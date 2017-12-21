/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:51:31 by briviere          #+#    #+#             */
/*   Updated: 2017/12/21 09:34:27 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		main(int ac, char **av)
{
	char	***env;

	(void)ac;
	(void)av;
	env = ft_env_load();
	*env = ft_env_init(*env);
	ft_env_set(env, "0", "minishell");
	signal(SIGINT, sigint_handler);
	shell_loop();
	ft_tabdel((void ***)env, sizeof(char *));
	return (0);
}
