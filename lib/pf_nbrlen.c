/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 18:00:33 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/09 18:14:21 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t		pf_nbrlen(long long nbr, char b)
{
	size_t			len;
	unsigned char	base;

	len = 1;
	base = pf_getbase(b);
	while (nbr /= base)
		len++;
	return (len);
}
