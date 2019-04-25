/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 21:07:51 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/25 19:38:12 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Affiche l’entier n sur la sortie standard.
*/

#include "../inc/ft_printf.h"

void	pf_putnbr(long long nbr, size_t *r)
{
	if (nbr < 0)
		nbr = -nbr;
	if (nbr < 10)
		pf_putchar(nbr + 48, r);
	else
	{
		pf_putnbr(nbr / 10, r);
		pf_putnbr(nbr % 10, r);
	}
}
