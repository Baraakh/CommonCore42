import sys
import importlib


def main():
    print("LOADING STATUS: Loading programs...")
    print("Checking dependencies:")

    required_packages = ["pandas", "numpy", "matplotlib"]
    optional_packages = ["requests"]

    loaded_modules = {}
    missing = False

    for pkg in required_packages:
        try:
            module = importlib.import_module(pkg)
            version = getattr(module, "__version__", "unknown")
            print(f"[OK] {pkg} ({version}) - Ready")
            loaded_modules[pkg] = module
        except ImportError:
            print(f"[MISSING] {pkg} - Not installed")
            missing = True

    for pkg in optional_packages:
        try:
            module = importlib.import_module(pkg)
            version = getattr(module, "__version__", "unknown")
            print(f"[OK] {pkg} ({version}) - Network access ready")
        except ImportError:
            pass

    if missing:
        print("\nERROR: Missing required dependencies.")
        print("\nInstall using pip:")
        print("pip install -r requirements.txt")

        print("\nOr using Poetry:")
        print("poetry install")

        sys.exit(1)

    np = loaded_modules["numpy"]
    pd = loaded_modules["pandas"]
    plt = importlib.import_module("matplotlib.pyplot")

    print("\nAnalyzing Matrix data...")

    data = np.random.normal(loc=0, scale=1, size=1000)

    print("Processing 1000 data points...")

    df = pd.DataFrame(data, columns=["signal"])
    df["smoothed"] = df["signal"].rolling(window=20).mean()

    print("Generating visualization...")

    plt.figure(figsize=(10, 5))
    plt.plot(df["signal"], alpha=0.4, label="Raw Signal")
    plt.plot(df["smoothed"], label="Smoothed Signal", linewidth=2)
    plt.title("Matrix Signal Analysis")
    plt.legend()

    output_file = "matrix_analysis.png"
    plt.savefig(output_file)

    print("Analysis complete!")
    print(f"Results saved to: {output_file}")


if __name__ == "__main__":
    main()
