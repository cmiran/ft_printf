/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:19:19 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/25 18:05:30 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		sign(size_t *fla, long long nbr, unsigned char b, size_t *r)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		++*r;
	}
	else if (fla['+'] && !pf_strchr("ouxX", b))
	{
		nbr < 0 ? write(1, "-", 1) : write(1, "+", 1);
		++*r;
	}
	else if (fla[' '] && !fla['+'] && !pf_strchr("ouxX", b))
	{
		nbr < 0 ? write(1, "-", 1) : write(1, " ", 1);
		++*r;
	}
}

void		other(size_t *fla, t_conv conv, unsigned char b, size_t *r)
{
	if (!fla['.'])
	{
		if (fla['0'])
			sign(&*fla, conv.nbr, b, r);
		pf_putnchar(fla['0'] ? '0' : ' ', fla['W'] - fla['N']\
				- ((fla['+'] || fla[' '] || conv.nbr < 0)\
					 && !pf_strchr("ouxX", b) ? 1 : 0)\
				- (fla['#'] && b == 'o' && conv.unbr ? 1 : 0), r);
		if (!fla['0'])
			sign(&*fla, conv.nbr, b, r);
	}
	else
	{
		pf_putnchar(' ', fla['W'] - (fla['N'] > fla['P'] ? fla['N'] : fla['P'])\
				- ((fla['+'] || fla[' '] || conv.nbr < 0)\
				 	&& !pf_strchr("ouxX", b) ? 1 : 0)\
				- (fla['#'] && b == 'o' && fla['P'] <= fla['N'] ? 1 : 0), r);
		sign(&*fla, conv.nbr, b, r);
		pf_putnchar('0', fla['P'] - fla['N'], r);
	}
	if (b == 'd' || b == 'i')
		fla['.'] && conv.nbr == 0 ? 0 : pf_putnbr(conv.nbr, r);
	else if (fla['#'] && b == 'o' && conv.unbr == 0)
		hash(fla, conv.unbr, b, r);
	else
		fla['.'] && conv.unbr == 0 ? 0 : pf_putnbr_base(conv.unbr, b, &*fla, r);
}

void		dash(size_t *fla, t_conv conv, unsigned char b, size_t *r)
{
	if ((fla['#'] && (b == 'x' || b == 'X') && conv.unbr > 0) || b == 'p')
	{
		ft_isupper(b) ? write(1, "0X", 2) : write(1, "0x", 2);
		*r += 2;
	}
	else
		sign(&*fla, conv.nbr, b, r);
	if (fla['P'] > fla['N'])
		pf_putnchar('0', fla['P'] - fla['N'], r);
	if (b == 'd' || b == 'i')
		fla['.'] && conv.nbr == 0 ? 0 : pf_putnbr(conv.nbr, r);
	else if (b == 'o' && conv.unbr == 0 && fla['#'])
		hash(fla, conv.unbr, b, r);
	else
		fla['.'] && conv.unbr == 0 ? 0 : pf_putnbr_base(conv.unbr, b, &*fla, r);
	pf_putnchar(' ', fla['W'] - (fla['N'] > fla['P'] ? fla['N'] : fla['P'])\
			- ((fla['+'] || fla[' '] || conv.nbr < 0)\
			 	&& !pf_strchr("ouxX", b) ? 1 : 0)\
			- ((fla['H'] || fla['#']) && b == 'o'\
/*
**				 ^ '#' marker initialized in pf_putnbr_base.c
*/
				&& ((conv.unbr && !fla['P'])\
					|| (fla['.'] && fla['P'] <= fla['N'])) ? 1 : 0)\
			- ((fla['#'] && (b == 'x' || b == 'X')\
				&& conv.unbr) || b == 'p' ? 2 : 0), r);
}

unsigned int	hash(size_t *fla, unsigned long long unbr, unsigned char b, size_t *r)
{
	if (b == 'o')
		pf_putnchar('0', 1 - (fla['P'] > fla['N'] ? 1 : 0), r);
	else
	{
		if (!fla['.'])
		{
			if (fla['0'])
				ft_isupper(b) ? write(1, "0X", 2) : write(1, "0x", 2);
			pf_putnchar(fla['0'] ? '0' : ' ', fla['W'] - fla['N'] - 2, r);
			if (!fla['0'])
				ft_isupper(b) ? write(1, "0X", 2) : write(1, "0x", 2);
		}
		else
		{
			pf_putnchar(' ', fla['W'] -\
					(fla['N'] > fla['P'] ? fla['N'] + 2 : fla['P'] + 2), r);
			ft_isupper(b) ? write(1, "0X", 2) : write(1, "0x", 2);
			pf_putnchar('0', fla['P'] - fla['N'], r);
		}
		fla['.'] && unbr == 0 ? 0 : pf_putnbr_base(unbr, b, &*fla, r);
		*r += 2;
	}
	return (0);
}

void		numbers(t_env *var, unsigned char b)
{
	(b == 'd' || b == 'i') ? is_bdi(var->fla, &var->conv.nbr, var->ap, b) :\
		(is_ouxp(var->fla, &var->conv.unbr, var->ap, b));
	var->fla['N'] = (b == 'd' || b == 'i') ? pf_nbrlen(var->conv.nbr, b) :\
		pf_unbrlen(var->conv.unbr, b);
	if (var->fla['.'] && var->conv.nbr == 0 && var->conv.unbr == 0)
		--var->fla['N'];
	if ((var->fla['#'] && !var->fla['-'] && (b == 'x' || b == 'X') && var->conv.unbr > 0)\
			|| (!var->fla['-'] && b == 'p'))
		hash(&*var->fla, var->conv.unbr, b, &var->r);
	else if (var->fla['-'])
		dash(&*var->fla, var->conv, b, &var->r);
	else
		other(&*var->fla, var->conv, b, &var->r);
}
