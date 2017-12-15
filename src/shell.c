/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:02:00 by briviere          #+#    #+#             */
/*   Updated: 2017/12/15 12:47:43 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static void	interpret_cmds(t_command **cmds)
{
	size_t		cmd_idx;
	size_t		store;
	int			res;
	char		*res_str;

	cmd_idx = 0;
	while (cmds[cmd_idx])
	{
		if (cmds[cmd_idx]->av[0] == 0)
		{
			cmd_idx++;
			free_command(cmds + cmd_idx);
			continue ;
		}
		if (ft_strcmp(cmds[cmd_idx]->bin, "exit") == 0)
		{
			store = cmd_idx;
			cmd_idx++;
			while (cmds[cmd_idx])
			{
				free(cmds + cmd_idx);
				cmd_idx++;
			}
			res = interpret(cmds[store]);
			free_command(cmds + store);
			free(cmds);
			exit(res);
		}
		res = interpret(cmds[cmd_idx]);
		res_str = ft_itoa(res);
		ft_env_set_ent(&environ, res_str, 1);
		free(res_str);
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
			exit(builtin_exit(1, (char *[]){(char *)"exit"}, environ));
		cmds = parse_commands(line);
		free(line);
		interpret_cmds(cmds);
		free(cmds);
		cmds = 0;
	}
}
