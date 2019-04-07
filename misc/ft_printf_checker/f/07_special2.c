/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_special2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:46:53 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/24 21:09:44 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			test_f_special2(void)
{
	int		pipeans[2];
	int		pipecor[2];
	int		ians;
	int		icor;
	char	ans[READING_SIZE + 1];
	char	cor[READING_SIZE + 1];

	if (pipe(pipeans) == -1)
		exit(INTERNAL_FAILURE);
	if (dup2(pipeans[1], 1) == -1)
		exit(-1);
	if (pipe(pipecor) == -1)
		exit(INTERNAL_FAILURE);
	if (dup2(pipecor[1], 2) == -1)
		exit(-1);


	float		nb;
	nb = -0.000;

	ft_printf("test basique:");
    ft_printf("space:% f\n", nb);
    ft_printf("plus:%+f\n", nb);
    ft_printf("hash:%#f\n", nb);
    ft_printf("precision:%.2f\n", nb);
    ft_printf("big prec:%.14f\n", nb);
    ft_printf("precision + hash:%#.0f\n", nb);
    ft_printf("space + prec:% .5f\n", nb);
    ft_printf("space + prec + hash:%# .0f\n", nb);
    ft_printf("space + prec + hash:% #.0f\n", nb);
    ft_printf("Plus + prec / grande:%+.5f\n", nb);
    ft_printf("Plus + prec / petite:%+.0f\n", nb);
    ft_printf("Plus + prec + hash:%#+.0f\n", nb);
    ft_printf("Prec + 0:%0.5f\n", nb);
    ft_printf("Prec + minus:%-.5f\n", nb);
    ft_printf("size:%5f\n", nb);
    ft_printf("size + space:% 5f\n", nb);
    ft_printf("size + plus:%+5f\n", nb);
    ft_printf("size + space:%# 5f\n", nb);
    ft_printf("size + plus:%#+5f\n", nb);
    ft_printf("size + minus:%-5f\n", nb);
    ft_printf("size + 0:%05f\n", nb);
    ft_printf("size + 0 + plus:%+05f\n", nb);
    ft_printf("size + 0 + plus:%0+5f\n", nb);
    ft_printf("size + 0 + prec:%05.3f\n", nb);
    ft_printf("size + 0 + prec + hash:%0#5.0f\n", nb);
    ft_printf("size + minus + prec:%-5.3f\n", nb);
    ft_printf("size + minus + prec + hash:%-#5.0f\n", nb);
    ft_printf("size + plus + 0 + prec:%+05.3f\n", nb);
    ft_printf("size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
    ft_printf("size + espace + zero + prec:%0 5.3f\n", nb);
    ft_printf("size + espace + zero + prec:% 05.3f\n", nb);
    ft_printf("size + espace + zero + prec + hash:%#0 5.0f\n", nb);
    ft_printf("size + minus + plus + prec:%-+5.3f\n", nb);
    ft_printf("size + minus + plus + prec + hash:%-#+5.0f\n", nb);

	dprintf(2, "test basique:");
	dprintf(2, "space:% f\n", nb);
	dprintf(2, "plus:%+f\n", nb);
	dprintf(2, "hash:%#f\n", nb);
	dprintf(2, "precision:%.2f\n", nb);
	dprintf(2, "big prec:%.14f\n", nb);
	dprintf(2, "precision + hash:%#.0f\n", nb);
	dprintf(2, "space + prec:% .5f\n", nb);
	dprintf(2, "space + prec + hash:%# .0f\n", nb);
	dprintf(2, "space + prec + hash:% #.0f\n", nb);
	dprintf(2, "Plus + prec / grande:%+.5f\n", nb);
	dprintf(2, "Plus + prec / petite:%+.0f\n", nb);
	dprintf(2, "Plus + prec + hash:%#+.0f\n", nb);
	dprintf(2, "Prec + 0:%0.5f\n", nb);
	dprintf(2, "Prec + minus:%-.5f\n", nb);
	dprintf(2, "size:%5f\n", nb);
	dprintf(2, "size + space:% 5f\n", nb);
	dprintf(2, "size + plus:%+5f\n", nb);
	dprintf(2, "size + space:%# 5f\n", nb);
	dprintf(2, "size + plus:%#+5f\n", nb);
	dprintf(2, "size + minus:%-5f\n", nb);
	dprintf(2, "size + 0:%05f\n", nb);
	dprintf(2, "size + 0 + plus:%+05f\n", nb);
	dprintf(2, "size + 0 + plus:%0+5f\n", nb);
	dprintf(2, "size + 0 + prec:%05.3f\n", nb);
	dprintf(2, "size + 0 + prec + hash:%0#5.0f\n", nb);
	dprintf(2, "size + minus + prec:%-5.3f\n", nb);
	dprintf(2, "size + minus + prec + hash:%-#5.0f\n", nb);
	dprintf(2, "size + plus + 0 + prec:%+05.3f\n", nb);
	dprintf(2, "size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
	dprintf(2, "size + espace + zero + prec:%0 5.3f\n", nb);
	dprintf(2, "size + espace + zero + prec:% 05.3f\n", nb);
	dprintf(2, "size + espace + zero + prec + hash:%#0 5.0f\n", nb);
	dprintf(2, "size + minus + plus + prec:%-+5.3f\n", nb);
	dprintf(2, "size + minus + plus + prec + hash:%-#+5.0f\n", nb);

	close(pipeans[1]);
	close(pipecor[1]);
	ians = read(pipeans[0], ans, READING_SIZE);
	icor = read(pipecor[0], cor, READING_SIZE);
	close(pipeans[0]);
	close(pipecor[0]);
	if (ians >= 0)
		ans[ians] = 0;
	if (icor >= 0)
		cor[icor] = 0;
	if (strcmp(cor, ans) == 0)
		exit (SUCCESS);
	exit(FAILURE);
}

int			f_special2(void)
{
	pid_t	pid_test;
	int		pipefd[2];
	int		wait_res;
	pid_t	pid_timeout;
	pid_t	first_pid;

	if (pipe(pipefd) == -1)
		exit(-1);
	if ((pid_test = fork()) == -1)
		exit(FAILURE);
	if (pid_test == 0)
		exit(test_f_special2());
	if ((pid_timeout = fork()) == -1)
		exit(FAILURE);
	if (pid_timeout == 0)
	{
		sleep(TIMEOUT_F);
		exit(SIGUSR1);
	}
	else
	{
		first_pid = wait(&wait_res);
		if (first_pid == pid_timeout)
		{
			kill(pid_test, SIGKILL);
			return (FAILURE);
		}
		kill(pid_timeout, SIGKILL);
		if (wait_res == SUCCESS)
			return(SUCCESS);
		return (FAILURE);
	}
}
