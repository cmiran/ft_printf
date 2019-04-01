/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:32:48 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/01 22:56:32 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

unsigned char	pf_nbrlen_base(unsigned long long unbr, char b)
{
	unsigned char	len;
	unsigned char	base;

	len = 1;
	base = get_base(b);
	while (unbr /= base)
		len++;
	return (len);
}
