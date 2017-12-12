/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:00:17 by briviere          #+#    #+#             */
/*   Updated: 2017/12/12 17:27:24 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		builtin_cd(int ac, char **av, char **envp)
{
	char	*path;

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
		return (chdir(av[1]));
	}
	return (0);
}
