/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putbin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:05:01 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/01 22:53:36 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	pf_putbin(size_t *fla, ssize_t nbr, unsigned char len)
{
	unsigned char	k;

	if (fla['0'])
		len = 32;
	else if (nbr < 0)
		len = pf_nbrlen(nbr, 'b');
	else if (fla['#'] || nbr < 0)
		while (len)
		{
			if (len % 4 == 0)
				break ;
			len++;
		}
	while (len--)
	{
		k = nbr >> len;
		if (k & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		if (fla['#'] && len % 4 == 0)
			write (1, " ", 1);
	}
}
