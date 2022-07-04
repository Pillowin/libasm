#include "Test.hpp"

extern "C" int64_t maxofthree(int64_t x, int64_t y, int64_t z);

static bool test_basic(void)
{
	maxofthree(1, 2, 42);
	return (true);
}

bool test_hello(void) {
	Test t("Hello");

	t.registerTest("Basic test", &test_basic);
	return (t.run());
}
