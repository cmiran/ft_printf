/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:27:24 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/01 18:41:12 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	width(size_t *fla, long long nbr, unsigned char b, unsigned char len)
{
	ft_putnchar(' ', fla['W'] -\
			(pf_strchr("di", b) && (len + fla['P']) > 32 ?\
			 len : fla['P']) -\
			(pf_strchr("ouxX", b) && (len + fla['P']) > 64 ?\
			 len : fla['P']) -\
			(fla['#'] ? 1 : 0) -\
			((fla['+'] || fla[' ']) && nbr >= 0 &&\
			 !pf_strchr("ouxX", b) ? 1 : 0) -\
			(nbr < 0 && fla['P'] > len ? 1 : 0));
}

void	precision(size_t *fla, t_conv conv, unsigned char len)
{
	if ((fla['P'] + len) <= 32)
		pf_putbin(fla, conv.nbr, fla['P'] + len);
	else if ((fla['P'] + len) <= 64)
		pf_putubin(fla, conv.unbr, fla['P'] + len);
	else
		conv.nbr ? pf_putbin(fla, conv.nbr, 32) :\
			pf_putubin(fla, conv.unbr, 64);

}

void	sign_4bin(size_t *fla, long long nbr, char b)
{
	if (nbr < 0)
		write(1, "-", 1);
	else if (fla['+'] && !pf_strchr("ouxX", b))
		nbr < 0 ? write(1, "-", 1) : write(1, "+", 1);
	else if (fla[' '] && fla['+'] && !pf_strchr("ouxX", b))
		nbr < 0 ? write(1, "1", 1) : write(1, "0", 1);
	if (fla['#'])
		write(1, " ", 1);
}

void	other_4bin(size_t *fla, t_conv conv, unsigned char b, unsigned char len)
{
	if (!fla['P'])
	{
		if (fla['W'])
			width(fla, b, len, conv.nbr);
		sign_4bin(fla, conv.nbr, b);
	}
	else if (fla['W'] > fla['P'])
	{	
		width(fla, b, len, conv.nbr);
		sign_4bin(fla, conv.nbr, b);
		precision(fla, conv, len);
		return ;
	}
	conv.nbr ? pf_putbin(fla, conv.nbr, len) : pf_putubin(fla, conv.unbr, len);
}

void	dash_4bin(size_t *fla, t_conv conv, char b, unsigned char len)
{
	sign_4bin(fla, conv.nbr, b);
	precision(fla, conv, len);
	if (fla['W'] > fla['P'])
		width(fla, b, len, conv.nbr);
}

void	binary(t_env *var, char b)
{
	unsigned char	len;

	var->conv.nbr = va_arg(var->ap, long long);
	if (var->conv.nbr > LLONG_MIN && var->conv.nbr < LLONG_MAX)
		exit(EXIT_FAILURE);
//	pf_putbin(var->fla, 256, 10);
	len = var->conv.nbr ? pf_nbrlen(var->conv.nbr, 'b') : pf_nbrlen_base(var->conv.unbr, 'b');
	if (var->fla['-'])
		dash_4bin(var->fla, var->conv, b, len);
	else
		other_4bin(var->fla, var->conv, b, len);
}
