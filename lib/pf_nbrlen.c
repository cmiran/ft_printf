/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 18:00:33 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/05 18:42:43 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

size_t		pf_nbrlen(long long nbr, char b)
{
	size_t		len;
	unsigned char	base;

	len = (nbr < 0) ? 2 : 1;
	base = get_base(b);
	while (nbr /= base)
		len++;
	return (len);
}
