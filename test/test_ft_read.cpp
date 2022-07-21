#include "Test.hpp"
#include <fcntl.h>
#include <iostream>
#include <string>
#include <sys/errno.h>
#include <unistd.h>

#define BUF_SIZE 128

extern "C" ssize_t ft_read(int fildes, void* buf, size_t nbyte);

static bool test_hello_world(void) {
	const char* str = "Hello World!\n";
	int fd			= open("./tmp.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1) {
		std::cerr << "Error in test: " << strerror(errno) << std::endl;
		return (false);
	}
	if (lseek(fd, 0, SEEK_SET) == -1) {
		std::cerr << "Error in test: " << strerror(errno) << std::endl;
		close(fd);
		return (false);
	}
	if (write(fd, str, strlen(str)) == -1) {
		std::cerr << "Error in test: " << strerror(errno) << std::endl;
		close(fd);
		return (false);
	}
	std::string buf(BUF_SIZE, '\0');
	ssize_t ret = read(fd, &(*buf.begin()), BUF_SIZE);
	close(fd);
	std::cerr << "ret = " << ret << std::endl;
	std::cerr << "buf = " << buf.c_str() << std::endl;
	std::cerr << "strcmp = " << strcmp(str, &(*buf.begin())) << std::endl;
	if (ret == 0 && strcmp(str, &(*buf.begin())) == 0)
		return (true);
	return (false);
}

bool test_ft_read(void) {
	Test t("ft_read");

	t.registerTest("\"Hello World!\\n\"", &test_hello_world);
	//	t.registerTest("wrong fd", &test_wrong_fd);
	//	t.registerTest("null str", &test_null_str);
	return (t.run());
}
