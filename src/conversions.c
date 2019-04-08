/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 22:51:31 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/08 09:53:49 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*int	is_cs(size_t *fla, t_conv *conv, va_list ap)
{
	if (fla['l'] && (*lc = va_arg(ap, )))
		return (*unbr <= ULONG_MAX);

}*/

int	is_f(size_t l, long double *dnbr, va_list ap)
{
	if (l)
		*dnbr = va_arg(ap, long double);
	else
		*dnbr = va_arg(ap, double);
	return (1);
}

int	is_ouxX(size_t *fla, unsigned long long *unbr, va_list ap)
{
	if (fla[91])
		*unbr = (unsigned char)va_arg(ap, unsigned int);
	else if (fla['h'])
		*unbr = (unsigned short)va_arg(ap, unsigned int);
	else if (fla['l'])
		*unbr = va_arg(ap, unsigned long);
	else if (fla[93])
		*unbr = va_arg(ap, unsigned long long);
	else
		*unbr = va_arg(ap, unsigned int);
	return (1);
}

int	is_bdi(size_t *fla, long long *nbr, va_list ap, char b)
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
	return (1);
}
