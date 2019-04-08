/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:45:53 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/08 00:43:20 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	pf_putdbl(size_t *fla, long double dnbr, unsigned char len, size_t *ret)
{
	size_t	i;

	if (fla['.'] && !fla['P'] && (dnbr - (int)dnbr) * 10 > 4)
		pf_putnbr(dnbr < 0 ? dnbr - 1 : dnbr + 1, ret);
	else
		pf_putnbr(dnbr, ret);
	if (fla['#'] || fla['P'])
	{
		write(1, ".", 1);
		(*ret)++;
	}
	if (fla['P'])
	{
		i = 0;
		while (i++ < fla['P'])
		{
			dnbr = (dnbr - (int)dnbr) * 10; 
			if (fla['P'] + len < 18 && (dnbr - (int)dnbr) * 10 > 8)
				(int)dnbr == 9 ? pf_putnbr(dnbr - 9, ret) :\
					   pf_putnbr(dnbr + 1, ret);
			else
/*				if (i > 15)
					while (i > 15 && i++ < 19)
						if ((dnbr - (int)dnbr) * 10 > 8)
							(int)dnbr == 9 ? pf_putnbr(dnbr - 9, ret) :\
								   pf_putnbr(dnbr + 1, ret);
						else
							pf_putnbr(dnbr, ret);
				else*/
					pf_putnbr(dnbr, ret);
		}
	}
}

void	sign_4dbl(size_t *fla, long double dnbr, size_t *ret)
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
			sign_4dbl(fla, dnbr, ret);
		pf_putnchar((fla['0'] ? '0' : ' '), fla['W'] - len -\
				((fla['+'] || fla[' ']) || dnbr < 0 ? 1 : 0) -\
				(fla['#'] || (ABS(dnbr - (int)dnbr) > 0 ? 1 : 0)), ret);
		if (!fla['0'])
			sign_4dbl(fla, dnbr, ret);
	}
	else
	{
		pf_putnchar(' ', fla['W'] - len - fla['P'] -\
				((fla['+'] || fla[' ']) || dnbr < 0 ? 1 : 0) -\
				(fla['#'] || (ABS(dnbr - (int)dnbr) >= 0 ? 1 : 0)), ret);
		sign_4dbl(fla, dnbr, ret);
	}
	pf_putdbl(fla, ABS(dnbr), len, ret);
}

void	floats(t_env *var, unsigned char b)
{
	unsigned char	len;

	if (b == 'f')
		if (!is_f(var->fla['L'], &var->conv.dnbr, var->ap))
			exit(EX_USAGE);
	len = pf_nbrlen(var->conv.dnbr, 'f');
	if (!var->fla['.'] && !var->fla['P'])
		var->fla['P'] = 6;
	if (var->fla['-'])
	{
		sign_4dbl(var->fla, var->conv.dnbr, &var->ret);
		pf_putdbl(var->fla, ABS(var->conv.dnbr), len, &var->ret);
		pf_putnchar(' ', var->fla['W'] - len - var->fla['P'] -\
			((var->fla['+'] || var->fla[' ']) || var->conv.dnbr < 0 ? 1 : 0) -\
			(var->fla['#'] ||\
				ABS(var->conv.dnbr - (long)var->conv.dnbr) > LDBL_EPSILON ? 1 : 0),\
			&var->ret);
	}
	else
		other_4dbl(var->fla, var->conv.dnbr, len, &var->ret);
}
