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
	printf("%0 14d Check\n", -42);
	ft_printf("%0 14d Check\n", -42);
	
	printf("\n14\n");
	printf("%0 d Check\n", -42);
	ft_printf("%0 d Check\n", -42);

	printf("\n15\n");
	printf("%0 +-14d Check\n", -42);
	ft_printf("%0 +-14d Check\n", -42);
	
	printf("\n16\n");
	printf("%0 +17.89d Check\n", -42);
	ft_printf("%0 +17.89d Check\n", -42);

	printf("\n17\n");
	printf("%- +17.89d Check\n", +42);
	ft_printf("%- +17.89d Check\n", +42);

	printf("\n18\n");
	printf("%- +89.17d Check\n", -42);
	ft_printf("%- +89.17d Check\n", -42);

	printf("\n19\n");
	printf("%0 +89.17d Check\n", -42);
	ft_printf("%0 +89.17d Check\n", -42);

	printf("\n20\n");
	printf("%+d Check\n", 42);
	ft_printf("%+d Check\n", 42);

	printf("\n21\n");
	printf("%u Check\n", 42);
	ft_printf("%u Check\n", 42);

	printf("\n22\n");
	printf("%16u Check\n", 42);
	ft_printf("%16u Check\n", 42);

	printf("\n23\n");
	printf("%.16i Check\n", 42);
	ft_printf("%.16i Check\n", 42);

	printf("\n24\n");
	printf("%5.16d Check\n", -42);
	ft_printf("%5.16d Check\n", -42);

	printf("\n25\n");
	printf("%34.16u Check\n", 42);
	ft_printf("%34.16u Check\n", 42);

	printf("\n26\n");
	printf("%34.16d Check\n", -42);
	ft_printf("%34.16d Check\n", -42);



	printf("\n30\n");
	printf("%hhd Check\n", (char)'c');
	ft_printf("%hhd Check\n", (char)'c');
	return(0);
}
