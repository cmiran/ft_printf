/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:05:30 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/22 18:06:19 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	%[flag][width][.precision][size-flag]type
*/

#include "../inc/ft_printf.h"

void		check_sizeflag(const char *format, size_t i, size_t *fla)
{
	if (format[i] == 'h')
		(fla[91] = (format[i + 1] == 'h')) ? i++ : fla['h']++;
	else if (format[i] == 'l')
		(fla[93] = (format[i + 1] == 'l')) ? i++ : fla['l']++;
	else
		fla['L'] = 1;
}

unsigned int	set_format(t_printf *var, const char *format)
{
	ft_bzero(var->fla, 127);
	while (format[var->i++])
	{
		if (ft_strchr("#0-+ ", format[var->i]))
			var->fla[(int)ft_strchr("#0-+ ", format[var->i])] = 1;
		else if (ft_isdigit(format[var->i]))
		{
				var->fla['W'] = pf_atoi(format, var->i);
				var->ret += var->fla['W'];/* 
**								?? a checker avec test
**								width idem pour la
**								precision.
*/
		}
		else if (format[var->i] == '.')
			var->fla['P'] = pf_atoi(format, ++var->i);/* 
**									^^^
*/
		else if (format[var->i] == 'h' || format[var->i] == 'l'\
				|| format[var->i] == 'L')
			check_sizeflag(format, var->i, var->fla);
		else
			break ;
	}
	return (ft_strchr("diouxXfpn", format[var->i]) ? 1 : 0);
}

int		ft_printf(const char *format, ...)
{
	t_printf	var;

	if (!format)
		return (0);
	va_start(var.ap, format);
	var.i = 0;
	var.ret = 0;
	while (format[var.i])
	{
		if (format[var.i] == '%')
		{
			format[var.i + 1] == '%' ?\
					   write(1, &format[var.i++], 1) :\
					   (!set_format(&var, format) ?\
					    	exit(EXIT_FAILURE) : is_di(&var));/*
**				pointeur sur fonction stuff
**				(*f[(int)ft_strchr("diouxXfpn")])(fomat[var.i], var);
*/
		}
		else
		{
			write(1, &format[var.i], 1);
			var.ret++;
		}
		var.i++;
	}
	va_end(var.ap);
	return (var.ret);
}
