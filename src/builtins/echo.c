/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:24:41 by briviere          #+#    #+#             */
/*   Updated: 2017/12/12 14:33:35 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		builtin_echo(int ac, char **av, char **envp)
{
	int		idx;

	(void)envp;
	idx = 1;
	while (idx < ac)
	{
		if (idx > 1)
			ft_putchar(' ');
		ft_putstr(av[idx]);
		idx++;
	}
	ft_putchar('\n');
	return (0);
}
