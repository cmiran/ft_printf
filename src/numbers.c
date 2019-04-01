/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:19:19 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/31 21:12:10 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	sign(size_t *fla, ssize_t nbr, char b)
{
	if (nbr < 0)
		write(1, "-", 1);
	else if (fla['+'] && !pf_strchr("ouxX", b))
		nbr < 0 ? write(1, "-", 1) : write(1, "+", 1);
	else if (!fla['+'] && fla[' '] && !pf_strchr("ouxX", b))
		nbr < 0 ? write(1, "-", 1) : write(1, " ", 1);
}

void	other(size_t *fla, t_conv conv, char b, char c)
{
	size_t len;

	len = conv.nbr ? pf_nbrlen(conv.nbr, b) : pf_unbrlen(conv.unbr, b);
	if (!fla['P'])
	{
		if (c == '0')
			sign(fla, conv.nbr, b);
		if (fla['W'])
			ft_putnchar(c, fla['W'] - len -\
				((fla['+'] || fla[' ']) &&\
				 	conv.nbr >= 0 && !pf_strchr("ouxX", b) ? 1 : 0) -\
				(fla['#'] && b == 'o' && conv.unbr ? 1 : 0));
		if (c == ' ')
			sign(fla, conv.nbr, b);
	}
	else
	{
		if ((ssize_t)(fla['W'] - fla['P']) > 0)
			ft_putnchar(' ', fla['W'] - (len > fla['P'] ? len : fla['P']) -\
				((fla['+'] || fla[' ']) &&\
				 	conv.nbr >= 0 && !pf_strchr("ouxX", b) ? 1 : 0) -\
				(conv.nbr < 0 && fla['P'] > len ? 1 : 0));
		sign(fla, conv.nbr, b);
		ft_putnchar('0', fla['P'] - (conv.nbr >= 0 ? len : len - 1));
	}
	conv.nbr ? pf_putnbr(conv.nbr) : pf_putnbr_base(conv.unbr, b, fla);
}

void	dash(size_t *fla, t_conv conv, char b)
{
	size_t len;

	len = conv.nbr ? pf_nbrlen(conv.nbr, b) : pf_unbrlen(conv.unbr, b);
	sign(fla, conv.nbr, b);
	if (fla['P'] > len)
		ft_putnchar('0', fla['P'] - len + (conv.nbr < 0 ? 1 : 0));
	conv.nbr ? pf_putnbr(conv.nbr) : pf_putnbr_base(conv.unbr, b, fla);
	if ((ssize_t)(fla['W'] - fla['P']) > 0)
		ft_putnchar(' ', fla['W'] - (len > fla['P'] ? len : fla['P']) -\
			((fla['+'] || fla[' ']) && conv.nbr >= 0 && !pf_strchr("ouxX", b) ? 1 : 0) -\
			(conv.nbr < 0 && fla['P'] > len ? 1 : 0));
}

unsigned int	hash(size_t unbr, char b, size_t *fla)
{
	if (b == 'o')
		ft_putnchar('0', 1 - (fla['P'] > pf_nbrlen(unbr, b) ? 1 : 0) -\
				(unbr > 0 ? 0 : 1));
	return (0);
}

void	dispatch(t_env *var, char b)
{
	if (b == 'd' || b == 'i')
	{
		if (!is_di(var->fla, &var->conv.nbr, var->ap))
			exit(EXIT_FAILURE);
	}
	else
		if (!is_ouxX(var->fla, &var->conv.unbr, var->ap))
			exit(EXIT_FAILURE);
	if (var->fla['-'])
		dash(var->fla, var->conv, b);
	else if (var->fla['0'])
		other(var->fla, var->conv, b, '0');
	else
		other(var->fla, var->conv, b, ' ');
}
