/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putbin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:05:01 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/01 18:41:17 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	pf_putbin(size_t *fla, int32_t nbr, unsigned char len)
{
	unsigned char	k;

	if (fla['0'])
		len = 31;
	else if (fla['#'])
		while (len)
			if (len++ % 4 == 0)
				break ;
	while (len)
	{
		k = nbr >> len;
		if (k & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		if (fla['#'] && len % 4 == 0)
			write (1, " ", 1);
		--len;
	}
}
