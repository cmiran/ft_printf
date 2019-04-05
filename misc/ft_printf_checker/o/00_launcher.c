/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:44:07 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/14 10:39:26 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			o_launcher(void)
{
	t_test		*start;

	start = NULL;
	libunit_display_header("%o");
	load_test(&start, "basic 1 (0)                  ", &(o_basic1));
	load_test(&start, "basic 2 (45)                 ", &(o_basic2));
	load_test(&start, "basic 3 (123564789)          ", &(o_basic3));
	load_test(&start, "basic 4 (-1235)              ", &(o_basic4));
	load_test(&start, "basic 5 (56489612321568652)  ", &(o_basic5));
	return (launch_test(start));	
}
