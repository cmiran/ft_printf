/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:08:41 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/09 23:05:07 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	pf_putbin(size_t *fla, long long nbr)
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
			fla['N']++;
		}
	}
	fla['R'] += fla['N'];
	while (fla['N']--)
	{
		k = nbr >> fla['N'];
		k & 1 ? write(1, "1", 1) : write(1, "0", 1);
		write(1, " ", 1);
		fla['R']++;
		if (fla['#'] && fla['N'] % 4 == 0 && fla['N'] != 0)
		{
			write(1, " ", 1);
			fla['R']++;
		}
	}
}

void	other_4bin(size_t *fla, long long nbr)
{
	if (!fla['.'])
	{
		if (fla['W'] && !fla['#'])
			pf_putnchar(' ', fla['W'] -\
			(fla['N'] + fla['P'] <= 32 ? fla['N'] + fla['P'] : fla['N']), &fla['R']);
	}
	else if (fla['P'] > fla['N'] && fla['P'] + fla['N'] < 32)
		pf_putbin(fla, nbr);
	else
	{
		pf_putbin(fla, nbr);
		fla['P'] + fla['N'] < 32 ? pf_putnchar(' ', fla['W'] - fla['P'] - fla['N'], &fla['R']) :\
			pf_putnchar(' ', fla['W'] - fla['N'], &fla['R']);
		return ;
	}
	pf_putbin(fla, nbr);
}

void	dash_4bin(size_t *fla, long long nbr)
{
	if (fla['P'] > fla['N'] && fla['P'] + fla['N'] <= 32)
 		pf_putbin(&*fla, nbr);
	else
		pf_putbin(&*fla, nbr);
	if (!fla['#'])
		fla['P'] + fla['N'] < 32 ? pf_putnchar(' ', fla['W'] - fla['N'], &fla['R']) :\
			pf_putnchar(' ', fla['W'] + fla['P'], &fla['R']);
}

void	binarys(t_env *var, unsigned char b)
{
	if (b == 'b')
		if (!is_bdi(var->fla, &var->conv.nbr, var->ap, b))
			exit(EX_USAGE);
	var->fla['N'] = pf_nbrlen(var->conv.nbr, 'b');
	if (var->fla['-'])
		dash_4bin(&*var->fla, var->conv.nbr);
	else
		other_4bin(&*var->fla, var->conv.nbr);
}
