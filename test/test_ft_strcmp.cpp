#include "Test.hpp"
#include <iostream>
#include <string.h>
#include <string>

extern "C" int ft_strcmp(const char* s1, const char* s2);

static bool test_aaa_aaa(void) {
	std::string const s1("aaa");
	std::string const s2("aaa");
	ft_strcmp(s1.c_str(), s2.c_str());
	ltest_assert_eq(ft_strcmp(s1.c_str(), s2.c_str()),
					strcmp(s1.c_str(), s2.c_str()));
}

static bool test_aaa_bbb(void) {
	std::string const s1("aaa");
	std::string const s2("bbb");
	ft_strcmp(s1.c_str(), s2.c_str());
	ltest_assert_eq(ft_strcmp(s1.c_str(), s2.c_str()),
					strcmp(s1.c_str(), s2.c_str()));
}

static bool test_bbb_aaa(void) {
	std::string const s1("bbb");
	std::string const s2("aaa");
	ft_strcmp(s1.c_str(), s2.c_str());
	ltest_assert_eq(ft_strcmp(s1.c_str(), s2.c_str()),
					strcmp(s1.c_str(), s2.c_str()));
}

static bool test_a_aaa(void) {
	std::string const s1("a");
	std::string const s2("aaa");
	ft_strcmp(s1.c_str(), s2.c_str());
	ltest_assert_eq(ft_strcmp(s1.c_str(), s2.c_str()),
					strcmp(s1.c_str(), s2.c_str()));
}

static bool test_aaa_a(void) {
	std::string const s1("aaa");
	std::string const s2("a");
	ft_strcmp(s1.c_str(), s2.c_str());
	ltest_assert_eq(ft_strcmp(s1.c_str(), s2.c_str()),
					strcmp(s1.c_str(), s2.c_str()));
}

static bool test_aaa_empty(void) {
	std::string const s1("aaa");
	std::string const s2("");
	ft_strcmp(s1.c_str(), s2.c_str());
	ltest_assert_eq(ft_strcmp(s1.c_str(), s2.c_str()),
					strcmp(s1.c_str(), s2.c_str()));
}

static bool test_empty_aaa(void) {
	std::string const s1("");
	std::string const s2("aaa");
	ft_strcmp(s1.c_str(), s2.c_str());
	ltest_assert_eq(ft_strcmp(s1.c_str(), s2.c_str()),
					strcmp(s1.c_str(), s2.c_str()));
}

static bool test_empty_empty(void) {
	std::string const s1("");
	std::string const s2("");
	ft_strcmp(s1.c_str(), s2.c_str());
	ltest_assert_eq(ft_strcmp(s1.c_str(), s2.c_str()),
					strcmp(s1.c_str(), s2.c_str()));
}

bool test_ft_strcmp(void) {
	Test t("ft_strcmp");

	t.registerTest("aaa\taaa", &test_aaa_aaa);
	t.registerTest("aaa\tbbb", &test_aaa_bbb);
	t.registerTest("bbb\taaa", &test_bbb_aaa);
	t.registerTest("aaa\ta", &test_aaa_a);
	t.registerTest("a\taaa", &test_a_aaa);
	t.registerTest("aaa\t\"\"", &test_aaa_empty);
	t.registerTest("\"\"\taaa", &test_empty_aaa);
	t.registerTest("\"\"\t\"\"", &test_empty_empty);
	return (t.run());
}
