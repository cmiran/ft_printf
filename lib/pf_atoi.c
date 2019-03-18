/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 00:19:43 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/18 15:48:54 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	pf_atoi(const char *format, size_t i)
{
	long	nb;

	while (ft_isdigit(format[i]))
	{
		nb = nb * 10 + format[i] - '0';
		i++;
	}
	return ((int)nb);
}
