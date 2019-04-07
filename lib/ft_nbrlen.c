/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:41:13 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/07 16:48:10 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

size_t	ft_nbrlen(ssize_t nbr)
{
	size_t	len;

	if (!nbr)
		return (0);
	len = 1;
	while (nbr /= 10)
		len++;
	return (len);
}
