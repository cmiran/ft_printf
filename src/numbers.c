/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:19:19 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/06 20:33:33 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		sign(size_t *fla, ssize_t nbr, unsigned char b, size_t *ret)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		(*ret)++;
	}
	else if (fla['+'] && !pf_strchr("ouxX", b))
	{
		nbr < 0 ? write(1, "-", 1) : write(1, "+", 1);
		(*ret)++;
	}
	else if (fla[' '] && !fla['+'] && !pf_strchr("ouxX", b))
	{
		nbr < 0 ? write(1, "-", 1) : write(1, " ", 1);
		(*ret)++;
	}
}

void		other(size_t *fla, t_conv conv, unsigned char b, size_t *ret)
{
	unsigned char len;

	len = conv.nbr ? pf_nbrlen(conv.nbr, b) : pf_unbrlen(conv.unbr, b);
	if (!fla['P'])
	{
		if (fla['0'])
			sign(fla, conv.nbr, b, ret);
		if (fla['W'] > len)
			pf_putnchar((fla['0'] ? '0' : ' '), fla['W'] - len -\
				(((fla['+'] || fla[' ']) /*&&*/||\
				 	/*conv.nbr >= 0*/ conv.nbr < 0) && !pf_strchr("ouxX", b) ? 1 : 0) -\
				(fla['#'] && b == 'o' && conv.unbr ? 1 : 0), ret);
		if (!fla['0'])
			sign(fla, conv.nbr, b, ret);
	}
	else
	{
		if (fla['W'] > fla['P'])
			pf_putnchar(' ', fla['W'] - (len > fla['P'] ? len : fla['P']) -\
				(((fla['+'] || fla[' ']) /*&&*/||\
				 	/*conv.nbr >= 0*/ conv.nbr < 0) && !pf_strchr("ouxX", b) ? 1 : 0) -\
				(conv.nbr < 0 && fla['P'] > len ? 1 : 0), ret);
		sign(fla, conv.nbr, b, ret);
		pf_putnchar('0', fla['P'] - (conv.nbr >= 0 ? len : len - 1), ret);
	}
	conv.nbr ? pf_putnbr(conv.nbr, ret) : pf_putnbr_base(conv.unbr, b, fla, ret);
}

void		dash(size_t *fla, t_conv conv, unsigned char b, size_t *ret)
{
	unsigned char len;

	len = conv.nbr ? pf_nbrlen(conv.nbr, b) : pf_unbrlen(conv.unbr, b);
	if (fla['#'] && (b == 'x' || b == 'X'))
	{
		b == 'x' ? write(1, "0x", 2) : write(1, "0X", 2);
		(*ret) += 2;
	}
	else
		sign(fla, conv.nbr, b, ret);
	if (fla['P'] > len)
		pf_putnchar('0', fla['P'] - len + (conv.nbr < 0 ? 1 : 0), ret);
	conv.nbr ? pf_putnbr(conv.nbr, ret) : pf_putnbr_base(conv.unbr, b, fla, ret);
	if (fla['W'] > (len > fla['P'] ? len : fla['P']))
		pf_putnchar(' ', fla['W'] - (len > fla['P'] ? len : fla['P']) -\
			((fla['+'] || fla[' ']) && conv.nbr >= 0 && !pf_strchr("ouxX", b) ? 1 : 0) -\
			(conv.nbr < 0 && fla['P'] > len ? 1 : 0) -\
			(fla['#'] && (b == 'o') ? 1 : 0) -\
			(fla['#'] && (b == 'x' || b == 'X') ? 2 : 0), ret);
}

unsigned int	hash(size_t unbr, unsigned char b, size_t *fla, size_t *ret)
{
	unsigned char len;

	len = pf_unbrlen(unbr, b);
	if (b == 'o')
		pf_putnchar('0', 1 - (fla['P'] > len ? 1 : 0) - (unbr > 0 ? 0 : 1), ret);
	else
	{
		if (!fla['P'])
		{
			if (fla['W'])
				pf_putnchar(' ', fla['W'] - len - 2, ret);
			ft_isupper(b) ? write(1, "0X", 2) : write(1, "0x", 2);
		}
		else
		{
			if (fla['W'] > fla['P'])
				pf_putnchar(' ', fla['W'] -\
						(len > fla['P'] ? len + 2 : fla['P'] + 2), ret);
			ft_isupper(b) ? write(1, "0X", 2) : write(1, "0x", 2);
			if (fla['P'] > len)
				pf_putnchar('0', fla['P'] - len, ret);
		}
		pf_putnbr_base(unbr, b, fla, ret);
	}
	return (0);
}

void		numbers(t_env *var, unsigned char b)
{
	if (b == 'd' || b == 'i')
	{
		if (!is_bdi(var->fla, &var->conv.nbr, var->ap))
			exit(EXIT_FAILURE);
	}
	else
	{
		if (!is_ouxX(var->fla, &var->conv.unbr, var->ap))
			exit(EXIT_FAILURE);
	}
	if (var->fla['#'] && !var->fla['-'] && (b == 'x' || b == 'X'))
	{
		var->ret += 2;
		hash(var->conv.unbr, b, var->fla, &var->ret);
	}
	else if (var->fla['-'])
		dash(var->fla, var->conv, b, &var->ret);
	else
		other(var->fla, var->conv, b, &var->ret);
}
