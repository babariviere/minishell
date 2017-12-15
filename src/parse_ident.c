/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ident.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:58:20 by briviere          #+#    #+#             */
/*   Updated: 2017/12/15 13:15:18 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static char	*parse_ident_sub(const char *str, size_t *idx)
{
	char	*tmp;
	char	*tmp_semi;

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
		if (tmp == 0)
			tmp = tmp_semi;
	}
	return (tmp);
}

char		*parse_ident(const char *str, size_t *idx)
{
	char	*res;
	char	*tmp;
	size_t	len;

	res = 0;
	tmp = parse_ident_sub(str, idx);
	if (tmp)
		len = tmp - (str + *idx);
	else
		len = ft_strlen(str + *idx);
	if (len == 0)
		return (0);
	res = ft_strnew(len);
	ft_strncpy_esc(res, str + *idx, len);
	*idx += len;
	if (tmp && (*tmp == '\'' || *tmp == '\"'))
		*idx += 1;
	return (res);
}
