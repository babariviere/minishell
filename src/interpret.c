/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:57:17 by briviere          #+#    #+#             */
/*   Updated: 2017/12/12 12:46:56 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void		interpret(t_command *command)
{
	pid_t	pid;
	int		status;
	// TODO: check if builtin
	ft_putstr("cmd: ");
	ft_putendl(command->bin);
	ft_putstr("arg: ");
	ft_print_tab((const char **)command->av);
	if ((pid = fork()) < 0)
		return ;
	if (pid == 0)
		execve(command->bin, command->av, command->env);
	else
		waitpid(pid, &status, 0);
}
