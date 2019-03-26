/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diouxX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:19:19 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/26 18:30:40 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	is_ouxX(size_t *fla, va_list *ap, uintmax_t *u_nbr)
{
	if (fla[91] && (*u_nbr = (unsigned char) va_arg(*ap, int)))
		return (*u_nbr > UCHAR_MAX);
	else if (fla['h'] && (*u_nbr = (short) va_arg(*ap, int)))
		return (*u_nbr > USHRT_MAX);
	else if (fla['l'] && (*u_nbr = (long) va_arg(*ap, long)))
		return (*u_nbr > ULONG_MAX);
	else if (fla[93] && (*u_nbr = (long long) va_arg(*ap, long long)))
		return (*u_nbr > ULLONG_MAX);
	else
	{
		*u_nbr = va_arg(*ap, unsigned int);
		return (*u_nbr > UINT_MAX);
	}
	return (0);	
}

int	is_di(size_t *fla, va_list *ap, intmax_t *nbr)
{
	if (fla[91] && (*nbr = (char) va_arg(*ap, int)))
		return (*nbr < SCHAR_MIN || *nbr > SCHAR_MAX);
	else if (fla['h'] && (*nbr = (short) va_arg(*ap, int)))
		return (*nbr < SHRT_MIN || *nbr > SHRT_MAX);
	else if (fla['l'] && (*nbr = (long) va_arg(*ap, long)))
		return (*nbr < LONG_MIN || *nbr > LONG_MAX);
	else if (fla[93] && (*nbr = (long long) va_arg(*ap, long long)))
		return (*nbr < LLONG_MIN || *nbr > LLONG_MAX);
	else
	{
		*nbr = va_arg(*ap, int);
		return (*nbr < INT_MIN || *nbr > INT_MAX);
	}
	return (0);
}

void	fl_sign(size_t *fla, t_conv conv)
{
	if (conv.nbr > 0)
		write(1, "-", 1);
	else if (fla['+'])
		conv.nbr < 0 ? write(1, "-", 1) : write(1, "+", 1);
	else if (!fla['+'] && fla[' '])
		conv.nbr < 0 ? write(1, "-", 1) : write (1, " ", 1);
}

void	fl_zer0(size_t *fla, t_conv conv, size_t len)
{
	if (!fla['P'])
	{
		fl_sign(fla, conv);
		if (fla['W'])
			ft_putnchar('0', fla['W'] - len -\
				((fla['+'] || fla[' ']) && (conv.nbr > 0 || conv.u_nbr) ? 1 : 0));
	}
	else if (fla['P'])
	{
		if ((int)fla['W'] - (int)fla['P'] > 0)
			ft_putnchar(' ', fla['W'] - (len > fla['P'] ? len : fla['P']) -\
				((fla['+'] || fla[' ']) && conv.nbr > 0 ? 1 : 0) -\
				(conv.nbr < 0 && fla['P'] > len ? 1 : 0));
		fl_sign(fla, conv);
		ft_putnchar('0', fla['P'] - ((conv.nbr > 0 || conv.u_nbr) ? len : len - 1));
	}
	conv.nbr ? pf_putnbr(conv.nbr) : pf_putnbr_base(conv.u_nbr, fla);
}

void	fl_dash(size_t *fla, t_conv conv, size_t len)
{
	fl_sign(fla, conv);
	if (fla['P'] > len)
		ft_putnchar('0', fla['P'] - len + (conv.nbr < 0 ? 1 : 0));
	conv.nbr ? pf_putnbr(conv.nbr) : pf_putnbr_base(conv.u_nbr, fla);
	if ((int)fla['W'] - (int)fla['P'] > 0)
		ft_putnchar(' ', fla['W'] - (len > fla['P'] ? len : fla['P']) -\
			((fla['+'] || fla[' ']) && (conv.nbr > 0 || conv.u_nbr) ? 1 : 0) -\
			(conv.nbr < 0 && fla['P'] > len ? 1 : 0));
}

void	set_format(t_env *var)
{
	size_t	len;

	if (var->fla['d'] || var->fla['i'])
	{
		if (!is_di(var->fla, &var->ap, &var->conv.nbr))
			exit(EXIT_FAILURE);
	}
	else
		if (!is_ouxX(var->fla, &var->ap, &var->conv.u_nbr))
			exit(EXIT_FAILURE);
	len = ft_nbrlen(var->conv.nbr) || ft_nbrlen(var->conv.u_nbr);
	if (var->fla['-'])
		fl_dash(var->fla, var->conv, len);
	else if (var->fla['0'])
		fl_zer0(var->fla, var->conv, len);
	else if (var->fla['+'] || var->fla[' '])
		fl_sign(var->fla, var->conv);
}
