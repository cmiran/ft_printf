/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:20:08 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/13 22:02:53 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	characters(t_env *var, unsigned char b)
{
	
}

void	strings(t_env *var, unsigned char b)
{
	if (b == 'c')
	{
		is_csp(var->fla, &var->conv, var->ap, b);
		
	}
	else if (b == 's')
	
}
