/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diouxX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:19:19 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/19 18:58:31 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*void	width_precision(t_printf *var, int nbr)
{
	int	i;
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
	}
}*/

void	fl_zer0(size_t *fla, long long nbr)
{
	
}

void	fl_dash(size_t *fla, long long nbr)
{
	nbr < 0 ? write(1, "-", 1) : 0;
	if (fla[3] || fla[4])
		fla[4] ? (nbr > 0 ? write(1, " ", 1) : 0) :\
			(nbr > 0 ? write(1, "+", 1) : 0);
	if (fla[6] > ft_nbrlen(nbr))
		ft_putnchar('0', fla[6] - ft_nbrlen(nbr) +\
				(nbr < 0 ? 1 : 0));
	pf_putnbr(nbr);
	if ((int)fla[5] - (int)fla[6] > 0)
		ft_putnchar(' ', fla[5] - fla[6] -\
				(ft_nbrlen(nbr) > fla[6] ? ft_nbrlen(nbr) : 0) -\
				(fla[3] || fla[4] ? 1 : 0));
}

void	is_di(t_printf *var)
{
long long	nbr;

	nbr = va_arg(var->ap, int);
	if (var->fla[2])	/* flag '-' */
		fl_dash(var->fla, nbr);
	else if (var->fla[1])	/* flag '0' */
		fl_zer0(var->fla, nbr);
}
