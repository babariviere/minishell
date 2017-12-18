/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 08:56:39 by briviere          #+#    #+#             */
/*   Updated: 2017/12/18 12:02:46 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void	sigint_handler(int sig)
{
	(void)sig;
	if (running_pid == 0)
	{
		ft_putchar('\n');
		put_shell_prompt();
		ft_env_set(&environ, "?", "1", 1);
		return ;
	}
	kill(running_pid, SIGINT);
	ft_putchar('\n');
	running_pid = 0;
}
