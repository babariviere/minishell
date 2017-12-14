/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_sub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:34:30 by briviere          #+#    #+#             */
/*   Updated: 2017/12/14 16:08:02 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

char	*parse_ident(const char *str, size_t *idx)
{
	char	*res;
	char	*tmp;
	char	*tmp_semi;
	size_t	len;

	res = 0;
	if (str[*idx] == '\'' || str[*idx] == '\"')
	{
		tmp = ft_strchr_esc(str + (*idx + 1), str[*idx]);
		*idx += 1;
	}
	else
	{
		tmp = ft_strchr_esc(str + (*idx), ' ');
		tmp_semi = ft_strchr(str + (*idx), ';');
		if (tmp_semi && tmp_semi < tmp)
			tmp = tmp_semi;
	}
	if (tmp)
		len = tmp - (str + *idx);
	else
		len = ft_strlen(str + *idx);
	res = ft_strnew(len);
	ft_strncpy(res, str + *idx, len);
	*idx += len;
	if (tmp && (*tmp == ';' || *tmp == '\'' || *tmp == '\"'))
		*idx += 1;
	return (res);
}

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
