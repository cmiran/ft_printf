/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 22:20:57 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/31 15:12:10 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>


typedef struct s_conversion
{
	ssize_t	nbr;
	size_t	unbr;
}		t_conv;

typedef struct s_printf_environment
{
	va_list		ap;
	size_t		i;
	size_t		ret;
	size_t		fla[128];
/*
**	fla['hh'] = fla[91]
**	fla['ll'] = fla[93]
*/
	t_conv		conv;
}		t_env;


/*
**	src/ft_printf.c
*/
int	ft_printf(const char * restrict format, ...);
/*
** int		parse(size_t *fla, size_t *i, const char *format);
** size_t	*check_sizeflag(const char *format, size_t *i, size_t *fla);
** void		pf_bzero(size_t *fla, size_t len, t_conv *conv);
*/

/*
**	src/conversions.c
*/
int	is_di(size_t *fla, ssize_t *nbr, va_list ap);
int	is_ouxX(size_t *fla, size_t *unbr, va_list ap);

/*
** 	src/numbers.c
*/
void	dispatch(t_env *var, char i);
/*
** void		dash(size_t *fla, long long nbr, ssize_t len);
** void		zer0(size_t *fla, long long nbr, ssize_t len);
** void		sign(size_t *fla, long long nbr);
*/


/*
**		lib/   by apparition order
*/
//void			ft_bzero(size_t *fla, size_t n);
int		ft_isdigit(int c);
size_t		pf_atoi(const char *format, size_t i);
size_t		ft_nbrlen(ssize_t nbr);
unsigned char	pf_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
size_t		pf_nbrlen(long long nbr, char c);
size_t		pf_unbrlen(unsigned long long unbr, char c);
unsigned char	get_base(char c);
void		pf_putnbr(ssize_t nbr);
void		pf_putnbr_base(size_t u_nbr, char c, size_t *fla);
void		ft_putchar(char c);
void		ft_putnchar(char c, size_t i);
int		ft_isspace(int c);
int		ft_isupper(int c);

int	main(void);
void	*ft_print_memory(void const *addr, size_t size);
int	ft_isprint(int c);
#endif
