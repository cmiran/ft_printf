/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diouxX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:19:19 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/24 19:25:30 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	fl_zer0(size_t *fla, long long nbr)
{
	if (!fla['P'])
	{
		nbr < 0 ? write(1, "-", 1) : 0;
		if (fla['+'] || fla[' '])
			fla[' '] ? (nbr > 0 ? write(1, " ", 1) : 0) :\
				(nbr > 0 ? write(1, "+", 1) : 0);
		ft_putnchar('0', fla['W'] - ft_nbrlen(nbr));
	}
	else if (fla['P'])
	{
		if ((int)fla['W'] - (int)fla['P'] > 0)
			ft_putnchar(' ', fla['W'] - fla['P'] -\
					(ft_nbrlen(nbr) > fla['P'] ? ft_nbrlen(nbr) : 0) -\
					(fla['+'] || fla[' '] ? 1 : 0) -\
					(nbr < 0 && fla['P'] ? 1 : 0));
		nbr < 0 ? write(1, "-", 1) : 0;
		if (fla['+'] || fla[' '])
			fla[' '] ? (nbr > 0 ? write(1, " ", 1) : 0) :\
				(nbr > 0 ? write(1, "+", 1) : 0);
		ft_putnchar('0', fla['P'] - ft_nbrlen(nbr));
	}
	pf_putnbr(nbr);
}

void	fl_dash(size_t *fla, long long nbr)
{
	nbr < 0 ? write(1, "-", 1) : 0;
	if (fla['+'] || fla[' '])
		fla[' '] ? (nbr > 0 ? write(1, " ", 1) : 0) :\
			(nbr > 0 ? write(1, "+", 1) : 0);
	if (fla['P'] > ft_nbrlen(nbr))
		ft_putnchar('0', fla['P'] - ft_nbrlen(nbr) +\
				(nbr < 0 ? 1 : 0));
	pf_putnbr(nbr);
	if ((int)fla['W'] - (int)fla['P'] > 0)
		ft_putnchar(' ', fla['W'] - fla['P'] -\
				(ft_nbrlen(nbr) > fla['P'] ? ft_nbrlen(nbr) : 0) -\
				(fla['+'] || fla[' '] ? 1 : 0) -\
				(nbr < 0 && fla['P'] ? 1 : 0));
}

void	is_di(t_printf *var)
{
	long long	nbr;

	nbr = va_arg(var->ap, int);
	if (var->fla['-'])	/* flag '-' */
		fl_dash(var->fla, nbr);
	else if (var->fla['0'])	/* flag '0' */
		fl_zer0(var->fla, nbr);
}
