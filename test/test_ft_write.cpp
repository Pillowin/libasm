#include "Test.hpp"

extern "C" ssize_t write(int fildes, const void *buf, size_t nbyte);

static bool test_true(void)
{
	return (true);
}

bool test_ft_write(void) {
	Test t("ft_write");

	t.registerTest("true", &test_true);
	return (t.run());
}
