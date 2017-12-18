/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:50:14 by briviere          #+#    #+#             */
/*   Updated: 2017/12/18 14:36:32 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static char		*substitute_env(char *str)
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

int				builtin_setenv(int ac, char **av, char **envp)
{
	char	*tmp;

	(void)envp;
	if (ac == 1)
		print_env(*ft_env_load());
	else if (ac == 2)
		ft_env_set(ft_env_load(), av[1], "", 1);
	else if (ac == 3)
	{
		if ((tmp = substitute_env(av[2])) == 0)
			return (1);
		ft_env_set(ft_env_load(), av[1], tmp, 1);
		free(tmp);
	}
	else
	{
		ft_putendl("setenv: Too many arguments.");
		return (1);
	}
	return (0);
}
