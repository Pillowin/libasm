#include "Test.hpp"
#include <iostream>
#include <string.h>

extern "C" char* ft_strcpy(char* dst, const char* src);

static bool test_hello_world(void) {
	std::string dst(128, '\0');
	std::string const src("Hello World!\n");
	ft_strcpy(&(*dst.begin()), &(*src.begin()));
	ltest_assert_n(strcmp(&(*dst.begin()), &(*src.begin())));
}

static bool test_ret_hello_world(void) {
	std::string dst(128, '\0');
	std::string const src("Hello World!\n");
	char* tmp = ft_strcpy(&(*dst.begin()), &(*src.begin()));
	ltest_assert_n(strcmp(tmp, &(*src.begin())));
}

static bool test_aaa(void) {
	std::string dst(128, '\0');
	std::string const src("aaa");
	ft_strcpy(&(*dst.begin()), &(*src.begin()));
	ltest_assert_n(strcmp(&(*dst.begin()), &(*src.begin())));
}

bool test_ft_strcpy(void) {
	Test t("ft_strcpy");

	t.registerTest("\"Hello World!\\n\"", &test_hello_world);
	t.registerTest("return value of \"Hello World!\\n\"",
				   &test_ret_hello_world);
	t.registerTest("aaa", &test_aaa);
	return (t.run());
}
