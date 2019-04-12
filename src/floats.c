/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:45:53 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/12 16:07:03 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	pf_putdbl(size_t *fla, long double dnbr)
{
	size_t	i;

	if (fla['.'] && !fla['P'] && (dnbr - (long)dnbr) * 10 > 5.)
		pf_putnbr(dnbr < 0 ? dnbr - 1. : dnbr + 1., &*fla);
	else
		pf_putnbr(dnbr, &*fla);
	if (fla['#'] || fla['P'])
	{
		write(1, ".", 1);
		fla['R']++;
	}
	i = 0;
	while (i++ < fla['P'])
	{
		dnbr = (dnbr - (long)dnbr) * 10.;
		if (fla['P'] + fla['N'] < (dnbr < .0 || fla['+'] || fla[' '] ? 19 : 18)\
				&& (dnbr - (int)dnbr) * 10 > 8.)
			(int)dnbr == 9 ? pf_putnbr(dnbr - 9., &*fla) :\
				   pf_putnbr(dnbr + 1., &*fla);
		else if (i == fla['P'] && (dnbr - (int)dnbr) * 10 > 5.)
			(int)dnbr == 9 ? pf_putnbr(dnbr - 9., &*fla) :\
				   pf_putnbr(dnbr + 1., &*fla);
		else
			pf_putnbr(dnbr, &*fla);
	}
}

void	sign_4dbl(size_t *fla, long double dnbr)
{
	if (dnbr < .0)
	{
		write(1, "-", 1);
		fla['R']++;
	}
	else if (fla['+'])
	{
		dnbr < .0 ? write(1, "-", 1) : write(1, "+", 1);
		fla['R']++;
	}
	else if (fla[' '] && !fla['+'])
	{
		dnbr < .0 ? write(1, "-", 1) : write(1, " ", 1);
		fla['R']++;
	}
}

void	other_4dbl(size_t *fla, long double dnbr)
{
	if (!fla['P'])
	{
		if (fla['0'])
			sign_4dbl(&*fla, dnbr);
		pf_putnchar((fla['0'] ? '0' : ' '), fla['W'] - fla['N']\
				- ((fla['+'] || fla[' ']) || dnbr < .0 ? 1 : 0)\
				- (fla['#'] || (ABS(dnbr - (long)dnbr) > .0 ? 1 : 0))\
				, &fla['R']);
		if (!fla['0'])
			sign_4dbl(&*fla, dnbr);
	}
	else
	{
		pf_putnchar(' ', fla['W'] - fla['N'] - fla['P']\
				- ((fla['+'] || fla[' ']) || dnbr < .0 ? 1 : 0)\
				- (fla['#'] || (ABS(dnbr - (long)dnbr) >= .0 ? 1 : 0))\
				, &fla['R']);
		sign_4dbl(&*fla, dnbr);
	}
	pf_putdbl(&*fla, ABS(dnbr));
}

void	floats(t_env *var, unsigned char b)
{
	var->fla['F'] = 1;
/*
**	^ float maker used later in pf_putnbr.c
*/
	if (b == 'f')
		if (!is_f(var->fla['L'], &var->conv.dnbr, var->ap))
			exit(EX_USAGE);
	var->fla['N'] = pf_nbrlen(var->conv.dnbr, 'f');
	if (!var->fla['.'] && !var->fla['P'])
		var->fla['P'] = 6;
	if (var->fla['-'])
	{
		sign_4dbl(var->fla, var->conv.dnbr);
		pf_putdbl(var->fla, ABS(var->conv.dnbr));
		pf_putnchar(' ', var->fla['W'] - var->fla['N'] - var->fla['P']\
			- (var->fla['+'] || var->fla[' '] || var->conv.dnbr < .0 ? 1 : 0)\
			- (var->fla['#'] ||\
				ABS(var->conv.dnbr - (long)var->conv.dnbr) > .0 ? 1 : 0),\
			&var->fla['R']);
	}
	else
		other_4dbl(&*var->fla, var->conv.dnbr);
}
