/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:48:57 by briviere          #+#    #+#             */
/*   Updated: 2017/12/13 10:44:09 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		builtin_exit(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void)envp;
	
	if (ac == 2)
		exit(ft_atoi(av[1]));
	if (ac > 2)
	{
		ft_putendl("exit: too many arguments");
		return (1);
	}
	exit(0);
}
