#include <stdio.h>

int	main()
{
	char a = 'A';
	char b = 'B';
	size_t i = 0;
	size_t j = 0;

	i = (a == 'A') & (b == 'A');
	j = (a == 'A') & (b == 'B');

	printf("i = %lu\nj = %lu\n", i, j);
	return (0);
}
