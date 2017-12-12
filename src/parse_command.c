/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:07:01 by briviere          #+#    #+#             */
/*   Updated: 2017/12/12 12:09:25 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static size_t	command_size(const char *str)
{
	size_t		count;
	size_t		level;

	count = 1;
	level = 0;
	while (*str)
	{
		if (*str == ';')
			return (count);
		if (*str == '\'' || *str == '\"')
			str = ft_strchr_esc(str, *str);
		if (ft_iswhitespace(*str))
		{
			count++;
			while (ft_iswhitespace(*str))
				str++;
		}
		else
			str++;
	}
	return (count);
}

t_command		*parse_command(const char *str, const char **envp)
{
	t_command	*cmd;
	char		**nenvp;
	char		**tmp;
	char		*epath;
	size_t		idx;

	if ((cmd = ft_memalloc(sizeof(t_command))) == 0)
		return (0);
	idx = 0;
	nenvp = ft_env_init(envp);
	tmp = parse_envs(str, &idx);
	while (tmp && *tmp)
	{
		ft_env_set_ent(&nenvp, *tmp);
		tmp++;
	}
	epath = ft_env_get(nenvp, "PATH");
	cmd->bin = cmd_bin_path(parse_cmd(str, &idx), epath);
	if (epath)
		free(epath);
	cmd->av = parse_args(str, &idx);
	return (cmd);
}

t_command		**parse_commands(const char *str, const char **envp)
{
	t_command	**cmds;
	char		*tmp;
	size_t		idx;
	size_t		len;

	if (str == 0)
		return (0);
	len = command_size(str);
	if ((cmds = ft_memalloc(sizeof(t_command *) * (len + 1))) == 0)
		return (0);
	idx = 0;
	tmp = (char *)str;
	while (idx < len)
	{
		cmds[idx++] = parse_command(tmp, envp);
		if (tmp)
			tmp = ft_strchr(tmp, ';');
		if (tmp != 0)
			tmp += 1;
	}
	return (cmds);
}
