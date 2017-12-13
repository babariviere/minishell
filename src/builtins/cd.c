/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:00:17 by briviere          #+#    #+#             */
/*   Updated: 2017/12/13 10:35:50 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		builtin_cd(int ac, char **av, char **envp)
{
	char	*path;
	int		res;

	// TODO: check if directory exists
	if (ac == 1)
	{
		path = ft_env_get(envp, "HOME");
		if (path)
			return (chdir(path));
		else
		{
			ft_putendl("HOME is not defined");
			return (1);
		}
	}
	else if (ac > 1)
	{
		if (av[1][0] == '~')
		{
			path = ft_env_get(envp, "HOME");
			path = ft_strjoin(path, av[1] + 1);
		}
		else
			path = ft_strdup(av[1]);
		res = chdir(path);
		free(path);
		return (res);
	}
	return (0);
}
