/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:56:28 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/31 15:11:59 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://gitgud.io/varnaud/libft/blob/586dd7b0d4f170ea438f2db0d717664801fc9b04/ft_putnbr_base.c

#include "../inc/ft_printf.h"

unsigned char	itoc(size_t i, char b)
{
	if (i <= 9)
		return (i + '0');
	if (i >= 10 && i <= 36)
	{
		if (ft_isupper(b))
			return (i + 'A' - 10);
		return (i + 'a' - 10);
	}
	return (0);
}

unsigned int	hash(size_t unbr, char b, size_t *fla)
{
	if (b == 'o')
		ft_putnchar('0', 1 - (fla['P'] > pf_nbrlen(unbr, b) ? 1 : 0) -\
				(unbr > 0 ? 0 : 1));
	return (0);
}

void	pf_putnbr_base(size_t unbr, char b, size_t *fla)
{
	unsigned char	base;

	base = get_base(b);
	if (fla['#'])
		fla['#'] = hash(unbr, b, fla);
	if (unbr < base)
		ft_putchar(itoc(unbr % base, b));
	else
	{
		pf_putnbr_base(unbr / base, b, fla);
		pf_putnbr_base(unbr % base, b, fla);
	}
}
