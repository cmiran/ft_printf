/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:45:53 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/05 22:40:33 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	pf_putdbl(size_t *fla, long double dnbr, size_t *ret)
{
	size_t	len;

	pf_putnbr(dnbr, ret);
	write(1, ".", 1);
	(*ret)++;
	len = fla['P'];
	while (len--)
	{
		dnbr = (dnbr - (long)dnbr) * 10; 
		fla['P'] > 16 ? ft_putchar(dnbr + 1 + '0') : ft_putchar(dnbr + '0');
		(*ret)++;
	}
}

void		sign(size_t *fla, double long dnbr, size_t *ret)
{
	if (dnbr < 0)
	{
		write(1, "-", 1);
		(*ret)++;
	}
	else if (fla['+'])
	{
		dnbr < 0 ? write(1, "-", 1) : write(1, "+", 1);
		(*ret)++;
	}
	else if (fla[' '] && !fla['+'])
	{
		dnbr < 0 ? write(1, "-", 1) : write(1, " ", 1);
		(*ret)++;
	}
}

void	other_4dbl(size_t *fla, long double dnbr, unsigned char len, size_t *ret)
{
	if (!fla['P'])
	{
		if (fla['0'])
			sign(fla, dnbr, ret);
		if (fla['W'] > len)
			pf_putnchar((fla['0'] ? '0' : ' '), fla['W'] - len -\
				((fla['+'] || fla[' ']) && dnbr >= 0 ? 1 : 0) -\
				(fla['#'] && (dnbr - (long)dnbr) > 0 ? 1 : 0), ret);
		if (!fla['0'])
			sign(fla, dnbr, ret);
	}
	else
	{
		if (fla['W'] > fla['P'] && fla['W'] > len)
			pf_putnchar(' ', fla['W'] - len - fla['P'] -\
				((fla['+'] || fla[' ']) && dnbr >= 0 ? 1 : 0) -\
				(dnbr < 0 ? 1 : 0), ret);
		sign(fla, dnbr, ret);
	}
	pf_putdbl(fla, dnbr, ret);
}

void	dash_4dbl(size_t *fla, ssize_t nbr, unsigned char len, size_t *ret)
{
	if (fla['P'] > len && fla['P'] + len <= 32)
 		pf_putbin(fla, nbr, fla['P'], ret);
	else
		pf_putbin(fla, nbr, len, ret);
	if (fla['W'] > fla['P'] + len && !fla['#'])
		fla['P'] + len < 32 ? pf_putnchar(' ', fla['W'] - len, ret) :\
			pf_putnchar(' ', fla['W'] + fla['P'], ret);
}

void	floats(t_env *var, unsigned char b)
{
	unsigned char	len;

	if (b == 'f')
		if (!is_f(var->fla['L'], &var->conv.dnbr, var->ap))
			exit(EXIT_FAILURE);
	len = pf_nbrlen(var->conv.dnbr, 'f');
	pf_putdbl(var->fla, var->conv.dnbr, &var->ret);
}
