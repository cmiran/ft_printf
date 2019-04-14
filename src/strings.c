/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:20:08 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/14 19:13:16 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	other_4str(size_t *fla, t_conv conv, unsigned char b)
{
	if (b == 'c')
	{
		pf_putnchar(fla['0'] ? '0' : ' ', fla['W'] - 1, &fla['R']);
		write(1, &conv.c, 1);
	}
	else
	{

	}
}

void	dash_4str(size_t *fla, t_conv conv,  unsigned char b)
{
	if (b == 'c')
	{
		write(1, &conv.c, 1);
		pf_putnchar(' ', fla['W'] - 1, &fla['R']);
	}
	else
	{
		
	}
}

void	strings(t_env *var, unsigned char b)
{
	if (b == 'c' || b == 's')
	{
		is_cs(&var->conv, var->ap, b);
		b == 's' ? var->fla['N'] = ft_strlen(var->conv.s) : 0;
	}
	if (var->fla['-'])
		dash_4str(&*var->fla, var->conv, b);
	else
		other_4str(&*var->fla, var->conv, b);
}
