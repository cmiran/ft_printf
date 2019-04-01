/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putubin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:03:32 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/01 18:26:30 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	pf_putubin(size_t *fla, uint64_t nbr, unsigned char len)
{
	unsigned char	k;

	if (fla['0'])
		len = 64;
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
