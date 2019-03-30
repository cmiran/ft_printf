/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_unbrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:10:16 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/30 16:19:59 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

size_t	pf_unbrlen(unsigned long long unbr, char c)
{
	size_t		len;
	unsigned char	base;

	len = 1;
	base = get_base(c);
	while (unbr /= base)
		len++;
	return (len);
}
