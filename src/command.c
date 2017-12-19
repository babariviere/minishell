/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:53:05 by briviere          #+#    #+#             */
/*   Updated: 2017/12/19 11:23:29 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static char	*file_exists(const char *path, const char *file)
{
	char		*tmp;
	struct stat	st;

	tmp = ft_strjoin_sep(path, '/', file);
	if (lstat(tmp, &st) < 0)
	{
		free(tmp);
		return (0);
	}
	return (tmp);
}

void		free_command(t_command **cmdptr)
{
	t_command	*cmd;

	cmd = *cmdptr;
	if (cmd->env)
		ft_tabdel((void ***)&cmd->env, sizeof(char *));
	if (cmd->bin)
		free(cmd->bin);
	if (cmd->av)
		ft_tabdel((void ***)&cmd->av, sizeof(char *));
	ft_memdel((void **)cmdptr);
}

static char	*cmd_bin_path_sub(char *cmd, const char *epath, size_t beg,
		size_t end)
{
	char	*res;
	char	*tmp;

	if (cmd == 0 || epath == 0)
		return (0);
	tmp = ft_strsub(epath, beg, end - beg);
	res = file_exists(tmp, cmd);
	free(tmp);
	if (res)
	{
		free(cmd);
		return (res);
	}
	return (0);
}

char		*cmd_bin_path(char *cmd, const char *epath)
{
	size_t	beg;
	size_t	end;
	char	*res;

	if (cmd == 0 || cmd[0] == 0)
		return (cmd);
	if (ft_strchr(cmd, '/'))
		return (cmd);
	if (get_builtin(cmd) >= 0)
		return (cmd);
	beg = 0;
	end = beg;
	res = 0;
	while (epath && epath[end])
	{
		if (epath[end] == ':')
		{
			if ((res = cmd_bin_path_sub(cmd, epath, beg, end)))
				return (res);
			beg = end + 1;
		}
		end++;
	}
	return (cmd_bin_path_sub(cmd, epath, beg, end));
}
