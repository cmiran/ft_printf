/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:27:24 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/02 02:46:31 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	width(size_t *fla, ssize_t nbr, unsigned char len)
{
	ft_putnchar(' ', fla['W'] -\
			((len + fla['P']) > 32 ? len : fla['P']) -\
			(fla['#'] ? 1 : 0) -\
			((fla['+'] || fla[' ']) && nbr >= 0 ? 1 : 0));/* -\
			(nbr < 0 && fla['P'] > len ? 1 : 0));*/
}

void	other_4bin(size_t *fla, ssize_t nbr, unsigned char len)
{
	if (!fla['P'])
	{
		if (fla['W'])
			width(fla, nbr, fla['W'] - len);
	}
	else if (fla['P'] > len && fla['P'] + len < 32)
		pf_putbin(fla, nbr, fla['P']);
	else
	{
		pf_putbin(fla, nbr, len);
		if (fla['W'] > fla['P'] + len)
			fla['P'] + len < 32 ? ft_putnchar(' ', fla['W'] - fla['P'] - len) :\
				ft_putnchar(' ', fla['W'] - len);
		return ;
	}
	pf_putbin(fla, nbr, len);
}

void	dash_4bin(size_t *fla, ssize_t nbr, unsigned char len)
{
	if (fla['P'] > len)
		pf_putbin(fla, nbr, fla['P']);
	else
		pf_putbin(fla, nbr, len);
	if (fla['W'] > fla['P'] + len)
		fla['P'] + len < 32 ? ft_putnchar(' ', fla['W'] - fla['P'] - len) :\
			ft_putnchar(' ', fla['W'] - len);
}

void	binary(t_env *var, unsigned char b)
{
	unsigned char	len;

	if (b == 'b')
		if (!is_bdi(var->fla, &var->conv.nbr, var->ap))
			exit(EXIT_FAILURE);
	len = pf_nbrlen(var->conv.nbr, 'b');
	if (var->conv.nbr < 0)
		len -= 1;
	if (var->fla['-'])
		dash_4bin(var->fla, var->conv.nbr, len);
	else
		other_4bin(var->fla, var->conv.nbr, len);
}
