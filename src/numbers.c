/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:19:19 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/30 18:02:50 by cmiran           ###   ########.fr       */
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
		return (*unbr <= UCHAR_MAX);
	else if (fla['h'] && (*unbr = va_arg(ap, unsigned int)))
		return (*unbr <= USHRT_MAX);
	else if (fla['l'] && (*unbr = va_arg(ap, unsigned long)))
		return (*unbr <= ULONG_MAX);
	else if (fla[93] && (*unbr = va_arg(ap, unsigned long long)))
		return (*unbr <= ULLONG_MAX);
	else
	{
		*unbr = va_arg(ap, unsigned int);
		return (*unbr < UINT_MAX);
	}
	return (0);
}

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
		sign(fla, conv.nbr, b);
		if (fla['W'])
			ft_putnchar(c, fla['W'] - len -\
				((fla['+'] || fla[' ']) && conv.nbr > 0 ? 1 : 0));
	}
	else if (fla['P'])
	{
		if ((ssize_t)(fla['W'] - fla['P']) > 0)
			ft_putnchar(' ', fla['W'] - (len > fla['P'] ? len : fla['P']) -\
				((fla['+'] || fla[' ']) && conv.nbr > 0 ? 1 : 0) -\
				(conv.nbr < 0 && fla['P'] > len ? 1 : 0));
		sign(fla, conv.nbr, b);
		ft_putnchar('0', fla['P'] - (conv.nbr >= 0 || conv.unbr  ? len : len - 1));
	}
	conv.nbr ? pf_putnbr(conv.nbr) : pf_putnbr_base(conv.unbr, b);
}

void	dash(size_t *fla, t_conv conv, char b)
{
	size_t len;

	len = conv.nbr ? pf_nbrlen(conv.nbr, b) : pf_unbrlen(conv.unbr, b);
	sign(fla, conv.nbr, b);
	if (fla['P'] > len)
		ft_putnchar('0', fla['P'] - len + (conv.nbr < 0 ? 1 : 0));
	conv.nbr ? pf_putnbr(conv.nbr) : pf_putnbr_base(conv.unbr, b);
	if ((ssize_t)(fla['W'] - fla['P']) > 0)
		ft_putnchar(' ', fla['W'] - (len > fla['P'] ? len : fla['P']) -\
			((fla['+'] || fla[' ']) && conv.nbr > 0 ? 1 : 0) -\
			(conv.nbr < 0 && fla['P'] > len ? 1 : 0));
}

void	dispatch(t_env *var, char b)
{
	if (pf_strchr("di", b))
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
