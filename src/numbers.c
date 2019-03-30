/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:19:19 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/30 14:44:59 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	is_di(size_t *fla, ssize_t *nbr, va_list ap)
{
	if (fla[91] && (*nbr = va_arg(ap, int)))
		return (*nbr >= SCHAR_MIN && *nbr <= SCHAR_MAX);
	else if (fla['h'] && (*nbr = va_arg(ap, int)))
		return (*nbr >= SHRT_MIN && *nbr <= SHRT_MAX);
	else if (fla['l'] && (*nbr = va_arg(ap, long)))
		return (*nbr >= LONG_MIN && *nbr <= LONG_MAX );
	else if (fla[93] && (*nbr = va_arg(ap, long long)))
		return (*nbr >= LLONG_MIN && *nbr <= LLONG_MAX);
	else
	{
		*nbr = va_arg(ap, int);
		return (*nbr > INT_MIN && *nbr < INT_MAX);
	}
	return (0);
}

int	is_ouxX(size_t *fla, size_t *unbr, va_list ap)
{
	if (fla[91] && (*unbr = va_arg(ap, unsigned int)))
		return (*unbr > 0 && *unbr <= UCHAR_MAX);
	else if (fla['h'] && (*unbr = va_arg(ap, unsigned int)))
		return (*unbr > 0 && *unbr <= USHRT_MAX);
	else if (fla['l'] && (*unbr = va_arg(ap, unsigned long)))
		return (*unbr > 0 && *unbr <= ULONG_MAX);
	else if (fla[93] && (*unbr = va_arg(ap, unsigned long long)))
		return (*unbr > 0 && *unbr <= ULLONG_MAX);
	else
	{
		*unbr = va_arg(ap, unsigned int);
		return (*unbr > 0 && *unbr < UINT_MAX);
	}
	return (0);
}

void	sign(size_t *fla, ssize_t nbr)
{
	if (nbr < 0)
		write(1, "-", 1);
	else if (fla['+'])
		nbr < 0 ? write(1, "-", 1) : write(1, "+", 1);
	else if (!fla['+'] && fla[' '])
		nbr < 0 ? write(1, "-", 1) : write(1, " ", 1);
}

void	other(size_t *fla, t_conv conv, char c, char d)
{
	size_t len;

	len = conv.nbr ? ft_nbrlen((int)conv.nbr) : ft_nbrlen((unsigned int)conv.unbr);
	if (!fla['P'])
	{
		sign(fla, conv.nbr);
		if (fla['W'])
			ft_putnchar(d, fla['W'] - len -\
				((fla['+'] || fla[' ']) && conv.nbr > 0 ? 1 : 0));
	}
	else if (fla['P'])
	{
		if ((ssize_t)(fla['W'] - fla['P']) > 0)
			ft_putnchar(' ', fla['W'] - (len > fla['P'] ? len : fla['P']) -\
				((fla['+'] || fla[' ']) && conv.nbr > 0 ? 1 : 0) -\
				(conv.nbr < 0 && fla['P'] > len ? 1 : 0));
		sign(fla, conv.nbr);
		ft_putnchar('0', fla['P'] - (conv.nbr > 0 ? len : len - 1));
	}
	conv.nbr ? pf_putnbr(conv.nbr) : pf_putnbr_base(conv.unbr, c);
}
/*
void	zer0(size_t *fla, t_conv conv, char c)
{
	size_t len;

	len = conv.nbr ? ft_nbrlen((int)conv.nbr) : ft_nbrlen(conv.unbr);
	if (!fla['P'])
	{
		sign(fla, conv.nbr);
		if (fla['W'])
			ft_putnchar('0', fla['W'] - len -\
				((fla['+'] || fla[' ']) && conv.nbr > 0 ? 1 : 0));
	}
	else if (fla['P'])
	{
		if ((ssize_t)(fla['W'] - fla['P']) > 0)
			ft_putnchar(' ', fla['W'] - (len > fla['P'] ? len : fla['P']) -\
				((fla['+'] || fla[' ']) && conv.nbr > 0 ? 1 : 0) -\
				(conv.nbr < 0 && fla['P'] > len ? 1 : 0));
		sign(fla, conv.nbr);
		ft_putnchar('0', fla['P'] - (conv.nbr > 0 ? len : len - 1));
	}
	conv.nbr ? pf_putnbr(conv.nbr) : pf_putnbr_base(conv.unbr, c);
}
*/
void	dash(size_t *fla, t_conv conv, char c)
{
	size_t len;

	len = conv.nbr ? ft_nbrlen((int)conv.nbr) : ft_nbrlen((unsigned int)conv.unbr);
	sign(fla, conv.nbr);
	if (fla['P'] > len)
		ft_putnchar('0', fla['P'] - len + (conv.nbr < 0 ? 1 : 0));
	conv.nbr ? pf_putnbr(conv.nbr) : pf_putnbr_base(conv.unbr, c);
	if ((ssize_t)(fla['W'] - fla['P']) > 0)
		ft_putnchar(' ', fla['W'] - (len > fla['P'] ? len : fla['P']) -\
			((fla['+'] || fla[' ']) && conv.nbr > 0 ? 1 : 0) -\
			(conv.nbr < 0 && fla['P'] > len ? 1 : 0));
}

void	dispatch(t_env *var, char c)
{
	if (pf_strchr("di", c))
	{
		if (!is_di(var->fla, &var->conv.nbr, var->ap))
			exit(EXIT_FAILURE);
	}
	else
		if (!is_ouxX(var->fla, &var->conv.unbr, var->ap))
			exit(EXIT_FAILURE);
	if (var->fla['-'])
		dash(var->fla, var->conv, c);
	else if (var->fla['0'])
		other(var->fla, var->conv, c, '0');
/*	else if (var->fla['+'] || var->fla[' '])
	{
		sign(var->fla, var->conv.nbr);
		var->conv.nbr ? pf_putnbr(var->conv.nbr) : pf_putnbr_base(var->conv.u_nbr, c);
	}*/
	else
		other(var->fla, var->conv, c, ' ');
}
