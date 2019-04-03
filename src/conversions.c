/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 22:51:31 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/03 17:59:27 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*int	is_cs(size_t *fla, t_conv *conv, va_list ap)
{
	if (fla['l'] && (*lc = va_arg(ap, )))
		return (*unbr <= ULONG_MAX);

}*/

int	is_ouxX(size_t *fla, size_t *unbr, va_list ap)
{
	if (fla[91] && (*unbr = va_arg(ap, unsigned int)))
		return (*unbr <= UCHAR_MAX);
	else if (fla['h'] && (*unbr = va_arg(ap, unsigned int)))
		return (*unbr <= USHRT_MAX);
	else if (fla['l'] && (*unbr = va_arg(ap, unsigned long)))
		return (*unbr <= ULONG_MAX);
	else if (fla[93] && (*unbr = va_arg(ap, unsigned long long)))
		return (*unbr <= ULLONG_MAX);
	else
	{
		*unbr = va_arg(ap, unsigned int);
		return (*unbr <= UINT_MAX);
	}
	return (0);
}

int	is_bdi(size_t *fla, ssize_t *nbr, va_list ap)
{
	if (fla[91] && (*nbr = va_arg(ap, int)))
		return (*nbr >= SCHAR_MIN && *nbr <= SCHAR_MAX);
	else if (fla['h'] && (*nbr = va_arg(ap, int)))
		return (*nbr >= SHRT_MIN && *nbr <= SHRT_MAX);
	else if (fla['l'] && (*nbr = va_arg(ap, long)))
		return (*nbr >= LONG_MIN && *nbr <= LONG_MAX );
	else if (fla[93] && (*nbr = va_arg(ap, long long)))
		return (*nbr >= LLONG_MIN && *nbr <= LLONG_MAX);
	else
	{
		*nbr = va_arg(ap, int);
		return (*nbr >= INT_MIN && *nbr <= INT_MAX);
	}
	return (0);
}
