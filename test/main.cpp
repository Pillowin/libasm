#include "Test.hpp"
#include <stdlib.h>

bool test_ft_strlen(void);
bool test_ft_strcmp(void);
bool test_ft_strcpy(void);
bool test_ft_strdup(void);
bool test_ft_write(void);
bool test_ft_read(void);
bool test_ft_atoi_base(void);

int main(void) {
	bool passed = true;

	// if (!test_ft_strlen())
	//	passed &= false;
	// if (!test_ft_strcmp())
	//	passed &= false;
	// if (!test_ft_strcpy())
	//	passed &= false;
	// if (!test_ft_strdup())
	//	passed &= false;
	// if (!test_ft_write())
	//	passed &= false;
	// if (!test_ft_read())
	//	passed &= false;
	if (!test_ft_atoi_base())
		passed &= false;
	return (passed ? EXIT_SUCCESS : EXIT_FAILURE);
}

