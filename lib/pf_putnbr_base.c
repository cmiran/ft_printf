/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:59:11 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/26 20:51:23 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_pow(int nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

unsigned char	get_base(size_t *fla)
{
	unsigned short	base;

	if (fla['o'])
		base = 8;
	else if (fla['x'] || fla['X'])
		base = 16;
	else
		base = 10;
	return (base);
}

void	pf_putnbr_base(size_t n, size_t *fla)
{
	unsigned char	base;
	int		i;
	char		*nbr;

	base = get_base(fla);
	i = 1;
	while ((size_t)ft_pow(base, i) - 1 < n)
		i++;
	if (!(nbr = (char*)malloc(sizeof(nbr) * i)))
		exit(EXIT_FAILURE);
	nbr[i] = '\0';
	while (i--)
	{
		nbr[i] = (n % base) + (n % base > 9 ? 'A' - 10 : '0');
		n = n / base;
	}
	write(1, nbr, sizeof(nbr));
}
