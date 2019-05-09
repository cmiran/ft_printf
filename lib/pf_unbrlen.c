/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_unbrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:32:48 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/09 18:14:32 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned char	pf_unbrlen(unsigned long long unbr, char b)
{
	unsigned char	len;
	unsigned char	base;

	len = 1;
	base = pf_getbase(b);
	while (unbr /= base)
		len++;
	return (len);
}
