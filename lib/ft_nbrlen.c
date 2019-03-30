/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 18:00:33 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/30 14:45:08 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

size_t	ft_nbrlen(ssize_t nbr)
{
	size_t	len;

	len = (nbr < 0) ? 2 : 1;
	while (nbr /= 10)
		len++;
	return (len);
}
