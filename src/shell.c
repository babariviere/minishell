/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:02:00 by briviere          #+#    #+#             */
/*   Updated: 2017/12/11 17:07:09 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void		print_command(t_lst *elem)
{
	ft_putendl(elem->content);
}

void		shell_loop(char **envp, char **epath)
{
	t_command	**cmds;
	char		*line;

	while (1)
	{
		ft_putstr("> ");
		if (ft_gnl(0, &line) <= 0)
		{
			ft_putendl("exit");
			break ;
		}
		cmds = parse_commands(line, envp, epath);
		//if (ft_strcmp(cmd->content, "exit") == 0)
		//	break ;
		ft_putendl("command not found");
	}
}
