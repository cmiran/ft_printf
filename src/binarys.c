/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:08:41 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/16 19:01:26 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	pf_putbin(size_t *fla, long long nbr, size_t *r)
{
	unsigned char	k;

	if (fla['0'])
		fla['N'] = 32;
	else if (fla['#'] || nbr < 0)
	{
		fla['N'] % 4 == 0 ? fla['N'] += 1 : fla['N'];
		while (fla['N'])
		{
			if (fla['N'] % 4 == 0)
				break ;
			++fla['N'];
		}
	}
	*r += fla['N'];
	while (fla['N']--)
	{
		k = nbr >> fla['N'];
		k & 1 ? write(1, "1", 1) : write(1, "0", 1);
		++*r;
		if (fla['#'] && fla['N'] % 4 == 0 && fla['N'] != 0)
		{
			write(1, " ", 1);
			++*r;
		}
	}
}

void	other_4bin(size_t *fla, long long nbr, size_t *r)
{
	if (!fla['.'])
	{
		if (fla['W'] && !fla['#'])
			pf_putnchar(' ', fla['W'] -\
			(fla['N'] + fla['P'] <= 32 ? fla['N'] + fla['P'] : fla['N']), r);
	}
	else if (fla['P'] > fla['N'] && fla['P'] + fla['N'] < 32)
		pf_putbin(&*fla, nbr, r);
	else
	{
		pf_putbin(&*fla, nbr, r);
		fla['P'] + fla['N'] < 32 ? pf_putnchar(' ', fla['W'] - fla['P'] - fla['N'], r) :\
			pf_putnchar(' ', fla['W'] - fla['N'], r);
		return ;
	}
	pf_putbin(fla, nbr, r);
}

void	dash_4bin(size_t *fla, long long nbr, size_t *r)
{
	if (fla['P'] > fla['N'] && fla['P'] + fla['N'] <= 32)
 		pf_putbin(&*fla, nbr, r);
	else
		pf_putbin(&*fla, nbr, r);
	if (!fla['#'])
		fla['P'] + fla['N'] < 32 ? pf_putnchar(' ', fla['W'] - fla['N'], r) :\
			pf_putnchar(' ', fla['W'] + fla['P'], r);
}

void	binarys(t_env *var, unsigned char b)
{
	if (b == 'b')
		if (!is_bdi(var->fla, &var->conv.nbr, var->ap, b))
			exit(EX_USAGE);
	var->fla['N'] = pf_nbrlen((int)var->conv.nbr, 'b');
	if (var->fla['-'])
		dash_4bin(&*var->fla, var->conv.nbr, &var->r);
	else
		other_4bin(&*var->fla, var->conv.nbr, &var->r);
}
