#include "Test.hpp"
#include <errno.h>
#include <fcntl.h>
#include <iostream>
#include <string>
#include <sys/errno.h>
#include <unistd.h>

#define BUF_SIZE 128

extern "C" ssize_t ft_read(int fildes, void* buf, size_t nbyte);

static int init_file(const char* content) {
	int fd = open("./tmp.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1) {
		std::cerr << "Error in test: " << strerror(errno) << std::endl;
		return (-1);
	}
	if (write(fd, content, strlen(content)) == -1) {
		std::cerr << "Error in test: " << strerror(errno) << std::endl;
		close(fd);
		return (-1);
	}
	if (lseek(fd, 0, SEEK_SET) == -1) {
		std::cerr << "Error in test: " << strerror(errno) << std::endl;
		close(fd);
		return (-1);
	}
	return (fd);
}

static bool test_hello_world(void) {
	const char* str = "Hello World!\n";
	int fd			= init_file(str);
	if (fd == -1)
		return (false);
	std::string buf(BUF_SIZE, '\0');
	ssize_t ret = ft_read(fd, &(*buf.begin()), BUF_SIZE);
	close(fd);
	if (ret == (ssize_t)strlen(str) && strcmp(str, &(*buf.begin())) == 0)
		return (true);
	return (false);
}

static bool test_alphabet(void) {
	const char* str = "abcdefghijklmnopqrstuvwxyz";
	int fd			= init_file(str);
	if (fd == -1)
		return (false);
	std::string buf(BUF_SIZE, '\0');
	ssize_t ret = ft_read(fd, &(*buf.begin()), BUF_SIZE);
	close(fd);
	if (ret == (ssize_t)strlen(str) && strcmp(str, &(*buf.begin())) == 0)
		return (true);
	return (false);
}

static bool test_non_printable(void) {
	const char* str = "\t\n\t";
	int fd			= init_file(str);
	if (fd == -1)
		return (false);
	std::string buf(BUF_SIZE, '\0');
	ssize_t ret = ft_read(fd, &(*buf.begin()), BUF_SIZE);
	close(fd);
	if (ret == (ssize_t)strlen(str) && strcmp(str, &(*buf.begin())) == 0)
		return (true);
	return (false);
}

static bool test_buf_size_char_file(void) {
	const char* str
		= "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	int fd = init_file(str);
	if (fd == -1)
		return (false);
	std::string buf(BUF_SIZE, '\0');
	ssize_t ret = ft_read(fd, &(*buf.begin()), BUF_SIZE);
	close(fd);
	if (ret == BUF_SIZE && strncmp(str, &(*buf.begin()), BUF_SIZE) == 0)
		return (true);
	return (false);
}

static bool test_2000_char_file(void) {
	const char* str
		= "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		  "aaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	int fd = init_file(str);
	if (fd == -1)
		return (false);
	std::string buf(BUF_SIZE, '\0');
	ssize_t ret = ft_read(fd, &(*buf.begin()), BUF_SIZE);
	close(fd);
	if (ret == BUF_SIZE && strncmp(str, &(*buf.begin()), BUF_SIZE) == 0)
		return (true);
	return (false);
}

static bool test_wrong_fd(void) {
	std::string buf(BUF_SIZE, '\0');
	ssize_t ret = ft_read(42, &(*buf.begin()), BUF_SIZE);
	if (ret == -1 && errno == EBADF) // Bad file descriptor
		return (true);
	return (false);
}

static bool test_wrong_size(void) {
	const char* str = "Hello World!\n";
	int fd			= init_file(str);
	if (fd == -1)
		return (false);
	std::string buf(BUF_SIZE, '\0');
	ssize_t ret = ft_read(fd, &(*buf.begin()), -1);
	close(fd);
	if (ret == -1 && errno == EINVAL) // Invalid argument
		return (true);
	return (false);
}

bool test_ft_read(void) {
	Test t("ft_read");

	t.registerTest("\"Hello World!\\n\"", &test_hello_world);
	t.registerTest("alphabet", &test_alphabet);
	t.registerTest("non printable char", &test_non_printable);
	t.registerTest("buf size char file", &test_buf_size_char_file);
	t.registerTest("2000 char file", &test_2000_char_file);
	t.registerTest("wrong fd", &test_wrong_fd);
	t.registerTest("wrong size", &test_wrong_size);
	return (t.run());
}
