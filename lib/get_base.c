/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:45:47 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/01 17:48:10 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

unsigned char	get_base(char b)
{
	unsigned char	base;
	
	if (b == 'b')
		base = 2;
	else if (b == 'o')
		base = 8;
	else if (b == 'x' || b == 'X')
		base = 16;
	else
		base = 10;
	return (base);
}
