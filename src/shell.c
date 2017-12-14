/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:02:00 by briviere          #+#    #+#             */
/*   Updated: 2017/12/14 09:37:28 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void		shell_loop(void)
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
			exit(0);
		}
		cmds = parse_commands(line);
		while (cmds[cmd_idx])
		{
			if (cmds[cmd_idx]->av[0] == 0)
			{
				cmd_idx++;
				continue ;
			}
			interpret(cmds[cmd_idx]);
			free(cmds[cmd_idx]);
			cmd_idx++;
		}
		cmds = 0;
	}
}
