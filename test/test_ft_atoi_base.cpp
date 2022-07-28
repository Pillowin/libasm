#include "Test.hpp"
#include <iostream>

extern "C" int ft_atoi_base(char* str, char* base);

static bool test_42(void) {
	ltest_assert_eq(ft_atoi_base((char*)"42", (char*)"0123456789"), 42);
}

static bool test_plus_42(void) {
	ltest_assert_eq(ft_atoi_base((char*)"+42", (char*)"0123456789"), 42);
}

static bool test_minus_42(void) {
	ltest_assert_eq(ft_atoi_base((char*)"-42", (char*)"0123456789"), -42);
}

static bool test_double_minus_42(void) {
	ltest_assert_eq(ft_atoi_base((char*)"--42", (char*)"0123456789"), 42);
}

static bool test_triple_minus_42(void) {
	ltest_assert_eq(ft_atoi_base((char*)"---42", (char*)"0123456789"), -42);
}

static bool test_zero_42(void) {
	ltest_assert_eq(ft_atoi_base((char*)"042", (char*)"0123456789"), 42);
}

static bool test_whitespaces_42(void) {
	ltest_assert_eq(ft_atoi_base((char*)"\t\n\r\v\f 42", (char*)"0123456789"),
					42);
}

static bool test_42quebec(void) {
	ltest_assert_eq(ft_atoi_base((char*)"42quebec", (char*)"0123456789"), 42);
}

static bool test_subject(void) {
	ltest_assert_eq(
		ft_atoi_base((char*)"   ---+--+1234ab567", (char*)"0123456789"),
		-1234);
}

static bool test_hexa(void) {
	ltest_assert_eq(ft_atoi_base((char*)"FF", (char*)"0123456789ABCDEF"), 255);
}

static bool test_base_empty(void) {
	ltest_assert_eq(ft_atoi_base((char*)"42", (char*)""), 0);
}

static bool test_base_size_one(void) {
	ltest_assert_eq(ft_atoi_base((char*)"42", (char*)"1"), 0);
}

static bool test_base_duplicates(void) {
	ltest_assert_eq(ft_atoi_base((char*)"42", (char*)"01230456789"), 0);
}

static bool test_base_plus(void) {
	ltest_assert_eq(ft_atoi_base((char*)"42", (char*)"0123+456789"), 0);
}

static bool test_base_dash(void) {
	ltest_assert_eq(ft_atoi_base((char*)"42", (char*)"0123-456789"), 0);
}

static bool test_base_whitespace(void) {
	ltest_assert_eq(ft_atoi_base((char*)"42", (char*)"0123\t456789"), 0);
}

bool test_ft_atoi_base(void) {
	Test t("ft_atoi_base");

	t.registerTest("42", &test_42);
	t.registerTest("+42", &test_plus_42);
	t.registerTest("-42", &test_minus_42);
	t.registerTest("--42", &test_double_minus_42);
	t.registerTest("---42", &test_triple_minus_42);
	t.registerTest("042", &test_zero_42);
	t.registerTest("whitespaces 42", &test_whitespaces_42);
	t.registerTest("42quebec", &test_42quebec);
	t.registerTest("   ---+--+1234ab567", &test_subject);
	t.registerTest("hexa FF", &test_hexa);
	t.registerTest("base empty", &test_base_empty);
	t.registerTest("base size 1", &test_base_size_one);
	t.registerTest("base contains duplicates", &test_base_duplicates);
	t.registerTest("base contains \"+\"", &test_base_plus);
	t.registerTest("base contains \"-\"", &test_base_dash);
	t.registerTest("base contains whitespaces", &test_base_whitespace);
	return (t.run());
}
