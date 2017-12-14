/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:51:45 by briviere          #+#    #+#             */
/*   Updated: 2017/12/14 17:36:33 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H

# include "libft.h"
# include <sys/stat.h>
# include <unistd.h>

typedef struct		s_command {
	char	**env;
	char	*bin;
	char	**av;
}					t_command;

t_command			**parse_commands(const char *str);
void				shell_loop(void);

/*
** COMMAND
*/
char				*cmd_bin_path(char *cmd, const char *epath);
void				interpret(t_command *cmd);
void				free_command(t_command **cmd);

/*
** PARSING
*/
char				*parse_ident(const char *str, size_t *idx);
char				**parse_envs(const char *str, size_t *idx);
char				*parse_cmd(const char *str, size_t *idx);
char				**parse_args(const char *str, size_t *idx);

/*
** ENV
*/
extern char			**environ;

/*
** BUILTINS
*/
int					get_builtin(char *bin);
int					builtin_echo(int ac, char **av, char **envp);
int					builtin_exit(int ac, char **av, char **envp);
int					builtin_cd(int ac, char **av, char **envp);
int					builtin_setenv(int ac, char **av, char **envp);
int					builtin_unsetenv(int ac, char **av, char **envp);

typedef struct		s_builtin_fn {
	char	name[255];
	int		(*ptr)(int ac, char **av, char **envp);
}					t_builtin_fn;

static t_builtin_fn	g_builtins[] = {
	{"echo", builtin_echo},
	{"exit", builtin_exit},
	{"cd", builtin_cd},
	{"env", builtin_setenv},
	{"setenv", builtin_setenv},
	{"unsetenv", builtin_unsetenv}
};

#endif
