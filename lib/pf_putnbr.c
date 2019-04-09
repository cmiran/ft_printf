/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 21:07:51 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/09 19:53:11 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Affiche l’entier n sur la sortie standard.
*/

#include "../inc/ft_printf.h"

void	pf_putnbr(long long nbr, size_t *fla)
{
/*	if (fla['.'] && !fla['F'] && nbr == 0)
		return ;*/
	if (nbr < 0)
		nbr = -nbr;
	if (nbr < 10)
	{
		ft_putchar(nbr + 48);
		fla['R']++;
	}
	else
	{
		pf_putnbr(nbr / 10, &*fla);
		pf_putnbr(nbr % 10, &*fla);
	}
}
