/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:45:53 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/20 21:23:09 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	pf_putdbl(size_t *fla, long double dnbr, size_t *r)
{
	size_t	i;

	if (fla['.'] && !fla['P'] && (dnbr - (long)dnbr) * 10 > 5.)
		pf_putnbr(dnbr < 0 ? dnbr - 1. : dnbr + 1., r);
	else
		pf_putnbr(dnbr, r);
	if (fla['#'] || fla['P'])
	{
		write(1, ".", 1);
		++*r;
	}
	i = 0;
	while (i++ < fla['P'])
	{
		dnbr = (dnbr - (long)dnbr) * 10.;
		if (fla['P'] + fla['N'] < (dnbr < .0 || fla['+'] || fla[' '] ? 19 : 18)\
				&& (dnbr - (int)dnbr) * 10 == 9.)
/*
**					Le probleme est la ^^^^^ (== 9. || >= 9.)
*/ 
			(int)dnbr == 9 ? pf_putnbr(dnbr - 9., r) :\
				   pf_putnbr(dnbr + 1., r);
		else if (i == fla['P'] && (dnbr - (int)dnbr) * 10 > 5.)
			(int)dnbr == 9 ? pf_putnbr(dnbr - 9., r) :\
				   pf_putnbr(dnbr + 1., r);
		else
			pf_putnbr(dnbr, r);
	}
}

void	sign_4dbl(size_t *fla, long double dnbr, size_t *r)
{
	if (!(1 / dnbr > 0))
	{
		write(1, "-", 1);
		++*r;
	}
	else if (fla['+'])
	{
		!(1 / dnbr > 0) ? write(1, "-", 1) : write(1, "+", 1);
		++*r;
	}
	else if (fla[' '] && !fla['+'])
	{
		!(1 / dnbr > 0) ? write(1, "-", 1) : write(1, " ", 1);
		++*r;
	}
}

void	other_4dbl(size_t *fla, long double dnbr, size_t *r)
{
	if (!fla['P'])
	{
		if (fla['0'])
			sign_4dbl(&*fla, dnbr, r);
		pf_putnchar((fla['0'] ? '0' : ' '), fla['W'] - fla['N']\
				- ((fla['+'] || fla[' ']) || !(1 / dnbr > 0) ? 1 : 0)\
				- (fla['#'] || (ABS(dnbr - (long)dnbr) > .0 ? 1 : 0))\
				, r);
		if (!fla['0'])
			sign_4dbl(&*fla, dnbr, r);
	}
	else
	{
		pf_putnchar(' ', fla['W'] - fla['N'] - fla['P']\
				- ((fla['+'] || fla[' ']) || !(1 / dnbr > 0) ? 1 : 0)\
				- (fla['#'] || (ABS(dnbr - (long)dnbr) >= .0 ? 1 : 0))\
				, r);
		sign_4dbl(&*fla, dnbr, r);
	}
	pf_putdbl(&*fla, ABS(dnbr), r);
}

void	floats(t_env *var, unsigned char b)
{
	is_csf(var->fla, &var->conv, var->ap, b);
	var->fla['N'] = pf_nbrlen(var->conv.dnbr, 'f');
	if (!var->fla['.'] && !var->fla['P'])
		var->fla['P'] = 6;
	if (var->fla['-'])
	{
		sign_4dbl(var->fla, var->conv.dnbr, &var->r);
		pf_putdbl(var->fla, ABS(var->conv.dnbr), &var->r);
		pf_putnchar(' ', var->fla['W'] - var->fla['N'] - var->fla['P']\
				- (var->fla['+'] || var->fla[' '] || !(1 / var->conv.dnbr > 0) ? 1 : 0)\
				- (var->fla['#'] ||\
					(ABS(var->conv.dnbr - (long)var->conv.dnbr) >= .0) ? 1 : 0)\
				, &var->r);
	}
	else
		other_4dbl(&*var->fla, var->conv.dnbr, &var->r);
}
