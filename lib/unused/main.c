#include "../inc/ft_printf.h"

int	ft_unbrlen(unsigned long long unbr)
{
	size_t		len;
	unsigned char	base;

	len = 1;
	base = 16;
	while (unbr /= base)
		len++;
	return (len);
}

int	main()
{
	int	nb = 123456789;

	printf("%x, %d\n", nb, ft_unbrlen(nb));
	return (0);
}
