/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_sub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:34:30 by briviere          #+#    #+#             */
/*   Updated: 2017/12/26 09:33:38 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

char	*parse_env(const char *str, size_t *idx)
{
	char	*res;
	char	*tmp;
	size_t	lidx;

	lidx = *idx;
	res = parse_ident(str, &lidx);
	if (res == 0)
		return (0);
	tmp = ft_strchr(res, '=');
	if (tmp == 0)
	{
		free(res);
		return (0);
	}
	*idx = lidx;
	return (res);
}

char	**parse_envs(const char *str, size_t *idx)
{
	char	**res;
	char	*tmp;
	size_t	sidx;
	size_t	size;

	res = 0;
	sidx = 0;
	size = 0;
	while ((tmp = parse_env(str, idx)))
	{
		res = ft_realloc(res, size, (size + sizeof(char *) * 2));
		res[sidx] = tmp;
		res[sidx + 1] = 0;
		tmp = 0;
		size += sizeof(char *);
		sidx++;
	}
	return (res);
}

char	*parse_cmd_str(const char *str, size_t *idx)
{
	char	*res;

	res = parse_ident(str, idx);
	return (res);
}

char	**parse_args(const char *str, size_t *idx)
{
	char	**res;
	char	*tmp;
	size_t	sidx;
	size_t	size;

	res = 0;
	sidx = 0;
	size = 0;
	while (str[*idx] && (tmp = parse_ident(str, idx)))
	{
		res = ft_realloc(res, size, size + (sizeof(char *) * 2));
		res[sidx] = tmp;
		res[sidx + 1] = 0;
		tmp = 0;
		size += sizeof(char *);
		sidx++;
	}
	return (res);
}
