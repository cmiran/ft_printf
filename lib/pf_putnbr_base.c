/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:56:28 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/30 15:47:28 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://gitgud.io/varnaud/libft/blob/586dd7b0d4f170ea438f2db0d717664801fc9b04/ft_putnbr_base.c

#include "../inc/ft_printf.h"

unsigned char	itoc(size_t i, char c)
{
	if (i <= 9)
		return (i + '0');
	if (i >= 10 && i <= 36)
	{
		if (ft_isupper(c))
			return (i + 'A' - 10);
		return (i + 'a' - 10);
	}
	return (0);
}

void	pf_putnbr_base(size_t nbr, char c)
{
	unsigned char	base;

	base = get_base(c);
	if (nbr < base)
		ft_putchar(itoc(nbr % base, c));
	else
	{
		pf_putnbr_base(nbr / base, c);
		pf_putnbr_base(nbr % base, c);
	}
}
