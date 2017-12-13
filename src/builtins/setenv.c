/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:50:14 by briviere          #+#    #+#             */
/*   Updated: 2017/12/13 09:56:19 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		builtin_setenv(int ac, char **av, char **envp)
{
	(void)envp;
	if (ac == 1)
		ft_print_tab((const char **)g_envp);
	else if (ac == 2)
		ft_env_set(&g_envp, av[1], "", 1);
	else if (ac == 3)
		ft_env_set(&g_envp, av[1], av[2], 1);
	else
	{
		ft_putendl("setenv: Too many arguments.");
		return (1);
	}
	return (0);
}
