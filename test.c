#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc)
		;

	printf("printf(%%d)\n");
	printf("%d\n\n", atoi(argv[1]));
	
	printf("printf(%%+d)\n");
	printf("%+d\n\n", atoi(argv[1]));
	
	printf("printf(%% d)\n");
	printf("% d\n\n", atoi(argv[1]));

	printf("printf(%%-10d)\n");
	printf("%-10dc\n\n", atoi(argv[1]));

	printf("printf(%%-+20d)\n");
	printf("%-+20dc\n\n", atoi(argv[1]));
	
	printf("printf(%%#d)\n");
	printf("%#d\n\n", atoi(argv[1]));
	
	printf("printf(%%012d)\n");
	printf("%012d\n\n", atoi(argv[1]));

	printf("printf(%%12d)\n");
	printf("%12d\n\n", atoi(argv[1]));
	return (0);
}
