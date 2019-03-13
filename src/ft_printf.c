/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:05:30 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/13 20:32:06 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
** 	| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
** 	| # | 0 | - | + |   |wid|pre| hh| h | ll|  l |
*/

//	%[flag][width][.precision][size_flag]type

int	pf_atoi(const char *format, size_t *i)
{
	long	nb;

	while (ft_isdigit(format[*i]))
	{
		nb = nb * 10 + format[*i] - '0';
		i++;
	}
	return ((int)nb);	
}

void	check_size_flag(const char *format, size_t i, size_t *fla)
{
	if (format[i] == 'h' && format[i + 1] == 'h')
		fla[7] = 1;
	else if (format[i] == 'h' && format[i + 1] != 'h')
		fla[8] = 1;
	else if (format[i] == 'l' && format[i + 1] == 'l')
		fla[9] = 1;
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

void	set_arg(t_printf *arg, va_list ap, const char *format)
{
	ft_bzero(arg->fla, 11);
	while (format[arg->i++])
	{
		if (format[arg->i] == '#' || format[arg->i] == '0'\
				|| format[arg->i] == '-' || format[arg->i] == '+'\
				|| format[arg->i] == ' ')
			check_flag(format, arg->i, &arg->fla);
		else if (ft_isdigit(format[arg->i]))
		{
				arg->fla[5] = pf_atoi(format, &arg->i);
				arg->ret += arg->fla[5]; // ?? a checker avec test width idem pour la precision
		}
		else if (format[arg->i] == '.')
			arg->fla[6] = pf_atoi(format, &arg->i + 1);
		else if (format[arg->i] == 'h' || format[arg->i] == 'l')
			check_size_flag(format, arg->i, &arg->fla);
	}
}

int	ft_printf(const char * restrict format, ...)
{
	va_list		ap;
	t_printf	arg;

	if (!format)
		return (0);
	va_start(ap, format);
	arg.i = 0;
	arg.ret = 0;
	while (format[arg.i])
	{
		if (format[arg.i] == '%')
			set_arg(&arg, ap, format);
		else
		{
			write (1, &format[arg.i], 1);
			arg.ret++;
		}
		arg.i++;
	}
	va_end(ap);
	return (arg.ret);
}
