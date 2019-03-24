#include "../inc/ft_printf.h"

int	main(void)
{
	ft_printf("Christopher Nolan\n");
	ft_printf("%%%%\n");
	
	printf("\n1\n");
	printf("lol : %-d Check Norris\n", -42);
	ft_printf("lol : %-d Check Norris\n", -42);
	
	printf("\n2\n");
	printf("%-10d Check\n", 42);
	ft_printf("%-10d Check\n", 42);	
	
	printf("\n3\n");
	printf("%-10d Check\n", -42);
	ft_printf("%-10d Check\n", -42);	

	printf("\n4\n");
	printf("%-.10d Check Norris\n", -42);
	ft_printf("%-.10d Check Norris\n\n", -42);
	
	printf("\n5\n");
	printf("%-10.5d Check Norris\n", -42);
	ft_printf("%-10.5d Check Norris\n\n", -42);
	
	printf("\n6\n");
	printf("%-+5.10d Check Norris\n", 42);
	ft_printf("%-+5.10d Check Norris\n\n", 42);

	printf("\n7\n");
	printf("% -10d Check\n", 42);
	ft_printf("% -10d Check\n", 42);

	printf("\n8\n");
	printf("% -d Check\n", -42);
	ft_printf("% -d Check\n", -42);

	printf("\n9\n");
	printf("% +-d Check\n", -42);
	ft_printf("% +-d Check\n", -42);

	printf("\n10\n");
	printf("%0-10d Check\n", -42);
	ft_printf("%0-10d Check\n", -42);
	
	printf("\n11\n");
	printf("%015d Check\n", -42);
	ft_printf("%015d Check\n", -42);
	
	printf("\n12\n");
	printf("%010.4d Check\n", -42);
	ft_printf("%010.4d Check\n", -42);
	
	printf("\n13\n");
	printf("%0 14d Check\n", +42);
	ft_printf("%0 14d Check\n", +42);
	return(0);
}
