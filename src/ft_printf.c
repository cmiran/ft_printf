/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:05:30 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/14 00:02:02 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	%[flag][width][.precision][size_flag]type
*/

#include "../inc/ft_printf.h"

int	pf_atoi(const char *format, size_t i)
{
	long	nb;

	while (ft_isdigit(format[i]))
	{
		nb = nb * 10 + format[i] - '0';
		i++;
//		if (!ft_isdigit(format[i]))
//			exit(EXIT_FAILURE);
	}
	return ((int)nb);
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
	while (format[var->i++])
	{
		if (format[var->i] == '%')
		{
			write(1, "%", 1);
			break;
		}
		if (format[var->i] == '#' || format[var->i] == '0'\
				|| format[var->i] == '-' || format[var->i] == '+'\
				|| format[var->i] == ' ')
			check_flag(format, var->i, var->fla);
		else if (ft_isdigit(format[var->i]))
		{
				var->fla[5] = pf_atoi(format, var->i);
				var->ret += var->fla[5]; // ?? a checker avec test
							 // width idem pour la
							 // precision
		}
		else if (format[var->i] == '.')
			var->fla[6] = pf_atoi(format, var->i + 1);
		else if (format[var->i] == 'h' || format[var->i] == 'l')
			check_sizeflag(format, var->i, var->fla);
	}
}

int	ft_printf(const char * restrict format, ...)
{
	va_list		ap;
	t_printf	var;

	if (!format)
		return (0);
	va_start(ap, format);
	var.i = 0;
	var.ret = 0;
	while (format[var.i])
	{
		if (format[var.i] == '%')
			set_format(&var, format);
		else
		{
			write (1, &format[var.i], 1);
			var.ret++;
		}
		var.i++;
	}
	va_end(ap);
	return (var.ret);
}
