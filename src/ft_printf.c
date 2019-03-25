/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:05:30 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/25 18:45:26 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	%[flag][width][.precision][size-flag]type
*/

#include "../inc/ft_printf.h"

size_t		*check_sizeflag(const char *format, size_t *fla, size_t *i)
{
	if (format[*i] == 'h')
		fla[91] = (format[*i + 1] == 'h') ? (*i)++ : fla['h']++;
	else if (format[*i] == 'l')
		fla[93] = (format[*i + 1] == 'l') ? (*i)++ : fla['l']++;
	else
		fla['L'] = 1;
	return (fla);
}

unsigned int	set_format(t_printf *var, const char *format)
{
	ft_bzero(var->fla, 127);
	while (format[var->i++])
	{
		if (pf_strchr("#0-+ ", format[var->i]))
			var->fla[pf_strchr("#0-+ ", format[var->i])] = 1;
		else if ((!var->fla['W']) && ft_isdigit(format[var->i]))
		{	
			var->fla['W'] = pf_atoi(format, var->i);
			var->i += ft_nbrlen(var->fla['W']) - 1;
			var->ret += var->fla['W'];/* 
**								?? a checker avec test
**								width idem pour la
**								precision.
*/
		}
		else if (format[var->i] == '.')
		{
			var->fla['P'] = pf_atoi(format, var->i + 1);
			var->i += ft_nbrlen(var->fla['.']);
		}/* 
**									^^^
*/
		else if (format[var->i] == 'h' || format[var->i] == 'l'\
				|| format[var->i] == 'L')
			*(var->fla) = *check_sizeflag(format, var->fla, &var->i);
		else
			break ;
	}
	return (pf_strchr("diouxXfpn", format[var->i]));
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
