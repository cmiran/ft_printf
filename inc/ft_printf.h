/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 22:20:57 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/22 18:06:22 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

typedef struct s_printf
{
	va_list	ap;
	size_t	i;
	size_t	ret;
	size_t	fla[128];
/*
**	fla['hh'] = fla[91]
**	fla['ll'] = fla[93]
*/
}		t_printf;

/*
**		src/ft_printf.c
*/
int	ft_printf(const char * restrict format, ...);
/*
** int	set_format(t_printf *var, const char *format);
** void	check_sizeflag(const char *format, size_t i, size_t *fla);
*/

/*
** 		src/diouxX.c
*/
void	is_di(t_printf *var);
/*
** void	fl_dash(size_t *fla, long nb);
** void	fl_zer0(size_t *fla, long nb);
*/

/*
**		lib/
*/
void	ft_bzero(size_t *s, size_t n);
int	ft_isdigit(int c);
size_t	pf_atoi(const char *format, size_t i);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	pf_putnbr(int nb);
void	ft_putchar(char c);
void	ft_putnchar(char c, size_t i);
size_t	ft_nbrlen(int nb);
int	ft_isspace(int c);

int	main(void);
void	*ft_print_memory(void const *addr, size_t size);
int	ft_isprint(int c);
#endif
