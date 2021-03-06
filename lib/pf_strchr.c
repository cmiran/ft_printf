/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:46:57 by cmiran            #+#    #+#             */
/*   Updated: 2019/05/09 18:14:08 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned char	pf_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return (c);
		s++;
	}
	return (0);
}
