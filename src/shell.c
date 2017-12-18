/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:02:00 by briviere          #+#    #+#             */
/*   Updated: 2017/12/18 12:01:10 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static void	interpret_cmd(t_command **cmds, size_t cmd_idx)
{
	size_t		store;
	int			res;
	char		*res_str;

	if (cmds[cmd_idx]->bin && ft_strcmp(cmds[cmd_idx]->bin, "exit") == 0)
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
	ft_env_set(&environ, "?", res_str, 1);
	free(res_str);
	free_command(cmds + cmd_idx);
}

static void	interpret_cmds(t_command **cmds)
{
	size_t		cmd_idx;

	cmd_idx = 0;
	while (cmds[cmd_idx])
	{
		interpret_cmd(cmds, cmd_idx);
		cmd_idx++;
	}
}

void		put_shell_prompt(void)
{
	char	*home;
	char	cwd[MAXPATHLEN];
	size_t	len;

	home = ft_env_get(environ, "HOME");
	if (home)
	{
		getcwd(cwd, MAXPATHLEN);
		len = ft_strlen(home);
		if (ft_strncmp(home, cwd, len) == 0)
		{
			cwd[0] = '~';
			ft_strcpy(cwd + 1, cwd + len);
		}
		ft_putstr(cwd);
		ft_putchar(' ');
	}
	ft_putstr("> ");
}

void		shell_loop(void)
{
	t_command	**cmds;
	char		*line;
	size_t		idx;

	while (1)
	{
		idx = 0;
		put_shell_prompt();
		if (ft_gnl(0, &line) <= 0)
			exit(builtin_exit(1, (char *[]){(char *)"exit"}, environ));
		cmds = parse_commands(line);
		free(line);
		interpret_cmds(cmds);
		free(cmds);
		cmds = 0;
	}
}
