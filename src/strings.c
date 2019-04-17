/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:20:08 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/17 16:55:32 by cmiran           ###   ########.fr       */
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
	else if (b == 's')
	{
		pf_putnchar(fla['0'] ? '0' : ' ', fla['W']\
				- (fla['P'] && fla['N'] > fla['P'] ? fla['P'] : fla['N'])\
				, r);
		pf_putnstr(conv.s, (fla['.'] && fla['P'] < fla['N']) ? fla['P'] : fla['N'], r);
	}
	else
	{
		write(1, "0x", 2);
		pf_putnbr_base(conv.unbr, b, fla, r);
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
	else if (b == 's')
	{	
		pf_putnstr(conv.s, (fla['.'] && fla['P'] < fla['N']) ? fla['P'] : fla['N'], r);
		pf_putnchar(' ', fla['W']\
				- (fla['P'] && fla['N'] > fla['P'] ? fla['P'] : fla['N'])\
				, r);
	}
	else
	{
		write(1, "0x", 2);
		pf_putnbr_base(conv.unbr, b, fla, r);
	}
}

void	strings(t_env *var, unsigned char b)
{
	if (b == 'c' || b == 's')
	{
		is_cs(&var->conv, var->ap, b);
		b == 's' && var->conv.s ? var->fla['N'] = ft_strlen(var->conv.s) :\
		   (var->conv.s = "(null)") && (var->fla['N'] = ft_strlen(var->conv.s));
	}
	if (var->fla['-'])
		dash_4str(&*var->fla, var->conv, b, &var->r);
	else
		other_4str(&*var->fla, var->conv, b, &var->r);
}
