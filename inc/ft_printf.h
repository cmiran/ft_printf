/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 12:25:48 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/13 20:32:08 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_printf
{
	size_t	i;
	size_t	ret;
	size_t	fla[11];
}		t_printf;

int	ft_printf(const char * restrict format, ...);
void	set_arg(t_printf *arg, va_list ap, const char *format);
void	check_flag(const char *format, size_t i, size_t *fla);
int	pf_atoi(const char *format, size_t *i);
void	check_size_flag(const char *format, size_t i, size_t *fla);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int	ft_isdigit(int c);

int	main(void);
#endif
