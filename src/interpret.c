/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:57:17 by briviere          #+#    #+#             */
/*   Updated: 2017/12/12 17:14:57 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void		interpret(t_command *command)
{
	pid_t	pid;
	int		status;
	int		idx;

	if (command == 0)
		return ;
	if (command->bin == 0)
	{
		ft_putstr("minishell: command not found: ");
		ft_putendl(command->av[0]);
		return ;
	}
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
