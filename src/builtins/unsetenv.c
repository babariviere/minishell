/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:52:52 by briviere          #+#    #+#             */
/*   Updated: 2017/12/18 13:40:36 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		builtin_unsetenv(int ac, char **av, char **envp)
{
	int	idx;

	(void)envp;
	idx = 1;
	if (ac == 1)
	{
		ft_putendl("unsetenv: Too few arguments.");
		return (1);
	}
	while (idx < ac)
	{
		ft_env_rm(ft_env_load(), av[idx]);
		idx++;
	}
	return (0);
}
