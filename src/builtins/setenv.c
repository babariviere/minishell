/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:50:14 by briviere          #+#    #+#             */
/*   Updated: 2018/01/08 09:19:36 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static int	check_and_set(char *name, char *val)
{
	size_t	idx;

	idx = 0;
	while (name[idx])
	{
		if (!ft_isalnum(name[idx]))
		{
			ft_putendl("setenv: Variable name must contain alphanumeric \
characters.");
			return (1);
		}
		idx++;
	}
	ft_env_set(ft_env_load(), name, val);
	return (0);
}

int			builtin_setenv(int ac, char **av, char **envp)
{
	(void)envp;
	if (ac == 1)
		print_env(*ft_env_load());
	else if (ac == 2)
		return (check_and_set(av[1], ""));
	else if (ac == 3)
		return (check_and_set(av[1], av[2]));
	else
	{
		ft_putendl("setenv: Too many arguments.");
		return (1);
	}
	return (0);
}
