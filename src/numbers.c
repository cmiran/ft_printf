/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:19:19 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/13 22:14:54 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		sign(size_t *fla, long long nbr, unsigned char b)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		++fla['R'];
	}
	else if (fla['+'] && !pf_strchr("ouxX", b))
	{
		nbr < 0 ? write(1, "-", 1) : write(1, "+", 1);
		++fla['R'];
	}
	else if (fla[' '] && !fla['+'] && !pf_strchr("ouxX", b))
	{
		nbr < 0 ? write(1, "-", 1) : write(1, " ", 1);
		++fla['R'];
	}
}

void		other(size_t *fla, t_conv conv, unsigned char b)
{
	if (!fla['.'])
	{
		if (fla['0'])
			sign(&*fla, conv.nbr, b);
		pf_putnchar(fla['0'] ? '0' : ' ', fla['W'] - fla['N']\
				- ((fla['+'] || fla[' '] || conv.nbr < 0)\
					 && !pf_strchr("ouxX", b) ? 1 : 0)\
				- (fla['#'] && b == 'o' && conv.unbr ? 1 : 0), &fla['R']);
		if (!fla['0'])
			sign(&*fla, conv.nbr, b);
	}
	else
	{
		pf_putnchar(' ', fla['W'] - (fla['N'] > fla['P'] ? fla['N'] : fla['P'])\
				- ((fla['+'] || fla[' '] || conv.nbr < 0)\
				 	&& !pf_strchr("ouxX", b) ? 1 : 0)\
				- (fla['#'] && b == 'o' && !fla['P'] ? 1 : 0), &fla['R']);
		sign(&*fla, conv.nbr, b);
		pf_putnchar('0', fla['P'] - fla['N'], &fla['R']);
	}
	if (b == 'd' || b == 'i')
		fla['.'] && conv.nbr == 0 ? 0 : pf_putnbr(conv.nbr, &*fla);
	else if (fla['#'] && b == 'o' && conv.unbr == 0)
		hash(fla, conv.unbr, b);
	else
		fla['.'] && conv.unbr == 0 ? 0 : pf_putnbr_base(conv.unbr, b, &*fla);
}

void		dash(size_t *fla, t_conv conv, unsigned char b)
{
	if (fla['#'] && (b == 'x' || b == 'X') && conv.unbr > 0)
	{
		b == 'x' ? write(1, "0x", 2) : write(1, "0X", 2);
		fla['R'] += 2;
	}
	else
		sign(&*fla, conv.nbr, b);
	if (fla['P'] > fla['N'])
		pf_putnchar('0', fla['P'] - fla['N'], &fla['R']);
	if (b == 'd' || b == 'i')
		fla['.'] && conv.nbr == 0 ? 0 : pf_putnbr(conv.nbr, &*fla);
	else if (b == 'o' && conv.unbr == 0 && fla['#'])
		hash(fla, conv.unbr, b);
	else
		fla['.'] && conv.unbr == 0 ? 0 : pf_putnbr_base(conv.unbr, b, &*fla);
	pf_putnchar(' ', fla['W'] - (fla['N'] > fla['P'] ? fla['N'] : fla['P'])\
			- ((fla['+'] || fla[' '] || conv.nbr < 0)\
			 	&& !pf_strchr("ouxX", b) ? 1 : 0)\
			- (fla['#'] && (b == 'o') && !fla['P'] ? 1 : 0)\
			- (fla['#'] && (b == 'x' || b == 'X')\
				&& conv.unbr > 0 ? 2 : 0), &fla['R']);
}

unsigned int	hash(size_t *fla, unsigned long long unbr, unsigned char b)
{
	if (b == 'o')
		pf_putnchar('0', 1 - (fla['P'] > fla['N'] ? 1 : 0), &fla['R']);
	else
	{
		if (!fla['P'])
		{
			if (fla['0'])
				ft_isupper(b) ? write(1, "0X", 2) : write(1, "0x", 2);
			pf_putnchar(fla['0'] ? '0' : ' ', fla['W'] - fla['N'] - 2, &fla['R']);
			if (!fla['0'])
				ft_isupper(b) ? write(1, "0X", 2) : write(1, "0x", 2);
		}
		else
		{
			pf_putnchar(' ', fla['W'] -\
					(fla['N'] > fla['P'] ? fla['N'] + 2 : fla['P'] + 2), &fla['R']);
			ft_isupper(b) ? write(1, "0X", 2) : write(1, "0x", 2);
			pf_putnchar('0', fla['P'] - fla['N'], &fla['R']);
		}
		fla['.'] && unbr == 0 ? 0 : pf_putnbr_base(unbr, b, &*fla);
	}
	return (0);
}

void		numbers(t_env *var, unsigned char b)
{
	if (b == 'd' || b == 'i')
	{
		if (!is_bdi(var->fla, &var->conv.nbr, var->ap, b))
			exit(EX_USAGE);
	}
	else
	{
		if (!is_ouxX(var->fla, &var->conv.unbr, var->ap))
			exit(EX_USAGE);
	}
	var->fla['N'] = (b == 'd' || b == 'i') ? pf_nbrlen(var->conv.nbr, b) :\
		pf_unbrlen(var->conv.unbr, b);
	if (var->fla['.'] && var->conv.nbr == 0 && var->conv.unbr == 0)
		var->fla['N']--;
	if (var->fla['#'] && !var->fla['-'] && (b == 'x' || b == 'X') && var->conv.unbr > 0)
	{
		var->fla['R'] += 2;
		hash(&*var->fla, var->conv.unbr, b);
	}
	else if (var->fla['-'])
		dash(&*var->fla, var->conv, b);
	else
		other(&*var->fla, var->conv, b);
}
