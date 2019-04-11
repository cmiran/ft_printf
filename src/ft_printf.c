/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:05:30 by cmiran            #+#    #+#             */
/*   Updated: 2019/04/11 17:55:28 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	%[flag][width][.precision][size-flag]conversion-specifier
*/

#include "../inc/ft_printf.h"

void	check_sizeflag(const char *format, size_t *i, size_t *fla)
{
	if (format[*i] == 'h')
		fla[91] = (format[*i + 1] == 'h') ? ++*i : ++fla['h'];
	else if (format[*i] == 'l')
		fla[93] = (format[*i + 1] == 'l') ? ++*i : ++fla['l'];
	else
		++fla['L'];
}

int	parse(const char *format, size_t *i, size_t *fla)
{
	while (format[++*i])
	{
		if (pf_strchr("#0-+ ", format[*i]))
			++fla[pf_strchr("#0-+ ", format[*i])];
		else if (ft_isdigit(format[*i]) && !fla['W'])
		{
			fla['W'] = pf_atoi(format, *i);
			*i += ft_nbrlen(fla['W']) - 1;
		}
		else if (format[*i] == '.' && !fla['.'])
		{
			++fla['.'];
			fla['P'] = pf_atoi(format, *i + 1);
			*i += ft_nbrlen(fla['P']);
		}
		else if (pf_strchr("Lhl", format[*i]))
		{
			check_sizeflag(format, i, fla);
			++*i;
			break ;
		}
		else
			break ;
	}
	return (pf_strchr("cspdiouxXfbn", format[*i]));
}

void	pf_bzero(size_t *fla, size_t len, t_conv *conv)
{
	while (len--)
		*fla++ = 0;
	conv->nbr = 0;
	conv->unbr = 0;
	conv->dnbr = 0.0;
}


void	init_env(t_env *var, t_fptr *f)
{
	var->i = 0;
//	f['c'] = &
//	f['s'] = &
//	f['p'] = &;
	f['d'] = &numbers;
	f['i'] = &numbers;
	f['o'] = &numbers;
	f['u'] = &numbers;
	f['x'] = &numbers;
	f['X'] = &numbers;
	f['f'] = &floats;
	f['b'] = &binarys;
//	f['n'] = &;
}

int	ft_printf(const char *format, ...)
{
	t_env	var;
	t_fptr	f[128];

	va_start(var.ap, format);
	init_env(&var, &*f);
	while (format[var.i])
	{
		if (format[var.i] == '%')
		{
			if (format[var.i + 1] == '%')
				write(1, &format[var.i++], 1);
			else
			{
				pf_bzero(&*var.fla, 127, &var.conv);
				!parse(format, &var.i, &*var.fla) ? exit(EX_USAGE) :\
					f[pf_strchr("cspdiouxXfbn", format[var.i])](&var, format[var.i]);
			}
		}
		else
		{
			write(1, &format[var.i], 1);
			var.fla['R']++;
		}
		++var.i;
	}
	va_end(var.ap);
	return (var.fla['R']);
}
