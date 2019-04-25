/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 22:51:31 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/25 17:24:31 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	is_csf(size_t *fla, t_conv *conv, va_list ap, char b)
{
	if (b == 'c')
		conv->c = (unsigned char)va_arg(ap, int);
	else if (b == 's')
		conv->s = va_arg(ap, char *);
	else
		fla['L'] ? conv->dnbr = va_arg(ap, long double) :\
			(conv->dnbr = va_arg(ap, double));
}

void	is_ouxp(size_t *fla, unsigned long long *unbr, va_list ap, char b)
{
	if (b == 'p')
		*unbr = va_arg(ap, uintptr_t);
	else if (fla[91])
		*unbr = (unsigned char)va_arg(ap, unsigned int);
	else if (fla['h'])
		*unbr = (unsigned short)va_arg(ap, unsigned int);
	else if (fla['l'])
		*unbr = (uintmax_t)va_arg(ap, unsigned long);
	else if (fla[93])
		*unbr = (uintmax_t)va_arg(ap, unsigned long long);
	else
		*unbr = va_arg(ap, unsigned int);
}

void	is_bdi(size_t *fla, long long *nbr, va_list ap, char b)
{
	if (fla[91])
		*nbr = (char)va_arg(ap, int);
	else if (fla['h'])
		*nbr = (short)va_arg(ap, int);
	else if (fla['l'])
		*nbr = (intmax_t)va_arg(ap, long);
	else if (fla[93] || b == 'b')
		*nbr = (intmax_t)va_arg(ap, long long);
	else
		*nbr = va_arg(ap, int);
}
