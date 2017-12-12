/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:02:00 by briviere          #+#    #+#             */
/*   Updated: 2017/12/12 12:14:15 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void		shell_loop(char **envp)
{
	t_command	**cmds;
	char		*line;
	size_t		idx;
	size_t		cmd_idx;

	while (1)
	{
		idx = 0;
		cmd_idx = 0;
		ft_putstr("> ");
		if (ft_gnl(0, &line) <= 0)
		{
			ft_putendl("exit");
			break ;
		}
		cmds = parse_commands(line, (const char **)envp);
		while (cmds[cmd_idx])
		{
			ft_putstr("cmd: ");
			ft_putendl(cmds[cmd_idx]->bin);
			cmd_idx++;
		}
		//if (ft_strcmp(cmd->content, "exit") == 0)
		//	break ;
		ft_putendl("command not found");
	}
}
