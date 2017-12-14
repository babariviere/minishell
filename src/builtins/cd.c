/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:00:17 by briviere          #+#    #+#             */
/*   Updated: 2017/12/14 09:35:42 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static char	*get_home(char **envp)
{
	char	*path;
	char	*home;

	home = ft_env_get(envp, "HOME");
	if (!home)
	{
		ft_putendl("HOME is not defined");
		return (0);
	}
	path = ft_strdup(home);
	return (path);
}

static char	*get_path(char *arg, char **envp)
{
	char	*path;
	char	*home;

	if (arg[0] == '~')
	{
		home = get_home(envp);
		if (!home)
			return (0);
		path = ft_strjoin(home, arg + 1);
		free(home);
	}
	else
		path = ft_strdup(arg);
	return (path);
}

static int	check_err(char *path)
{

	struct stat	st;

	if (stat(path, &st) != 0)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(path);
		return (0);
	}
	if ((st.st_mode & S_IFDIR) == 0)
	{
		ft_putstr("cd: ");
		ft_putstr(path);
		ft_putendl(": not a directory");
		return (0);
	}
	return (1);
}

int			builtin_cd(int ac, char **av, char **envp)
{
	char	*path;
	int		res;

	if (ac == 1)
		path = get_home(envp);
	else if (ac == 2)
		path = get_path(av[1], envp);
	else
	{
		ft_putendl("cd: too many arguments");
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
