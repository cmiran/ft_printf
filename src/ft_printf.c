/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:05:30 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/27 00:51:14 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	%[flag][width][.precision][size-flag]type
*/

#include "../inc/ft_printf.h"

size_t	*check_sizeflag(const char *format, size_t *i, size_t *fla)
{
	if (format[*i] == 'h')
		fla[91] = (format[*i + 1] == 'h') ? ++*i : ++fla['h'];
	else if (format[*i] == 'l')
		fla[93] = (format[*i + 1] == 'l') ? ++*i : ++fla['l'];
	else
		++fla['L'];
	return (fla);
}

int	parse(const char *format, size_t *i, size_t *fla)
{
	ft_bzero(fla, 127);
	while (format[++*i])
	{
		if (pf_strchr("#0-+ ", format[*i]))
			++fla[pf_strchr("#0-+ ", format[*i])];
		else if (ft_isdigit(format[*i]))
		{
			fla['W'] = pf_atoi(format, *i);
			*i += ft_nbrlen(fla['W']) - 1;/*
**			var->ret += var->fla['W'];
**								?? a checker avec test
**								width idem pour la
**								precision.
*/
		}
		else if (format[*i] == '.')
		{
			fla['P'] = pf_atoi(format, *i + 1);
			*i += ft_nbrlen(fla['P']);
		}/* 
**								^^^
*/
		else if (pf_strchr("Lhl", format[*i]))
		{
			*fla = *check_sizeflag(format, &*i, fla);
			++*i;
			break ;
		}
		else
			break ;
	}
	return (pf_strchr("diouxXfpn", format[*i]));
}

int	ft_printf(const char *format, ...)
{
	t_env	var;

	if (!format)
		return (0);
	va_start(var.ap, format);
	var.i = 0;
	var.ret = 0;
	while (format[var.i])
	{
		if (format[var.i] == '%')
		{
			if (format[var.i + 1] == '%')
				write(1, &format[var.i++], 1);
			else
				!parse(format, &var.i, &*var.fla) ? exit(EXIT_FAILURE) : dispatch(&var);/*
**				pointeur sur fonction stuff
**				(*f[(int)ft_strchr("diouxXfpn")])(fomat[var.i], var);
*/
		}
		else
		{
			write(1, &format[var.i], 1);
			++var.ret;
		}
		++var.i;
	}
	va_end(var.ap);
	return (var.ret);
}
