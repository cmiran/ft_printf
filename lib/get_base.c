/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:45:47 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/30 15:46:06 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

unsigned char	get_base(char c)
{
	unsigned char	base;

	if (c == 'o')
		base = 8;
	else if (c == 'x' || c == 'X')
		base = 16;
	else
		base = 10;
	return (base);
}
