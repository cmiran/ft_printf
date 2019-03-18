/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 22:20:57 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/18 21:24:04 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_printf
{
	va_list	ap;	
	size_t	i;
	size_t	ret;
	size_t	fla[11];
/*
**	| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
**	| # | 0 | - | + |   |wid|pre| hh| h | ll|  l |
*/
	size_t	conv[12];
/*
**	| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 |
**	| c | s | p | d | i | o | u | x | X | f |  b |  n |
*/
	char	*buf;
}		t_printf;

/*
**		src/ft_printf.c
*/
int	ft_printf(const char * restrict format, ...);
/*
** void	set_format(t_printf *var, const char *format);
** void	check_flag(const char *format, size_t i, size_t *fla);
** void	check_sizeflag(const char *format, size_t i, size_t *fla);
** int	check_conversion(const char *format, size_t i, size_t *conv);
*/

/*
** 		src/diouxX.c
*/
void	is_di(t_printf *var, int nb);

/*
**		lib/
*/
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int	ft_isdigit(int c);
int	pf_atoi(const char *format, size_t i);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
char	*ft_itoa(int nb);
	size_t	ft_nbrlen(int nb);
char	*ft_strnew(size_t size);
int	main(void);
#endif
