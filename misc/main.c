#include "../inc/ft_printf.h"
#include <stdio.h>

int	main(void)
{
//	ft_printf("Christopher Nolan\n");
	printf("%d Check Norris\n", 42);

	printf("%-d Check Norris\n", 42);

	printf("%-1d Check Norris\n", 42);
	
	printf("%-05d Check Norris\n", 42);
	
	printf("%- d Check Norris\n", 42);
	
	printf("%- d Check Norris\n", -42);

	printf("%- 5d Check Norris\n", -42);

	printf("%-+d Check Norris\n", 42);

	printf("%-5.5d Check Norris\n", 42);

	printf("%-5.d Check Norris\n", 42);

	printf("%0d Check Norras\n", 42);

	return(0);
}
