/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:57:17 by briviere          #+#    #+#             */
/*   Updated: 2017/12/18 09:56:34 by briviere         ###   ########.fr       */
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
		ft_putendl2_fd("command not found: ", command->av[0], 2);
		return (127);
	}
	if (get_builtin(command->bin) >= 0)
		return (0);
	stat(command->bin, &st);
	if (has_perm(st) == 0)
	{
		ft_putendl2_fd(command->bin, ": permission denied", 2);
		return (126);
	}
	return (0);
}

int			interpret(t_command *command)
{
	pid_t	pid;
	int		status;
	int		idx;

	if ((status = check_err(command)) != 0)
		return (status);
	if (command->bin == 0 || command->bin[0] == 0)
		return (0);
	if ((idx = get_builtin(command->bin)) >= 0)
	{
		status = g_builtins[idx].ptr(ft_tablen(command->av, sizeof(char *)),
				command->av, command->env);
		return (status);
	}
	if ((pid = fork()) < 0)
		return (-1);
	if (pid == 0)
		status = execve(command->bin, command->av, command->env);
	else
	{
		running_pid = pid;
		waitpid(pid, &status, 0);
		running_pid = 0;
	}
	return (status);
}
