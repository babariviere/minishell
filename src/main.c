/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:51:31 by briviere          #+#    #+#             */
/*   Updated: 2017/12/15 11:16:37 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	environ = ft_env_init((const char **)environ);
	shell_loop();
	ft_tabdel((void ***)&environ, sizeof(char *));
	return (0);
}
