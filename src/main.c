/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:51:31 by briviere          #+#    #+#             */
/*   Updated: 2017/12/12 10:32:25 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"


int		main(int ac, char **av, char **envp)
{
	char	*path;
	char	**paths;

	(void)ac;
	(void)av;
	envp = ft_env_init((const char **)envp);
	path = ft_env_get(envp, "PATH");
	if (path)
		paths = ft_strsplit(path, ':');
	else
		paths = ft_memalloc(sizeof(char *));
	shell_loop(envp, paths);
	return (0);
}
