/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 21:07:51 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/06 16:34:47 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Affiche l’entier n sur la sortie standard.
*/

#include "../inc/ft_printf.h"

void	pf_putnbr(ssize_t nbr, size_t *ret)
{
	if (nbr < 0)
		nbr = -nbr;
	if (nbr < 10)
	{
		ft_putchar(nbr + 48);
		(*ret)++;
	}
	else
	{
		pf_putnbr(nbr / 10, ret);
		pf_putnbr(nbr % 10, ret);
	}
}
