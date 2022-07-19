#include "Test.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <sys/errno.h>
#include <unistd.h>

extern "C" ssize_t ft_write(int fildes, const void* buf, size_t nbyte);

static bool test_hello_world(void) {
	std::string const str("Hello World!\n");
	ssize_t ret = ft_write(STDOUT_FILENO, str.c_str(), str.length());
	ltest_assert_eq(ret, 13);
}

static bool test_dlrow_olleh(void) {
	std::string const str("!dlroW olleH\n");
	ssize_t ret = ft_write(STDOUT_FILENO, str.c_str(), str.length());
	ltest_assert_eq(ret, 13);
}

static bool test_len_too_long(void) {
	std::string const str("Hello World!\n");
	ssize_t ret = ft_write(STDOUT_FILENO, str.c_str(), 42);
	ltest_assert_eq(ret, 42);
}

static bool test_wrong_fd(void) {
	std::string const str("Hello World!\n");
	ssize_t ret = ft_write(42, str.c_str(), str.length());
	if (errno != EBADF) // Bad file descriptor
		return (false);
	ltest_assert_eq(ret, -1);
}

static bool test_null_str(void) {
	ssize_t ret = ft_write(STDOUT_FILENO, NULL, 1);
	if (errno != EFAULT) // Bad address
		return (false);
	ltest_assert_eq(ret, -1);
}

bool test_ft_write(void) {
	Test t("ft_write");

	t.registerTest("stdout \"Hello World!\\n\"", &test_hello_world);
	t.registerTest("stdout \"!dlroW olleH\\n\"",
				   &test_dlrow_olleh,
				   "!dlroW olleH\n");
	// TODO: test errno
	t.registerTest("len too long", &test_len_too_long);
	t.registerTest("wrong fd", &test_wrong_fd);
	t.registerTest("null str", &test_null_str);
	return (t.run());
}
