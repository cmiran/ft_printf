/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:05:30 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/18 22:28:24 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	%[flag][width][.precision][size_flag]type
*/

#include "../inc/ft_printf.h"

int	check_conversion(t_printf *var, const char *format)
{
	format[var->i] == 'c' ? var->conv[0] = 1 : 0;
	format[var->i] == 's' ? var->conv[1] = 1 : 0;
	format[var->i] == 'p' ? var->conv[2] = 1 : 0;
	format[var->i] == 'd' ? is_di(var) : 0;
	format[var->i] == 'i' ? var->conv[4] = 1 : 0;
	format[var->i] == 'o' ? var->conv[5] = 1 : 0;
	format[var->i] == 'u' ? var->conv[6] = 1 : 0;
	format[var->i] == 'x' ? var->conv[7] = 1 : 0;
	format[var->i] == 'X' ? var->conv[8] = 1 : 0;
	format[var->i] == 'f' ? var->conv[9] = 1 : 0;
	format[var->i] == 'p' ? var->conv[10] = 1 : 0;
	format[var->i] == 'n' ? var->conv[11] = 1 : exit(EXIT_FAILURE);
	return (1);
}

void	check_sizeflag(const char *format, size_t i, size_t *fla)
{
	if (format[i] == 'h' && format[i + 1] == 'h')
	{
		fla[7] = 1;
		i++;
	}
	else if (format[i] == 'h' && format[i + 1] != 'h')
		fla[8] = 1;
	else if (format[i] == 'l' && format[i + 1] == 'l')
	{
		fla[9] = 1;
		i++;
	}
	else if (format[i] == 'l' && format[i + 1] != 'l')
		fla[10] = 1;
}

void	check_flag(const char *format, size_t i, size_t *fla)
{
	if (format[i] == '#')
		fla[0] = 1;
	else if (format[i] == '0')
		fla[1] = 1;
	else if (format[i] == '-')
		fla[2] = 1;
	else if (format[i] == '+')
		fla[3] = 1;
	else if (format[i] == ' ')
		fla[4] = 1;
}

void	set_format(t_printf *var, const char *format)
{
	ft_bzero(var->fla, 11);
	ft_bzero(var->conv, 12);
	while (format[var->i++])
	{
		if (format[var->i] == '#' || format[var->i] == '0'\
				|| format[var->i] == '-' || format[var->i] == '+'\
				|| format[var->i] == ' ')
			check_flag(format, var->i, var->fla);
		else if (ft_isdigit(format[var->i]))
		{
				var->fla[5] = pf_atoi(format, var->i);
				var->ret += var->fla[5]; // ?? a checker avec test
							 // width idem pour la
							 // precision.
		}
		else if (format[var->i] == '.')
			var->fla[6] = pf_atoi(format, ++var->i);
		else if (format[var->i] == 'h' || format[var->i] == 'l')
			check_sizeflag(format, var->i, var->fla);
		else if (check_conversion(var, format))
			break;
	}
}

int	ft_printf(const char * restrict format, ...)
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
			format[var.i + 1] == '%' ?\
					   write(1, "%", 1) : set_format(&var, format);
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
