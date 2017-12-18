/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:48:57 by briviere          #+#    #+#             */
/*   Updated: 2017/12/18 13:39:59 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		builtin_exit(int ac, char **av, char **envp)
{
	int		ex;

	ex = 0;
	(void)envp;
	if (ac == 2)
		ex = ft_atoi(av[1]);
	if (ac > 2)
	{
		ft_putendl("exit: too many arguments");
		return (1);
	}
	ft_putendl("exit");
	ft_tabdel((void ***)ft_env_load(), sizeof(char *));
	return (ex);
}
