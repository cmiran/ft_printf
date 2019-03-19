/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 16:55:23 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/18 22:56:06 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Alloue (avec malloc(3)) et retourne une chaine de caractère “fraiche”
** terminée par un ’\0’.
** Chaque caractère de la chaine est initialisé à ’\0’.
** Si l’allocation echoue, la fonction renvoie NULL.
*/

#include "../inc/ft_printf.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	return (ft_memset(str, '\0', size + 1));
}
