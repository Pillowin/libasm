#include "Test.hpp"
#include <stdlib.h>

bool test_hello(void);

int main(void) {
	bool passed = true;

	if (!test_hello())
		passed &= false;
	return (passed ? EXIT_SUCCESS : EXIT_FAILURE);
}

