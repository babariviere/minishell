/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:29:48 by briviere          #+#    #+#             */
/*   Updated: 2017/12/18 13:44:37 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static int		check_exit(char *bin)
{
	if (ft_strcmp(bin, "exit") == 0)
	{
		ft_putendl_fd("env: exit: no such file or directory", 2);
		return (0);
	}
	return (1);
}

void			print_env(char **envp)
{
	size_t	idx;

	idx = 0;
	while (envp[idx])
	{
		if (envp[idx][0] == '?' || envp[idx][0] == '0' || envp[idx][0] == 0)
		{
			idx++;
			continue ;
		}
		ft_putendl(envp[idx++]);
	}
}

int				builtin_env(int ac, char **av, char **envp)
{
	t_command	*cmd;
	char		*cmd_str;
	int			res;

	(void)envp;
	if (ac == 1)
	{
		print_env(*ft_env_load());
		return (0);
	}
	cmd_str = ft_strtab_join_sep((av + 1), ' ');
	cmd = parse_command(cmd_str);
	res = 0;
	if (cmd->bin == 0)
		print_env(cmd->env);
	else if (check_exit(cmd->bin) == 0)
		res = 1;
	else
		res = interpret(cmd);
	free_command(&cmd);
	return (res);
}
