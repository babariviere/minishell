/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 08:56:39 by briviere          #+#    #+#             */
/*   Updated: 2017/12/18 09:17:26 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void	sigint_handler(int sig)
{
	(void)sig;
	ft_putchar('\r');
	if (running_pid == 0)
	{
		put_shell_prompt();
		ft_putstr("  \n");
		put_shell_prompt();
		ft_env_set(&environ, "?", "1", 1);
		return ;
	}
	kill(running_pid, SIGINT);
	running_pid = 0;
}
