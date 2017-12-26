/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:50:14 by briviere          #+#    #+#             */
/*   Updated: 2017/12/26 09:02:52 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		builtin_setenv(int ac, char **av, char **envp)
{
	(void)envp;
	if (ac == 1)
		print_env(*ft_env_load());
	else if (ac == 2)
		ft_env_set(ft_env_load(), av[1], "");
	else if (ac == 3)
		ft_env_set(ft_env_load(), av[1], av[2]);
	else
	{
		ft_putendl("setenv: Too many arguments.");
		return (1);
	}
	return (0);
}
