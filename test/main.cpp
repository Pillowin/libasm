#include "Test.hpp"
#include <stdlib.h>

bool test_hello(void);
bool test_ft_write(void);

int main(void) {
	bool passed = true;

	if (!test_ft_write())
		passed &= false;
	return (passed ? EXIT_SUCCESS : EXIT_FAILURE);
}

