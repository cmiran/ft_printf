/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:20:08 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/20 21:14:39 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	other_4str(size_t *fla, t_conv conv, unsigned char b, size_t *r)
{
	if (b == 'c')
	{
		pf_putnchar(fla['0'] ? '0' : ' ', fla['W'] - 1, r);
		write(1, &conv.c, 1);
		*r += 1;
	}
	else
	{
		pf_putnchar(fla['0'] ? '0' : ' ', fla['W']\
				- (fla['P'] && fla['N'] > fla['P'] ? fla['P'] : fla['N'])\
				, r);
		pf_putnstr(conv.s, (fla['.'] && fla['P'] < fla['N']) ? fla['P'] : fla['N'], r);
	}
}

void	dash_4str(size_t *fla, t_conv conv,  unsigned char b, size_t *r)
{
	if (b == 'c')
	{
		write(1, &conv.c, 1);
		pf_putnchar(' ', fla['W'] - 1, r);
		*r += 1;
	}
	else
	{	
		pf_putnstr(conv.s, (fla['.'] && fla['P'] < fla['N']) ? fla['P'] : fla['N'], r);
		pf_putnchar(' ', fla['W']\
				- (fla['P'] && fla['N'] > fla['P'] ? fla['P'] : fla['N'])\
				, r);
	}
}

void	strings(t_env *var, unsigned char b)
{
	is_csf(var->fla, &var->conv, var->ap, b);
	b == 's' && var->conv.s ? var->fla['N'] = ft_strlen(var->conv.s) :\
		(var->conv.s = "(null)") && (var->fla['N'] = ft_strlen(var->conv.s));
	var->fla['-'] ? dash_4str(&*var->fla, var->conv, b, &var->r) :\
		other_4str(&*var->fla, var->conv, b, &var->r);
}
