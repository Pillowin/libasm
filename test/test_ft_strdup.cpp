#include "Test.hpp"
#include <iostream>
#include <stdio.h>
#include <string.h>

extern "C" char* ft_strdup(const char* s1);

static bool test_hello_world(void) {
	const char* s1 = "Hello World!\n";
	char* ret	   = ft_strdup(s1);
	if (strcmp(s1, ret) == 0) {
		free(ret);
		return (true);
	} else {
		free(ret);
		return (false);
	}
}

static bool test_empty(void) {
	const char* s1 = "";
	char* ret	   = ft_strdup(s1);
	if (strcmp(s1, ret) == 0) {
		free(ret);
		return (true);
	} else {
		free(ret);
		return (false);
	}
}

static bool test_rewrite(void) {
	const char* s1 = "a";
	char* ret	   = ft_strdup(s1);
	ret[0]		   = 'b';
	if (strcmp("b", ret) == 0) {
		free(ret);
		return (true);
	} else {
		free(ret);
		return (false);
	}
}

bool test_ft_strdup(void) {
	Test t("ft_strdup");

	t.registerTest("\"Hello World!\\n\"", &test_hello_world);
	t.registerTest("empty string", &test_empty);
	t.registerTest("rewrite in ret", &test_rewrite);
	return (t.run());
}
