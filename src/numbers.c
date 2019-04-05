/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:19:19 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/04 23:37:03 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		sign(size_t *fla, ssize_t nbr, unsigned char b)
{
	if (nbr < 0)
		write(1, "-", 1);
	else if (fla['+'] && !pf_strchr("ouxX", b))
		nbr < 0 ? write(1, "-", 1) : write(1, "+", 1);
	else if (fla[' '] && !fla['+'] && !pf_strchr("ouxX", b))
		nbr < 0 ? write(1, "-", 1) : write(1, " ", 1);
}

void		other(size_t *fla, t_conv conv, unsigned char b)
{
	unsigned char len;

	len = conv.nbr ? pf_nbrlen(conv.nbr, b) : pf_nbrlen_base(conv.unbr, b);
	if (!fla['P'])
	{
		if (fla['0'])
			sign(fla, conv.nbr, b);
		if (fla['W'] > len)
			ft_putnchar((fla['0'] ? '0' : ' '), fla['W'] - len -\
				((fla['+'] || fla[' ']) &&\
				 	conv.nbr >= 0 && !pf_strchr("ouxX", b) ? 1 : 0) -\
				(fla['#'] && b == 'o' && conv.unbr ? 1 : 0));
		if (!fla['0'])
			sign(fla, conv.nbr, b);
	}
	else
	{
		if (fla['W'] > fla['P'])
			ft_putnchar(' ', fla['W'] - (len > fla['P'] ? len : fla['P']) -\
				((fla['+'] || fla[' ']) &&\
				 	conv.nbr >= 0 && !pf_strchr("ouxX", b) ? 1 : 0) -\
				(conv.nbr < 0 && fla['P'] > len ? 1 : 0));
		sign(fla, conv.nbr, b);
		ft_putnchar('0', fla['P'] - (conv.nbr >= 0 ? len : len - 1));
	}
	conv.nbr ? pf_putnbr(conv.nbr) : pf_putnbr_base(conv.unbr, b, fla);
}

void		dash(size_t *fla, t_conv conv, unsigned char b)
{
	unsigned char len;

	len = conv.nbr ? pf_nbrlen(conv.nbr, b) : pf_nbrlen_base(conv.unbr, b);
	if (fla['#'] && (b == 'x' || b == 'X'))
		b == 'x' ? write(1, "0x", 2) : write(1, "0X", 1);
	else
		sign(fla, conv.nbr, b);
	if (fla['P'] > len)
		ft_putnchar('0', fla['P'] - len + (conv.nbr < 0 ? 1 : 0));
	conv.nbr ? pf_putnbr(conv.nbr) : pf_putnbr_base(conv.unbr, b, fla);
	if (fla['W'] > (len > fla['P'] ? len : fla['P']))
		ft_putnchar(' ', fla['W'] - (len > fla['P'] ? len : fla['P']) -\
			((fla['+'] || fla[' ']) && conv.nbr >= 0 && !pf_strchr("ouxX", b) ? 1 : 0) -\
			(conv.nbr < 0 && fla['P'] > len ? 1 : 0) -\
			(fla['#'] && (b == 'o') ? 1 : 0) -\
			(fla['#'] && (b == 'x' || b == 'X') ? 2 : 0));
}

unsigned int	hash(size_t unbr, unsigned char b, size_t *fla)
{
	unsigned char len;

	len = pf_nbrlen_base(unbr, b);
	if (b == 'o')
		ft_putnchar('0', 1 - (fla['P'] > len ? 1 : 0) - (unbr > 0 ? 0 : 1));
	if (b == 'x' || b == 'X')
	{
		if (!fla['P'])
		{
			if (fla['W'])
				ft_putnchar(' ', fla['W'] - len - 2);
			ft_isupper(b) ? write(1, "0X", 2) : write(1, "0x", 2);
		}
		else
		{
			if (fla['W'] > fla['P'])
				ft_putnchar(' ', fla['W'] -\
						(len > fla['P'] ? len + 2 : fla['P'] + 2));
			ft_isupper(b) ? write(1, "0X", 2) : write(1, "0x", 2);
			if (fla['P'] > len)
				ft_putnchar('0', fla['P'] - len);
		}
		pf_putnbr_base(unbr, b, fla);
	}
	return (0);
}

void		dispatch(t_env *var, unsigned char b)
{
	if (b == 'd' || b == 'i')
	{
		if (!is_bdi(var->fla, &var->conv.nbr, var->ap))
			exit(EXIT_FAILURE);
	}
	else
		if (!is_ouxX(var->fla, &var->conv.unbr, var->ap))
			exit(EXIT_FAILURE);
	if (var->fla['#'] && !var->fla['-'] && (b == 'x' || b == 'X'))
		hash(var->conv.unbr, b, var->fla);
	else if (var->fla['-'])
		dash(var->fla, var->conv, b);
	else
		other(var->fla, var->conv, b);
}
