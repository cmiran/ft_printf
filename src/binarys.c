/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:08:41 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/07 18:54:20 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	pf_putbin(size_t *fla, long long nbr, unsigned char len, size_t *ret)
{
	unsigned char	k;

	if (fla['0'])
		len = 32;
	else if (fla['#'] || nbr < 0)
	{
		len % 4 == 0 ? len += 1 : len;
		while (len)
		{
			if (len % 4 == 0)
				break ;
			len++;
		}
	}
	*ret += len;
	while (len--)
	{
		k = nbr >> len;
		k & 1 ? write(1, "1", 1) : write(1, "0", 1);
		if (fla['#'] && len % 4 == 0 && len != 0)
		{
			write(1, " ", 1);
			(*ret)++;
		}
	}
}

void	other_4bin(size_t *fla, long long nbr, unsigned char len, size_t *ret)
{
	if (!fla['.'])
	{
		if (fla['W'] && !fla['#'])
			pf_putnchar(' ', fla['W'] -\
			(len + fla['P'] <= 32 ? len + fla['P'] : len), ret);
	}
	else if (fla['P'] > len && fla['P'] + len < 32)
		pf_putbin(fla, nbr, fla['P'], ret);
	else
	{
		pf_putbin(fla, nbr, len, ret);
		fla['P'] + len < 32 ? pf_putnchar(' ', fla['W'] - fla['P'] - len, ret) :\
			pf_putnchar(' ', fla['W'] - len, ret);
		return ;
	}
	pf_putbin(fla, nbr, len, ret);
}

void	dash_4bin(size_t *fla, long long nbr, unsigned char len, size_t *ret)
{
	if (fla['P'] > len && fla['P'] + len <= 32)
 		pf_putbin(fla, nbr, fla['P'], ret);
	else
		pf_putbin(fla, nbr, len, ret);
	if (!fla['#'])
		fla['P'] + len < 32 ? pf_putnchar(' ', fla['W'] - len, ret) :\
			pf_putnchar(' ', fla['W'] + fla['P'], ret);
}

void	binarys(t_env *var, unsigned char b)
{
	unsigned char	len;

	if (b == 'b')
		if (!is_bdi(var->fla, &var->conv.nbr, var->ap, b))
			exit(EXIT_FAILURE);
	len = pf_nbrlen(var->conv.nbr, 'b');
	if (var->conv.nbr < 0)
		len -= 1;
	if (var->fla['-'])
		dash_4bin(var->fla, var->conv.nbr, len, &var->ret);
	else
		other_4bin(var->fla, var->conv.nbr, len, &var->ret);
}
