#include "Test.hpp"
#include <unistd.h>
#include <string>

extern "C" ssize_t ft_write(int fildes, const void *buf, size_t nbyte);

static bool test_hello_world(void)
{
	std::string const str("Hello World!\n");
	ssize_t ret = write(STDOUT_FILENO, str.c_str(), str.length()); // TODO: ft_write
	ltest_assert_eq(ret, 13);
}

bool test_ft_write(void) {
	Test t("ft_write");

	t.registerTest("stdout \"Hello World!\\n\"", &test_hello_world, "Hello World!\n");
	return (t.run());
}
