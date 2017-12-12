/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:53:05 by briviere          #+#    #+#             */
/*   Updated: 2017/12/12 12:12:23 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static char	*file_exists(const char *path, const char *file)
{
	char		*tmp;
	struct stat	st;

	tmp = ft_strjoin_sep(path, "/", file);
	if (lstat(tmp, &st) < 0)
	{
		free(tmp);
		return (0);
	}
	return (tmp);
}

char	*cmd_bin_path(char *cmd, const char *epath)
{
	size_t	beg;
	size_t	end;
	char	*tmp;
	char	*res;

	if (ft_strchr(cmd, '/'))
		return (cmd);
	// TODO: if builtin
	beg = 0;
	end = beg;
	res = 0;
	while (epath[end])
	{
		if (epath[end] == ':')
		{
			tmp = ft_strsub(epath, beg, end - beg);
			res = file_exists(tmp, cmd);
			free(tmp);
			if (res)
			{
				free(cmd);
				return (res);
			}
			beg = end + 1;
		}
		end++;
	}
	return (0);
}
