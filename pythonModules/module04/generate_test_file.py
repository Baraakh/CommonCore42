"""
generate_test_file.py — Generate a large test file for ft_ancient_text.py

Usage:
    python generate_test_file.py [strategy]

Strategies:
    sparse   — instant, uses no real disk space (default on Linux/macOS)
    fill     — writes real data, tests actual read performance
    text     — writes real human-readable text content
"""

import io
import os
import sys
import time

TARGET_SIZE = 10 * 1024 * 1024 * 1024  # 10 GB
OUTPUT_FILE = "test_10gb.txt"
CHUNK_SIZE = io.DEFAULT_BUFFER_SIZE  # match your reader's chunk size


# ── Strategy 1: Sparse file ─────────────────────────
# ──────────────────────────
# Fastest possible — takes milliseconds.
# The OS allocates no real disk blocks; reads return null bytes.
# Use this to test that your code handles large files without crashing.
def generate_sparse(path: str, size: int) -> None:
    print(f"[sparse] Creating {size / 1e9:.1f} GB sparse file → {path}")
    with open(path, "wb") as f:
        f.seek(size - 1)  # jump to the last byte
        f.write(b"\x00")  # write one byte to actually create the file
    print("[sparse] Done — file created instantly, real disk usage: ~0 bytes")


# ── Strategy 2: Fill with repetitive bytes ────────────────
# ────────────────────
# Writes actual data in large chunks — tests real read throughput.
# Fast because the chunk is pre-allocated and reused every iteration.
def generate_fill(path: str, size: int) -> None:
    chunk = b"x" * CHUNK_SIZE
    written = 0
    start_time = time.monotonic()

    print(
        f"[fill] Writing {size / 1e9:.1f} GB to {path} in {CHUNK_SIZE // 1024}\
              KB chunks"
    )

    with open(path, "wb") as f:
        while written < size:
            remaining = size - written
            data = chunk if remaining >= CHUNK_SIZE else b"x" * remaining
            f.write(data)
            written += len(data)
            _print_progress(written, size, start_time)

    print(f"\n[fill] Done in {time.monotonic() - start_time:.1f}s")


# ── Strategy 3: Readable text content ────────────────────────────────────────
# Writes real UTF-8 text — best for testing your text-mode reader.
# Tests encoding handling, newlines, and chunk boundary behaviour.
def generate_text(path: str, size: int) -> None:
    line = ("The quick brown fox jumps over the lazy dog. " * 10).strip() + "\n"
    line_bytes = line.encode("utf-8")
    written = 0
    line_num = 0
    start_time = time.monotonic()

    # Pre-build a large block (~128KB) to reduce Python loop overhead
    lines_per_block = max(1, CHUNK_SIZE // len(line_bytes))
    block = (line * lines_per_block).encode("utf-8")
    block_size = len(block)

    print(f"[text] Writing {size / 1e9:.1f} GB of UTF-8 text to {path}")

    with open(path, "wb") as f:
        while written < size:
            remaining = size - written
            if remaining >= block_size:
                f.write(block)
                written += block_size
                line_num += lines_per_block
            else:
                # write remaining bytes — may cut a line mid-way, that's fine
                f.write(block[:remaining])
                written += remaining

            _print_progress(written, size, start_time)

    print(
        f"\n[text] Done in {time.monotonic() - start_time:.1f}s — {line_num:,}\
              lines written"
    )


# ── Progress bar ─────────────────────────────
# ─────────────────────────────────
def _print_progress(written: int, total: int, start: float) -> None:
    pct = written / total * 100
    elapsed = time.monotonic() - start
    mb_done = written / 1024 / 1024
    speed = mb_done / elapsed if elapsed > 0 else 0
    eta = (total - written) / (written / elapsed) if written > 0 else 0
    bar = "█" * int(pct // 2) + "░" * (50 - int(pct // 2))
    print(
        f"\r  [{bar}] {pct:5.1f}%  "
        f"{mb_done / 1024:.2f} GB  "
        f"{speed:.0f} MB/s  "
        f"ETA {eta:.0f}s   ",
        end="",
        flush=True,
    )


# ── Entry point ───────────────────────────────
# ────────────────────────────────
def main() -> None:
    strategy = sys.argv[1] if len(sys.argv) > 1 else "sparse"

    # Check available disk space first (skip for sparse)
    if strategy != "sparse":
        stat = os.statvfs(".")
        free = stat.f_bavail * stat.f_frsize
        if free < TARGET_SIZE:
            print(
                f"Error: not enough disk space.\n"
                f"  Required : {TARGET_SIZE / 1e9:.1f} GB\n"
                f"  Available: {free / 1e9:.1f} GB",
                file=sys.stderr,
            )
            sys.exit(1)

    generators = {
        "sparse": generate_sparse,
        "fill": generate_fill,
        "text": generate_text,
    }

    if strategy not in generators:
        print(
            f"Unknown strategy '{strategy}'. Choose: sparse, fill, text",
            file=sys.stderr,
        )
        sys.exit(1)

    generators[strategy](OUTPUT_FILE, TARGET_SIZE)

    actual_size = os.path.getsize(OUTPUT_FILE)
    print(f"\nFile      : {OUTPUT_FILE}")
    print(f"Size      : {actual_size / 1e9:.3f} GB ({actual_size:,} bytes)")
    print(f"Strategy  : {strategy}")
    print(f"\nNow run   : python ft_ancient_text.py {OUTPUT_FILE}")


if __name__ == "__main__":
    main()
