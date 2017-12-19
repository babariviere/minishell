/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 08:56:39 by briviere          #+#    #+#             */
/*   Updated: 2017/12/19 11:45:00 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void	sigint_handler(int sig)
{
	(void)sig;
	if (g_running_pid == 0)
	{
		ft_putstr("\33[2K\r");
		put_shell_prompt();
		ft_putchar('\n');
		put_shell_prompt();
		ft_env_set(ft_env_load(), "?", "1", 1);
		return ;
	}
	kill(g_running_pid, SIGINT);
	ft_putchar('\n');
	g_running_pid = 0;
}
