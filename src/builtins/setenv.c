/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:50:14 by briviere          #+#    #+#             */
/*   Updated: 2017/12/21 09:34:56 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		builtin_setenv(int ac, char **av, char **envp)
{
	char	*tmp;

	(void)envp;
	if (ac == 1)
		print_env(*ft_env_load());
	else if (ac == 2)
		ft_env_set(ft_env_load(), av[1], "");
	else if (ac == 3)
	{
		if ((tmp = substitute_env(av[2])) == 0)
			return (1);
		ft_env_set(ft_env_load(), av[1], tmp);
		free(tmp);
	}
	else
	{
		ft_putendl("setenv: Too many arguments.");
		return (1);
	}
	return (0);
}
