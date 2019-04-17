/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:56:28 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/17 17:34:58 by cmiran           ###   ########.fr       */
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

void	pf_putnbr_base(unsigned long long unbr, char b, size_t *fla, size_t *r)
{
	unsigned char	base;

	base = get_base(b);
	if (fla['#'] && b == 'o')
		fla['#'] = hash(&*fla, unbr, b, r);
	if (unbr < base)
	{
		ft_putchar(itoc(unbr % base, b));
		++*r;
	}
	else
	{
		pf_putnbr_base(unbr / base, b, &*fla, r);
		pf_putnbr_base(unbr % base, b, &*fla, r);
	}
}
