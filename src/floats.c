/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:45:53 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/02 19:30:37 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	pf_putdbl(size_t *e, long double dnbr, size_t *r)
{
	size_t	i;
//	int	nb;

	if (e['.'] && !e['P'] && (dnbr - (long)dnbr) * 10 > 5.)
		pf_putnbr(dnbr < 0 ? dnbr - 1. : dnbr + 1., r);
	else
		pf_putnbr(dnbr, r);
	if (e['#'] || e['P'])
		pf_putchar('.', r);
	i = 0;
//	printf("\ndnbr : %Lf\n", (dnbr - (long)dnbr) * 10.);
	while (i++ < e['P'])
	{
		dnbr = (dnbr - (long)dnbr) * 10.;
		printf("\ndnbr : %Lf\n", dnbr);
		if (e['P'] + e['N'] < (dnbr < .0 || e['+'] || e[' '] ? 19 : 18)\
				&& (dnbr - (int)dnbr) * 10 == 9.)
/*
**					Le probleme est la ^^^^^ (== 9. || >= 9.)
*/
			(int)dnbr == 9 ? pf_putnbr(dnbr - 9., r) :\
				pf_putnbr(dnbr + 1., r);
		else if (i == e['P'] && (dnbr - (int)dnbr) * 10 > 5.)
		{
			printf("\nonysuis\n");
			(int)dnbr == 9 ? pf_putnbr(dnbr - 9., r) :\
				pf_putnbr(dnbr + 1., r);
		}
		else
		{
//			printf("\ndnbr : %Lf, %Lf\n", dnbr, dnbr * (10 ^ e['P']));
//			printf("\nprecision :%lu\n", e['P']);
//			pf_putnbr(nb = (int)dnbr, r);
//			break ;
			(int)dnbr == 9  ? pf_putnbr(dnbr - 9., r) : 0;
			(dnbr - (int)dnbr) * 10 == 9. ? pf_putnbr(dnbr + 1, r) : pf_putnbr(dnbr, r);
		}
	}
}

void	sign_4dbl(size_t *e, long double dnbr, size_t *r)
{
	if (!(1 / dnbr > 0))
	{
		write(1, "-", 1);
		++*r;
	}
	else if (e['+'])
	{
		!(1 / dnbr > 0) ? write(1, "-", 1) : write(1, "+", 1);
		++*r;
	}
	else if (e[' '] && !e['+'])
	{
		!(1 / dnbr > 0) ? write(1, "-", 1) : write(1, " ", 1);
		++*r;
	}
}

void	other_4dbl(size_t *e, long double dnbr, size_t *r)
{
	if (e['0'])
		sign_4dbl(e, dnbr, r);
	pf_putnchar((e['0'] ? '0' : ' '), e['W'] - e['N'] - e['P']\
			- (e['+'] || e[' '] || !(1 / dnbr > 0) ? 1 : 0)\
			- (e['#'] || (ABS(dnbr - (long)dnbr) >= .0) ? 1 : 0)\
			, r);
	if (!e['0'])
		sign_4dbl(e, dnbr, r);
	pf_putdbl(e, ABS(dnbr), r);
}

void	dash_4dbl(size_t *e, long double dnbr, size_t *r)
{
	sign_4dbl(e, dnbr, r);
	pf_putdbl(e, ABS(dnbr), r);
	pf_putnchar(' ', e['W'] - e['N'] - e['P']\
			- (e['+'] || e[' '] || !(1 / dnbr > 0) ? 1 : 0)\
			- (e['#'] || (ABS(dnbr - (long)dnbr) >= .0) ? 1 : 0)\
			, r);
}

void	floats(t_env *var, unsigned char b)
{
	is_csf(var->e, &var->conv, var->ap, b);
	var->e['N'] = pf_nbrlen(var->conv.dnbr, 'f');
	if (!var->e['.'])
		var->e['P'] = 6;
	var->e['-'] ? dash_4dbl(&*var->e, var->conv.dnbr, &var->r) :\
		other_4dbl(&*var->e, var->conv.dnbr, &var->r);
}
