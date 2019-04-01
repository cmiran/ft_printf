/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:27:24 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/01 21:13:40 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	width(size_t *fla, ssize_t nbr, unsigned char len)
{
	ft_putnchar(' ', fla['W'] -\
			((len + fla['P']) > 32 ? len : fla['P']) -\
			(fla['#'] ? 1 : 0) -\
			((fla['+'] || fla[' ']) && nbr >= 0 ? 1 : 0) -\
			(nbr < 0 && fla['P'] > len ? 1 : 0));
}

void	precision(size_t *fla, ssize_t nbr, unsigned char len)
{
	if (fla['P'] + len <= 31)
		pf_putbin(fla, nbr, fla['P'] + len);
	else
		pf_putbin(fla, nbr, len);
}

void	sign_4bin(size_t *fla, ssize_t nbr)
{
	if (fla['+'] && !fla['0'])
		nbr < 0 ? write(1, "-", 1) : write(1, "+", 1);
	else if (fla[' '] && !fla['+'] && !fla['0'])
		nbr < 0 ? write(1, "1", 1) : write(1, "0", 1);
	else if (nbr < 0 && !fla['0'])
		write(1, "-", 1); 
	if ((fla['+'] || fla[' ']) && fla['#'] && !fla['0'])
		write(1, " ", 1);
}

void	other_4bin(size_t *fla, size_t nbr, unsigned char len)
{
	if (!fla['P'])
	{
		if (fla['W'])
			width(fla, nbr, len);
		sign_4bin(fla, nbr);
	}
	else if (fla['W'] > fla['P'])
	{	
		width(fla, nbr, len);
		sign_4bin(fla, nbr);
		precision(fla, nbr, len);
		return ;
	}
	pf_putbin(fla, nbr, len);
}

void	dash_4bin(size_t *fla, ssize_t nbr, unsigned char len)
{
	sign_4bin(fla, nbr);
	precision(fla, nbr, len);
	if (fla['W'] > fla['P'])
		width(fla, nbr, len);
}

void	binary(t_env *var, unsigned char b)
{
	unsigned char	len;

	if (b == 'b')
		if (!is_bdi(var->fla, &var->conv.nbr, var->ap, b))
			exit(EXIT_FAILURE);
	printf("nbr : %ld\n", var->conv.nbr);
	len = pf_nbrlen(var->conv.nbr, 'b');
	printf("len : %d\n", len);
	if (var->fla['-'])
		dash_4bin(var->fla, var->conv.nbr, len);
	else
		other_4bin(var->fla, var->conv.nbr, len);
}
