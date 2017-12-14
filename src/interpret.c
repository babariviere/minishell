/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:57:17 by briviere          #+#    #+#             */
/*   Updated: 2017/12/14 09:43:09 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static int	has_perm(struct stat st)
{
	return ((st.st_mode & S_IXUSR) || (st.st_mode & S_IXGRP) ||
			(st.st_mode & S_IXOTH));
}

static int	check_err(t_command *command)
{
	struct stat	st;

	if (command == 0)
		return (0);
	if (command->bin == 0)
	{
		ft_putstr("command not found: ");
		ft_putendl(command->av[0]);
		return (0);
	}
	if (get_builtin(command->bin) > 0)
		return (1);
	stat(command->bin, &st);
	if (has_perm(st) == 0)
	{
		ft_putstr(command->bin);
		ft_putendl(": permission denied");
		return (0);
	}
	return (1);
}

void		interpret(t_command *command)
{
	pid_t	pid;
	int		status;
	int		idx;

	if (check_err(command) == 0)
		return ;
	if ((idx = get_builtin(command->bin)) >= 0)
	{
		g_builtins[idx].ptr(ft_tablen(command->av, sizeof(char *)),
				command->av, command->env);
		return ;
	}
	status = 0;
	if ((pid = fork()) < 0)
		return ;
	if (pid == 0)
		status = execve(command->bin, command->av, command->env);
	else
		waitpid(pid, &status, 0);
	ft_putstr("exit num: ");
	ft_putnbr(status);
	ft_putendl(0);
}
