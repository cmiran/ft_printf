/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:56:28 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/30 14:45:06 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://gitgud.io/varnaud/libft/blob/586dd7b0d4f170ea438f2db0d717664801fc9b04/ft_putnbr_base.c

#include "../inc/ft_printf.h"

unsigned char	get_base(char c)
{
	unsigned char	base;

	if (c == 'o')
		base = 8;
	else if (c == 'x' || c == 'X')
		base = 16;
	else
		base = 10;
	return (base);
}

void	pf_putnbr_base(size_t nbr, char c)
{
	unsigned char	base;

	base = get_base(c);
	if (nbr < base)
		ft_putchar(pf_itoc(base, c));
	else
	{
		pf_putnbr_base(nbr / base, c);
		pf_putnbr_base(nbr % base, c);
//		ft_putchar(pf_itoc(nbr % base, c));
	}
}

