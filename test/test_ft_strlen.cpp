#include "Test.hpp"
#include <string>
#include <iostream>

extern "C" size_t ft_strlen(const char *s);

static bool test_hello_world(void)
{
	std::string const str("Hello World!\n");
	size_t ret = ft_strlen(str.c_str());
	std::cerr << "ret is " << ret << std::endl;
	ltest_assert_eq(ret, 13);
}

bool test_ft_strlen(void) {
	Test t("ft_strlen");

	t.registerTest("\"Hello World!\\n\"", &test_hello_world);
	return (t.run());
}
