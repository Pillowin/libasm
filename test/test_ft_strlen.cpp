#include "Test.hpp"
#include <iostream>
#include <string>

extern "C" size_t ft_strlen(const char* s);

static bool test_hello_world(void) {
	std::string const str("Hello World!\n");
	size_t ret = ft_strlen(str.c_str());
	ltest_assert_eq(ret, 13);
}

static bool test_empty(void) {
	std::string const str("");
	size_t ret = ft_strlen(str.c_str());
	ltest_assert_eq(ret, 0);
}

bool test_ft_strlen(void) {
	Test t("ft_strlen");

	t.registerTest("\"Hello World!\\n\"", &test_hello_world);
	t.registerTest("empty string", &test_empty);
	return (t.run());
}
