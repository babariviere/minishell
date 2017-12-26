/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:06:34 by briviere          #+#    #+#             */
/*   Updated: 2017/12/26 09:43:21 by briviere         ###   ########.fr       */
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

static char		*parse_command_bin(const char *str, size_t *fidx, char *epath)
{
	char	*cmd_str;
	char	*cmd_res;
	char	*path;

	path = ft_strjoin(epath, ":.");
	cmd_str = parse_cmd_str(str, fidx);
	cmd_res = cmd_bin_path(cmd_str, path);
	free(path);
	if (cmd_res == cmd_str)
		return (cmd_str);
	free(cmd_str);
	return (cmd_res);
}

t_command		*parse_command(const char *str)
{
	t_command	*cmd;
	char		**tmp;
	char		*epath;
	size_t		idx;
	size_t		fidx;

	if ((cmd = ft_memalloc(sizeof(t_command))) == 0)
		return (0);
	idx = 0;
	while (ft_iswhitespace(str[idx]))
		idx++;
	cmd->env = ft_env_init(*ft_env_load());
	ft_env_rm(&cmd->env, "?");
	ft_env_rm(&cmd->env, "0");
	tmp = parse_envs(str, &idx);
	while (tmp && *tmp)
	{
		ft_env_set_ent(&cmd->env, *tmp);
		tmp++;
	}
	epath = ft_env_get(cmd->env, "PATH");
	fidx = idx;
	cmd->bin = parse_command_bin(str, &fidx, epath);
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
		tmp = ft_strchr(tmp, ';');
		if (tmp)
			tmp += 1;
	}
	return (cmds);
}
