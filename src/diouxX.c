/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diouxX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:19:19 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/25 18:45:29 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	fl_sign(size_t *fla, long long nbr)
{
	if (nbr < 0)
		write(1, "-", 1);
	else if (fla['+'])
		write(1, "+", 1);
	else if (!fla['+'] && fla[' '])
		write(1, " ", 1);
}

void	fl_zer0(size_t *fla, long long nbr, unsigned short len)
{
	if (!fla['P'])
	{
		fl_sign(fla, nbr);
		if (fla['W'])
			ft_putnchar('0', fla['W'] - len -\
					((fla['+'] || fla[' ']) && nbr > 0 ? 1 : 0));
	}
	else if (fla['P'])
	{
		if ((int)fla['W'] - (int)fla['P'] > 0)
			ft_putnchar(' ', fla['W'] - (len > fla['P'] ? len : fla['P']) -\
					((fla['+'] || fla[' ']) && nbr > 0 ? 1 : 0) -\
					(nbr < 0 && fla['P'] > len ? 1 : 0));
		fl_sign(fla, nbr);
		ft_putnchar('0', fla['P'] - (nbr > 0 ? len : len - 1));
	}
	pf_putnbr(nbr);
}

void	fl_dash(size_t *fla, long long nbr, unsigned short len)
{
	fl_sign(fla, nbr);
	if (fla['P'] > len)
		ft_putnchar('0', fla['P'] - len + (nbr < 0 ? 1 : 0));
	pf_putnbr(nbr);
//	printf("\nfla['W'] : %lu, fla['P'] : %lu\n", fla['W'], fla['P']);
	if ((int)fla['W'] - (int)fla['P'] > 0)
		ft_putnchar(' ', fla['W'] - (len > fla['P'] ? len : fla['P']) -\
				((fla['+'] || fla[' ']) && nbr > 0 ? 1 : 0) -\
				(nbr < 0 && fla['P'] > len ? 1 : 0));
}

void	is_di(t_printf *var)
{
	long long	nbr;
	unsigned short	len;

	nbr = va_arg(var->ap, int);
	len = ft_nbrlen(nbr);
	if (var->fla['-'])
		fl_dash(var->fla, nbr, len);
	else if (var->fla['0'])	
		fl_zer0(var->fla, nbr, len);
	else if (var->fla['+'] || var->fla[' '])
		fl_sign(var->fla, len);
}
