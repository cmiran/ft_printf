/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmiran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:50:14 by cmiran            #+#    #+#             */
/*   Updated: 2019/03/18 17:42:14 by cmiran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Alloue (avec malloc(3)) et retourne une chaine de caractères “fraiche”
** terminée par un ’\0’ représentant l’entier n passé en paramètre.
** Les nombres négatifs doivent être gérés. Si l’allocation échoue,
** la fonction renvoie NULL.
*/

#include "../inc/ft_printf.h"

size_t	ft_nbrlen(int nb)
{
	size_t	len;

	len = (nb < 0) ? 2 : 1;
	while (nb /= 10)
		len++;
	return (len);
}

char	*ft_itoa(int nb)
{
	size_t	len;
	char	*str;
	int	sign;

	len = ft_nbrlen(nb);
	if (!(str = (char *)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	sign = 1;
	if (nb < 0)
	{
		str[0] = '-';
		sign -= 2;
	}
	while (nb)
	{
		str[--len] = nb % 10 * sign + '0';
		nb /= 10;
	}
	return (str);
}
