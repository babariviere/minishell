/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:02:00 by briviere          #+#    #+#             */
/*   Updated: 2017/12/15 11:15:20 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static void	interpret_cmds(t_command **cmds)
{
	size_t		cmd_idx;

	cmd_idx = 0;
	while (cmds[cmd_idx])
	{
		if (cmds[cmd_idx]->av[0] == 0)
		{
			cmd_idx++;
			free_command(cmds + cmd_idx);
			continue ;
		}
		interpret(cmds[cmd_idx]);
		free_command(cmds + cmd_idx);
		cmd_idx++;
	}
}

void		shell_loop(void)
{
	t_command	**cmds;
	char		*line;
	size_t		idx;

	while (1)
	{
		idx = 0;
		ft_putstr("> ");
		if (ft_gnl(0, &line) <= 0)
		{
			ft_putendl("exit");
			ft_tabdel((void ***)&environ, sizeof(char *));
			exit(0);
		}
		cmds = parse_commands(line);
		free(line);
		interpret_cmds(cmds);
		free(cmds);
		cmds = 0;
	}
}
