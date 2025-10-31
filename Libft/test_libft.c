/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhilo <bkhilo@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 00:00:00 by bkhilo            #+#    #+#             */
/*   Updated: 2025/10/31 09:20:58 by bkhilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"
#define YELLOW "\033[0;33m"

int g_tests_passed = 0;
int g_tests_failed = 0;

void print_test_header(const char *func_name)
{
	printf("\n" YELLOW "Testing %s:" RESET "\n", func_name);
}

void assert_int(const char *test_name, int expected, int actual)
{
	if (expected == actual)
	{
		printf(GREEN "  ✓ %s\n" RESET, test_name);
		g_tests_passed++;
	}
	else
	{
		printf(RED "  ✗ %s (expected: %d, got: %d)\n" RESET, test_name, expected, actual);
		g_tests_failed++;
	}
}

void assert_size_t(const char *test_name, size_t expected, size_t actual)
{
	if (expected == actual)
	{
		printf(GREEN "  ✓ %s\n" RESET, test_name);
		g_tests_passed++;
	}
	else
	{
		printf(RED "  ✗ %s (expected: %zu, got: %zu)\n" RESET, test_name, expected, actual);
		g_tests_failed++;
	}
}

void assert_str(const char *test_name, const char *expected, const char *actual)
{
	if ((expected == NULL && actual == NULL) ||
		(expected != NULL && actual != NULL && strcmp(expected, actual) == 0))
	{
		printf(GREEN "  ✓ %s\n" RESET, test_name);
		g_tests_passed++;
	}
	else
	{
		printf(RED "  ✗ %s (expected: %s, got: %s)\n" RESET,
			test_name, expected ? expected : "NULL", actual ? actual : "NULL");
		g_tests_failed++;
	}
}

void assert_ptr(const char *test_name, const void *expected, const void *actual)
{
	if (expected == actual)
	{
		printf(GREEN "  ✓ %s\n" RESET, test_name);
		g_tests_passed++;
	}
	else
	{
		printf(RED "  ✗ %s (expected: %p, got: %p)\n" RESET, test_name, expected, actual);
		g_tests_failed++;
	}
}

void assert_mem(const char *test_name, const void *expected, const void *actual, size_t n)
{
	if (memcmp(expected, actual, n) == 0)
	{
		printf(GREEN "  ✓ %s\n" RESET, test_name);
		g_tests_passed++;
	}
	else
	{
		printf(RED "  ✗ %s (memory differs)\n" RESET, test_name);
		g_tests_failed++;
	}
}

void test_isalpha(void)
{
	print_test_header("ft_isalpha");
	assert_int("isalpha('a')", isalpha('a'), ft_isalpha('a'));
	assert_int("isalpha('Z')", isalpha('Z'), ft_isalpha('Z'));
	assert_int("isalpha('0')", isalpha('0'), ft_isalpha('0'));
	assert_int("isalpha(' ')", isalpha(' '), ft_isalpha(' '));
	assert_int("isalpha('!')", isalpha('!'), ft_isalpha('!'));
	assert_int("isalpha(128)", isalpha(128), ft_isalpha(128));
	assert_int("isalpha(-1)", isalpha(-1), ft_isalpha(-1));
}

void test_isdigit(void)
{
	print_test_header("ft_isdigit");
	assert_int("isdigit('0')", isdigit('0'), ft_isdigit('0'));
	assert_int("isdigit('5')", isdigit('5'), ft_isdigit('5'));
	assert_int("isdigit('9')", isdigit('9'), ft_isdigit('9'));
	assert_int("isdigit('a')", isdigit('a'), ft_isdigit('a'));
	assert_int("isdigit(' ')", isdigit(' '), ft_isdigit(' '));
	assert_int("isdigit(-1)", isdigit(-1), ft_isdigit(-1));
}

void test_isalnum(void)
{
	print_test_header("ft_isalnum");
	assert_int("isalnum('a')", isalnum('a'), ft_isalnum('a'));
	assert_int("isalnum('Z')", isalnum('Z'), ft_isalnum('Z'));
	assert_int("isalnum('5')", isalnum('5'), ft_isalnum('5'));
	assert_int("isalnum(' ')", isalnum(' '), ft_isalnum(' '));
	assert_int("isalnum('!')", isalnum('!'), ft_isalnum('!'));
}

void test_isascii(void)
{
	print_test_header("ft_isascii");
	assert_int("isascii(0)", isascii(0), ft_isascii(0));
	assert_int("isascii('A')", isascii('A'), ft_isascii('A'));
	assert_int("isascii(127)", isascii(127), ft_isascii(127));
	assert_int("isascii(128)", isascii(128), ft_isascii(128));
	assert_int("isascii(-1)", isascii(-1), ft_isascii(-1));
}

void test_isprint(void)
{
	print_test_header("ft_isprint");
	assert_int("isprint(' ')", isprint(' '), ft_isprint(' '));
	assert_int("isprint('A')", isprint('A'), ft_isprint('A'));
	assert_int("isprint('~')", isprint('~'), ft_isprint('~'));
	assert_int("isprint(31)", isprint(31), ft_isprint(31));
	assert_int("isprint(127)", isprint(127), ft_isprint(127));
}

void test_strlen(void)
{
	print_test_header("ft_strlen");
	assert_size_t("strlen(\"\")", strlen(""), ft_strlen(""));
	assert_size_t("strlen(\"hello\")", strlen("hello"), ft_strlen("hello"));
	assert_size_t("strlen(\"42 Abu Dhabi\")", strlen("42 Abu Dhabi"), ft_strlen("42 Abu Dhabi"));
}

void test_memset(void)
{
	print_test_header("ft_memset");
	char buf1[50], buf2[50];

	memset(buf1, 'A', 10);
	ft_memset(buf2, 'A', 10);
	assert_mem("memset('A', 10)", buf1, buf2, 10);

	memset(buf1, 0, 20);
	ft_memset(buf2, 0, 20);
	assert_mem("memset(0, 20)", buf1, buf2, 20);
}

void test_bzero(void)
{
	print_test_header("ft_bzero");
	char buf1[50], buf2[50];

	memset(buf1, 'X', 50);
	memset(buf2, 'X', 50);
	bzero(buf1, 10);
	ft_bzero(buf2, 10);
	assert_mem("bzero(10)", buf1, buf2, 50);
}

void test_memcpy(void)
{
	print_test_header("ft_memcpy");
	char src[] = "Hello World";
	char dst1[50], dst2[50];

	memcpy(dst1, src, strlen(src) + 1);
	ft_memcpy(dst2, src, strlen(src) + 1);
	assert_mem("memcpy(\"Hello World\")", dst1, dst2, strlen(src) + 1);
}

void test_memmove(void)
{
	print_test_header("ft_memmove");
	char buf1[] = "Hello World";
	char buf2[] = "Hello World";

	memmove(buf1 + 2, buf1, 5);
	ft_memmove(buf2 + 2, buf2, 5);
	assert_mem("memmove overlapping forward", buf1, buf2, strlen(buf1) + 1);

	strcpy(buf1, "Hello World");
	strcpy(buf2, "Hello World");
	memmove(buf1, buf1 + 2, 5);
	ft_memmove(buf2, buf2 + 2, 5);
	assert_mem("memmove overlapping backward", buf1, buf2, strlen(buf1) + 1);
}

void test_strlcpy(void)
{
	print_test_header("ft_strlcpy");
	char dst1[20], dst2[20];
	size_t r1, r2;

	r1 = strlcpy(dst1, "Hello", 20);
	r2 = ft_strlcpy(dst2, "Hello", 20);
	assert_size_t("strlcpy return value", r1, r2);
	assert_str("strlcpy result", dst1, dst2);

	r1 = strlcpy(dst1, "Hello World", 5);
	r2 = ft_strlcpy(dst2, "Hello World", 5);
	assert_size_t("strlcpy truncated return", r1, r2);
	assert_str("strlcpy truncated result", dst1, dst2);
}

void test_strlcat(void)
{
	print_test_header("ft_strlcat");
	char dst1[20], dst2[20];
	size_t r1, r2;

	strcpy(dst1, "Hello");
	strcpy(dst2, "Hello");
	r1 = strlcat(dst1, " World", 20);
	r2 = ft_strlcat(dst2, " World", 20);
	assert_size_t("strlcat return value", r1, r2);
	assert_str("strlcat result", dst1, dst2);

	strcpy(dst1, "Hello");
	strcpy(dst2, "Hello");
	r1 = strlcat(dst1, " World", 8);
	r2 = ft_strlcat(dst2, " World", 8);
	assert_size_t("strlcat truncated return", r1, r2);
	assert_str("strlcat truncated result", dst1, dst2);
}

void test_toupper(void)
{
	print_test_header("ft_toupper");
	assert_int("toupper('a')", toupper('a'), ft_toupper('a'));
	assert_int("toupper('z')", toupper('z'), ft_toupper('z'));
	assert_int("toupper('A')", toupper('A'), ft_toupper('A'));
	assert_int("toupper('5')", toupper('5'), ft_toupper('5'));
	assert_int("toupper('!')", toupper('!'), ft_toupper('!'));
}

void test_tolower(void)
{
	print_test_header("ft_tolower");
	assert_int("tolower('A')", tolower('A'), ft_tolower('A'));
	assert_int("tolower('Z')", tolower('Z'), ft_tolower('Z'));
	assert_int("tolower('a')", tolower('a'), ft_tolower('a'));
	assert_int("tolower('5')", tolower('5'), ft_tolower('5'));
	assert_int("tolower('!')", tolower('!'), ft_tolower('!'));
}

void test_strchr(void)
{
	print_test_header("ft_strchr");
	char str[] = "Hello World";

	assert_ptr("strchr('H')", strchr(str, 'H'), ft_strchr(str, 'H'));
	assert_ptr("strchr('o')", strchr(str, 'o'), ft_strchr(str, 'o'));
	assert_ptr("strchr('d')", strchr(str, 'd'), ft_strchr(str, 'd'));
	assert_ptr("strchr('\\0')", strchr(str, '\0'), ft_strchr(str, '\0'));
	assert_ptr("strchr('x')", strchr(str, 'x'), ft_strchr(str, 'x'));
}

void test_strrchr(void)
{
	print_test_header("ft_strrchr");
	char str[] = "Hello World";

	assert_ptr("strrchr('H')", strrchr(str, 'H'), ft_strrchr(str, 'H'));
	assert_ptr("strrchr('o')", strrchr(str, 'o'), ft_strrchr(str, 'o'));
	assert_ptr("strrchr('d')", strrchr(str, 'd'), ft_strrchr(str, 'd'));
	assert_ptr("strrchr('\\0')", strrchr(str, '\0'), ft_strrchr(str, '\0'));
	assert_ptr("strrchr('x')", strrchr(str, 'x'), ft_strrchr(str, 'x'));
}

void test_strncmp(void)
{
	print_test_header("ft_strncmp");
	assert_int("strncmp equal", strncmp("hello", "hello", 5), ft_strncmp("hello", "hello", 5));
	assert_int("strncmp diff", strncmp("hello", "world", 5), ft_strncmp("hello", "world", 5));
	assert_int("strncmp n=0", strncmp("hello", "world", 0), ft_strncmp("hello", "world", 0));
	assert_int("strncmp partial", strncmp("hello", "hella", 3), ft_strncmp("hello", "hella", 3));

	int orig = strncmp("test\200", "test\0", 6);
	int mine = ft_strncmp("test\200", "test\0", 6);
	if ((orig > 0 && mine > 0) || (orig < 0 && mine < 0) || (orig == 0 && mine == 0))
	{
		printf(GREEN "  ✓ strncmp sign matches\n" RESET);
		g_tests_passed++;
	}
	else
	{
		printf(RED "  ✗ strncmp sign differs (orig: %d, mine: %d)\n" RESET, orig, mine);
		g_tests_failed++;
	}
}

void test_memchr(void)
{
	print_test_header("ft_memchr");
	char str[] = "Hello\0World";

	assert_ptr("memchr('H')", memchr(str, 'H', 11), ft_memchr(str, 'H', 11));
	assert_ptr("memchr('W')", memchr(str, 'W', 11), ft_memchr(str, 'W', 11));
	assert_ptr("memchr('\\0')", memchr(str, '\0', 11), ft_memchr(str, '\0', 11));
	assert_ptr("memchr('x')", memchr(str, 'x', 11), ft_memchr(str, 'x', 11));
}

void test_memcmp(void)
{
	print_test_header("ft_memcmp");
	assert_int("memcmp equal", memcmp("hello", "hello", 5), ft_memcmp("hello", "hello", 5));
	assert_int("memcmp diff", memcmp("hello", "world", 5), ft_memcmp("hello", "world", 5));
	assert_int("memcmp n=0", memcmp("hello", "world", 0), ft_memcmp("hello", "world", 0));

	char s1[] = "test\200";
	char s2[] = "test\0";
	int orig = memcmp(s1, s2, 6);
	int mine = ft_memcmp(s1, s2, 6);
	if ((orig > 0 && mine > 0) || (orig < 0 && mine < 0) || (orig == 0 && mine == 0))
	{
		printf(GREEN "  ✓ memcmp sign matches\n" RESET);
		g_tests_passed++;
	}
	else
	{
		printf(RED "  ✗ memcmp sign differs (orig: %d, mine: %d)\n" RESET, orig, mine);
		g_tests_failed++;
	}
}

void test_strnstr(void)
{
	print_test_header("ft_strnstr");
	char haystack[] = "Hello World";

	assert_ptr("strnstr(\"World\")", strnstr(haystack, "World", 20), ft_strnstr(haystack, "World", 20));
	assert_ptr("strnstr(\"Hello\")", strnstr(haystack, "Hello", 20), ft_strnstr(haystack, "Hello", 20));
	assert_ptr("strnstr(\"lo\")", strnstr(haystack, "lo", 20), ft_strnstr(haystack, "lo", 20));
	assert_ptr("strnstr empty needle", strnstr(haystack, "", 20), ft_strnstr(haystack, "", 20));
	assert_ptr("strnstr not found", strnstr(haystack, "42", 20), ft_strnstr(haystack, "42", 20));
	assert_ptr("strnstr len too short", strnstr(haystack, "World", 5), ft_strnstr(haystack, "World", 5));
}

void test_atoi(void)
{
	print_test_header("ft_atoi");
	assert_int("atoi(\"123\")", atoi("123"), ft_atoi("123"));
	assert_int("atoi(\"-456\")", atoi("-456"), ft_atoi("-456"));
	assert_int("atoi(\"  789\")", atoi("  789"), ft_atoi("  789"));
	assert_int("atoi(\"0\")", atoi("0"), ft_atoi("0"));
	assert_int("atoi(\"+42\")", atoi("+42"), ft_atoi("+42"));
	assert_int("atoi(\"  -123abc\")", atoi("  -123abc"), ft_atoi("  -123abc"));
	assert_int("atoi(\"2147483647\")", atoi("2147483647"), ft_atoi("2147483647"));
	assert_int("atoi(\"-2147483648\")", atoi("-2147483648"), ft_atoi("-2147483648"));
}

void test_calloc(void)
{
	print_test_header("ft_calloc");
	void *ptr1, *ptr2;

	// Test 1: Basic allocation and zero initialization
	ptr1 = calloc(10, sizeof(int));
	ptr2 = ft_calloc(10, sizeof(int));
	if (ptr1 && ptr2)
	{
		assert_mem("calloc zeros memory", ptr1, ptr2, 10 * sizeof(int));
		free(ptr1);
		free(ptr2);
	}
	else
	{
		printf(RED "  ✗ calloc basic allocation failed\n" RESET);
		g_tests_failed++;
	}

	// Test 2: calloc(0, 10) - count is 0
	ptr1 = calloc(0, 10);
	ptr2 = ft_calloc(0, 10);
	if ((ptr1 == NULL && ptr2 == NULL) || (ptr1 != NULL && ptr2 != NULL))
	{
		printf(GREEN "  ✓ calloc(0, 10) behavior matches\n" RESET);
		g_tests_passed++;
	}
	else
	{
		printf(RED "  ✗ calloc(0, 10) behavior differs\n" RESET);
		g_tests_failed++;
	}
	if (ptr1) free(ptr1);
	if (ptr2) free(ptr2);

	// Test 3: calloc(10, 0) - size is 0
	ptr1 = calloc(10, 0);
	ptr2 = ft_calloc(10, 0);
	if ((ptr1 == NULL && ptr2 == NULL) || (ptr1 != NULL && ptr2 != NULL))
	{
		printf(GREEN "  ✓ calloc(10, 0) behavior matches\n" RESET);
		g_tests_passed++;
	}
	else
	{
		printf(RED "  ✗ calloc(10, 0) behavior differs\n" RESET);
		g_tests_failed++;
	}
	if (ptr1) free(ptr1);
	if (ptr2) free(ptr2);

	// Test 4: calloc(0, 0) - both are 0
	ptr1 = calloc(0, 0);
	ptr2 = ft_calloc(0, 0);
	if ((ptr1 == NULL && ptr2 == NULL) || (ptr1 != NULL && ptr2 != NULL))
	{
		printf(GREEN "  ✓ calloc(0, 0) behavior matches\n" RESET);
		g_tests_passed++;
	}
	else
	{
		printf(RED "  ✗ calloc(0, 0) behavior differs\n" RESET);
		g_tests_failed++;
	}
	if (ptr1) free(ptr1);
	if (ptr2) free(ptr2);

	// Test 5: SIZE_MAX overflow test - should return NULL
	ptr1 = calloc(SIZE_MAX, 2);
	ptr2 = ft_calloc(SIZE_MAX, 2);
	if ((ptr1 == NULL && ptr2 == NULL) || (ptr1 != NULL && ptr2 != NULL))
	{
		printf(GREEN "  ✓ calloc(SIZE_MAX, 2) overflow handling matches\n" RESET);
		g_tests_passed++;
	}
	else
	{
		printf(RED "  ✗ calloc(SIZE_MAX, 2) overflow handling differs\n" RESET);
		g_tests_failed++;
	}
	if (ptr1) free(ptr1);
	if (ptr2) free(ptr2);

	// Test 6: Another overflow test
	ptr1 = calloc(SIZE_MAX / 2, 3);
	ptr2 = ft_calloc(SIZE_MAX / 2, 3);
	if ((ptr1 == NULL && ptr2 == NULL) || (ptr1 != NULL && ptr2 != NULL))
	{
		printf(GREEN "  ✓ calloc(SIZE_MAX/2, 3) overflow handling matches\n" RESET);
		g_tests_passed++;
	}
	else
	{
		printf(RED "  ✗ calloc(SIZE_MAX/2, 3) overflow handling differs\n" RESET);
		g_tests_failed++;
	}
	if (ptr1) free(ptr1);
	if (ptr2) free(ptr2);

	// Test 7: Large but valid allocation
	ptr1 = calloc(1000, sizeof(char));
	ptr2 = ft_calloc(1000, sizeof(char));
	if (ptr1 && ptr2)
	{
		assert_mem("calloc large allocation zeros memory", ptr1, ptr2, 1000);
		free(ptr1);
		free(ptr2);
	}
	else if (!ptr1 && !ptr2)
	{
		printf(GREEN "  ✓ calloc large allocation both failed (low memory)\n" RESET);
		g_tests_passed++;
	}
	else
	{
		printf(RED "  ✗ calloc large allocation behavior differs\n" RESET);
		g_tests_failed++;
		if (ptr1) free(ptr1);
		if (ptr2) free(ptr2);
	}
}

void test_strdup(void)
{
	print_test_header("ft_strdup");

	char *s1 = strdup("Hello World");
	char *s2 = ft_strdup("Hello World");

	if (s1 && s2)
	{
		assert_str("strdup(\"Hello World\")", s1, s2);
		free(s1);
		free(s2);
	}
	else
	{
		printf(RED "  ✗ strdup allocation failed\n" RESET);
		g_tests_failed++;
	}

	s1 = strdup("");
	s2 = ft_strdup("");
	if (s1 && s2)
	{
		assert_str("strdup(\"\")", s1, s2);
		free(s1);
		free(s2);
	}
}

void test_substr(void)
{
	print_test_header("ft_substr");
	char *result;

	// Test 1: Extract substring from middle
	result = ft_substr("Hello World", 6, 5);
	if (result)
	{
		assert_str("substr(\"Hello World\", 6, 5)", "World", result);
		free(result);
	}
	else
	{
		printf(RED "  ✗ substr allocation failed\n" RESET);
		g_tests_failed++;
	}

	// Test 2: Extract from beginning
	result = ft_substr("Hello World", 0, 5);
	if (result)
	{
		assert_str("substr(\"Hello World\", 0, 5)", "Hello", result);
		free(result);
	}
	else
	{
		printf(RED "  ✗ substr from beginning failed\n" RESET);
		g_tests_failed++;
	}

	// Test 3: Extract entire string
	result = ft_substr("42", 0, 2);
	if (result)
	{
		assert_str("substr(\"42\", 0, 2)", "42", result);
		free(result);
	}
	else
	{
		printf(RED "  ✗ substr entire string failed\n" RESET);
		g_tests_failed++;
	}

	// Test 4: Length longer than remaining string
	result = ft_substr("Hello", 2, 100);
	if (result)
	{
		assert_str("substr(\"Hello\", 2, 100)", "llo", result);
		free(result);
	}
	else
	{
		printf(RED "  ✗ substr length overflow failed\n" RESET);
		g_tests_failed++;
	}

	// Test 5: Start beyond string length (should return empty string)
	result = ft_substr("Hello", 10, 5);
	if (result)
	{
		assert_str("substr(\"Hello\", 10, 5)", "", result);
		free(result);
	}
	else
	{
		printf(RED "  ✗ substr start beyond length failed\n" RESET);
		g_tests_failed++;
	}

	// Test 6: Start at end of string
	result = ft_substr("Hello", 5, 5);
	if (result)
	{
		assert_str("substr(\"Hello\", 5, 5)", "", result);
		free(result);
	}
	else
	{
		printf(RED "  ✗ substr start at end failed\n" RESET);
		g_tests_failed++;
	}

	// Test 7: Extract with len = 0
	result = ft_substr("Hello", 2, 0);
	if (result)
	{
		assert_str("substr(\"Hello\", 2, 0)", "", result);
		free(result);
	}
	else
	{
		printf(RED "  ✗ substr len=0 failed\n" RESET);
		g_tests_failed++;
	}

	// Test 8: Extract from empty string
	result = ft_substr("", 0, 5);
	if (result)
	{
		assert_str("substr(\"\", 0, 5)", "", result);
		free(result);
	}
	else
	{
		printf(RED "  ✗ substr empty string failed\n" RESET);
		g_tests_failed++;
	}

	// Test 9: Extract single character
	result = ft_substr("Hello", 1, 1);
	if (result)
	{
		assert_str("substr(\"Hello\", 1, 1)", "e", result);
		free(result);
	}
	else
	{
		printf(RED "  ✗ substr single char failed\n" RESET);
		g_tests_failed++;
	}

	// Test 10: Extract last character
	result = ft_substr("Hello", 4, 1);
	if (result)
	{
		assert_str("substr(\"Hello\", 4, 1)", "o", result);
		free(result);
	}
	else
	{
		printf(RED "  ✗ substr last char failed\n" RESET);
		g_tests_failed++;
	}

	// Test 11: NULL input (should return NULL)
	result = ft_substr(NULL, 0, 5);
	if (result == NULL)
	{
		printf(GREEN "  ✓ substr(NULL, 0, 5) returns NULL\n" RESET);
		g_tests_passed++;
	}
	else
	{
		printf(RED "  ✗ substr(NULL, 0, 5) should return NULL\n" RESET);
		g_tests_failed++;
		free(result);
	}
}

int main(void)
{
	printf("\n======================================\n");
	printf("   LIBFT COMPREHENSIVE TEST SUITE\n");
	printf("======================================\n");

	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_strlen();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	test_strlcpy();
	test_strlcat();
	test_toupper();
	test_tolower();
	test_strchr();
	test_strrchr();
	test_strncmp();
	test_memchr();
	test_memcmp();
	test_strnstr();
	test_atoi();
	test_calloc();
	test_strdup();
	test_substr();

	printf("\n======================================\n");
	printf("   TEST RESULTS\n");
	printf("======================================\n");
	printf(GREEN "Passed: %d\n" RESET, g_tests_passed);
	printf(RED "Failed: %d\n" RESET, g_tests_failed);
	printf("Total:  %d\n", g_tests_passed + g_tests_failed);

	if (g_tests_failed == 0)
		printf(GREEN "\n🎉 All tests passed!\n" RESET);
	else
		printf(RED "\n❌ Some tests failed. Please review.\n" RESET);

	return (g_tests_failed == 0 ? 0 : 1);
}
