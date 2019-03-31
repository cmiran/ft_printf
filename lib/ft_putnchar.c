/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:38:29 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/31 15:12:06 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Affiche n caracteres c sur la sortie standard.
*/ 

#include "../inc/ft_printf.h"

void	ft_putnchar(char c, size_t i)
{
	while (i--)
		write(1, &c, 1);
}
