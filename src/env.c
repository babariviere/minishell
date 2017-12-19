/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:16:38 by briviere          #+#    #+#             */
/*   Updated: 2017/12/19 10:08:22 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

char		*extract_env(char *str)
{
	size_t		idx;

	idx = 0;
	if (str[idx++] != '$')
		return (0);
	if (str[idx] != '?')
	{
		while (str[idx] && (ft_isalnum(str[idx]) || str[idx] == '_'))
			idx++;
	}
	else
		idx++;
	return (ft_strsub(str, 0, idx));
}

char		*substitute_env(char *str)
{
	char	*tmp;
	char	*tmp2;
	char	*res;
	char	*env;

	res = ft_strdup(str);
	while ((tmp = ft_strchr_esc(res, '$')))
	{
		tmp = extract_env(tmp);
		env = ft_env_get(*ft_env_load(), tmp + 1);
		if (env == 0)
		{
			ft_putendl2_fd(tmp + 1, ": environment variable not found", 2);
			return (0);
		}
		tmp2 = res;
		res = ft_strrepl(res, tmp, env);
		free(tmp);
		free(tmp2);
	}
	return (res);
}
