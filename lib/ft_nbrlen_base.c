/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:15:41 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/01 11:31:25 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

unsigned char	ft_nbrlen_base(unsigned long long unbr, size_t base)
{
	static unsigned char	i;

	if (unbr < base)
		i += 1;
	else
	{
		ft_nbrlen_base(unbr / base, base);
		ft_nbrlen_base(unbr % base, base);
	}
	return (i);
}
