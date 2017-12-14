/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_sub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:34:30 by briviere          #+#    #+#             */
/*   Updated: 2017/12/14 17:14:51 by briviere         ###   ########.fr       */
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

	if ((res = malloc(sizeof(char *) * 1)) == 0)
		return (0);
	res[0] = 0;
	sidx = 0;
	size = sizeof(char *);
	while ((tmp = parse_env(str, idx)))
	{
		res = ft_realloc(res, size, size + sizeof(char *));
		res[sidx] = tmp;
		res[sidx + 1] = 0;
		tmp = 0;
		while (str[*idx] && ft_iswhitespace(str[*idx]))
			*idx += 1;
		size += sizeof(char *);
		sidx++;
	}
	return (res);
}

char	*parse_cmd(const char *str, size_t *idx)
{
	char	*res;

	while (str[*idx] && ft_iswhitespace(str[*idx]))
		*idx += 1;
	res = parse_ident(str, idx);
	while (str[*idx] && ft_iswhitespace(str[*idx]))
		*idx += 1;
	return (res);
}

char	**parse_args(const char *str, size_t *idx)
{
	char	**res;
	char	*tmp;
	size_t	sidx;
	size_t	size;

	if ((res = malloc(sizeof(char *))) == 0)
		return (0);
	res[0] = 0;
	sidx = 0;
	size = sizeof(char *);
	while (str[*idx] && (tmp = parse_ident(str, idx)))
	{
		res = ft_realloc(res, size, size + sizeof(char *));
		res[sidx] = tmp;
		tmp = 0;
		while (str[*idx] && ft_iswhitespace(str[*idx]))
			*idx += 1;
		size += sizeof(char *);
		sidx++;
	}
	res[sidx] = 0;
	return (res);
}
