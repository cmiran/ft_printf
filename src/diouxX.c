/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diouxX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:19:19 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/18 22:29:44 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	width_precision(t_printf *var, int nb)
{
/*	int	i;
	char	*str;

	if (!(var->buf = ft_strnew(var->fla[5] + var->fla[6] + ft_nbrlen(nb))))
		exit(EXIT_FAILURE);
	i = 0;
	if (var->fla[2])
	{
		str = ft_itoa(nb);
		while (*str)
			var->buf[i++] = *str++;
		free(str);
	}*/
}

void	is_di(t_printf *var)
{
	int	nb;

	nb = va_arg(var->ap, int);
	if (var->fla[2])
	{
		var->fla[3] || var->fla[4] ?\
			(nb > 0 ? write(1, "+", 1) : write(1, "-", 1)) :\
			(nb > 0 ? write(1, " ", 1) : write(1, "-", 1));
		var->fla[6] > ft_nbrlen(nb) ? write(1, "0", (var->fla[6] - ft_nbrlen(nb))) :\
					ft_putnbr(nb);
		if (var->fla[5] > var->fla[6])
			if ((var->fla[5] - var->fla[6] - ft_nbrlen(nb)) > 0)
			 	write(1, " ", (var->fla[5] - var->fla[6] - ft_nbrlen(nb)));
	}
	else if (var->fla[1])
		(var->fla[5] || var->fla[6]) ? width_precision(var, nb) : ft_putnbr(nb);
}
