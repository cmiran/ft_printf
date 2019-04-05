/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:38:29 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/05 18:45:01 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Affiche n caracteres c sur la sortie standard.
*/ 

#include "../inc/ft_printf.h"

void	pf_putnchar(char c, unsigned long long i, size_t *ret)
{
	*ret += i;
	while (i--)
		write(1, &c, 1);
}
