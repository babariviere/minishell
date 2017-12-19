/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:00:17 by briviere          #+#    #+#             */
/*   Updated: 2017/12/19 09:45:23 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static int	check_err(char *path)
{
	struct stat	st;

	if (stat(path, &st) != 0)
	{
		ft_putendl2_fd("cd: no such file or directory: ", path, 2);
		return (0);
	}
	if ((st.st_mode & S_IFDIR) == 0)
	{
		ft_putendl3("cd: ", path, ": not a directory");
		return (0);
	}
	return (1);
}

static char	*get_home(char **envp)
{
	char	*home;

	home = ft_env_get(envp, "HOME");
	if (!home)
	{
		ft_putendl("HOME is not defined");
		return (0);
	}
	return (home);
}

static char	*get_path(char *arg, char **envp)
{
	char	*path;
	char	*home;
	char	*tmp;

	path = substitute_env(arg);
	if (path == 0)
		return (0);
	if (arg[0] == '~')
	{
		home = get_home(envp);
		if (!home)
			return (0);
		tmp = path;
		path = ft_strjoin(home, arg + 1);
		free(tmp);
	}
	return (path);
}

int			builtin_cd(int ac, char **av, char **envp)
{
	char	*path;
	int		res;

	if (ac == 1)
		path = ft_strdup(get_home(envp));
	else if (ac == 2)
		path = get_path(av[1], envp);
	else
	{
		ft_putendl_fd("cd: too many arguments", 2);
		return (1);
	}
	if (!check_err(path))
		return (1);
	res = 1;
	if (path)
	{
		res = chdir(path);
		free(path);
	}
	return (res);
}
