/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:24:41 by briviere          #+#    #+#             */
/*   Updated: 2017/12/15 15:23:11 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static size_t	echo_env(char *str, char **envp)
{
	size_t	idx;
	char	*tmp;
	char	*env;

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
	tmp = ft_strsub(str, 1, idx - 1);
	if (tmp)
	{
		env = ft_env_get(envp, tmp);
		if (env == 0)
			return (idx);
		ft_putstr(env);
		free(tmp);
	}
	return (idx);
}

static void		echo_str_dollar(char *str, char **envp, size_t *begptr,
		size_t *endptr)
{
	size_t	beg;
	size_t	end;

	beg = *begptr;
	end = *endptr;
	write(1, str + beg, end - beg);
	beg = end + echo_env(str + end, envp);
	end = beg;
	*begptr = beg;
	*endptr = end;
}

static void		echo_str_antislash(char *str, size_t *beg, size_t *end,
		int *prev_anti)
{
	write(1, str + *beg, *end - *beg - 1);
	*beg = *end + 1;
	*prev_anti = 1;
}

static void		echo_str(char *str, char **envp)
{
	size_t	beg;
	size_t	end;
	int		prev_anti;

	prev_anti = 0;
	beg = 0;
	end = 0;
	while (str[end])
	{
		if (str[end] == '\\' && prev_anti == 0)
			echo_str_antislash(str, &beg, &end, &prev_anti);
		else if (str[end] == '$' && prev_anti == 0)
			echo_str_dollar(str, envp, &beg, &end);
		else if (prev_anti)
		{
			ft_putchar(str[end]);
			beg = end + 1;
			prev_anti = 0;
		}
		end++;
	}
	write(1, str + beg, end - beg);
}

int				builtin_echo(int ac, char **av, char **envp)
{
	int		idx;

	(void)envp;
	idx = 1;
	while (idx < ac)
	{
		if (idx > 1)
			ft_putchar(' ');
		echo_str(av[idx], environ);
		idx++;
	}
	ft_putchar('\n');
	return (0);
}
