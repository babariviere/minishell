/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:06:34 by briviere          #+#    #+#             */
/*   Updated: 2017/12/15 11:14:53 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static size_t	command_count(const char *str)
{
	size_t	count;

	count = 1;
	while (*str)
	{
		if (*str == ';')
			count++;
		str++;
	}
	return (count);
}

t_command		*parse_command(const char *str)
{
	t_command	*cmd;
	char		**tmp;
	char		*epath;
	char		*tmp2;
	size_t		idx;
	size_t		fidx;

	if ((cmd = ft_memalloc(sizeof(t_command))) == 0)
		return (0);
	idx = 0;
	cmd->env = ft_env_init((const char **)environ);
	tmp = parse_envs(str, &idx);
	while (tmp && *tmp)
	{
		ft_env_set_ent(&cmd->env, *tmp, 1);
		tmp++;
	}
	epath = ft_env_get(cmd->env, "PATH");
	fidx = idx;
	tmp2 = parse_cmd(str, &fidx);
	cmd->bin = cmd_bin_path(tmp2, epath);
	free(tmp2);
	if (epath)
		free(epath);
	cmd->av = parse_args(str, &idx);
	return (cmd);
}

t_command		**parse_commands(const char *str)
{
	t_command	**cmds;
	char		*tmp;
	size_t		idx;
	size_t		len;

	if (str == 0)
		return (0);
	len = command_count(str);
	if ((cmds = ft_memalloc(sizeof(t_command *) * (len + 1))) == 0)
		return (0);
	idx = 0;
	tmp = (char *)str;
	while (tmp && idx < len)
	{
		cmds[idx++] = parse_command(tmp);
		if (tmp)
			tmp = ft_strchr(tmp, ';');
		if (tmp)
			tmp += 1;
	}
	cmds[idx] = 0;
	return (cmds);
}
