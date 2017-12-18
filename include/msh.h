/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:51:45 by briviere          #+#    #+#             */
/*   Updated: 2017/12/18 15:17:13 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H

# include "libft.h"
# include <signal.h>
# include <sys/param.h>
# include <sys/stat.h>
# include <unistd.h>

typedef struct		s_command {
	char	**env;
	char	*bin;
	char	**av;
}					t_command;

t_command			**parse_commands(const char *str);
t_command			*parse_command(const char *str);
void				shell_loop(void);
void				put_shell_prompt(void);

/*
** PROCESS
*/
int					g_running_pid;
void				sigint_handler(int sig);

/*
** COMMAND
*/
char				*cmd_bin_path(char *cmd, const char *epath);
int					interpret(t_command *cmd);
void				free_command(t_command **cmd);

/*
** PARSING
*/
char				*parse_ident(const char *str, size_t *idx);
char				**parse_envs(const char *str, size_t *idx);
char				*parse_cmd_str(const char *str, size_t *idx);
char				**parse_args(const char *str, size_t *idx);

/*
** ENV
*/
void				print_env(char **envp);
char				*extract_env(char *str);
char				*substitute_env(char *str);

/*
** BUILTINS
*/
int					get_builtin(char *bin);
int					builtin_echo(int ac, char **av, char **envp);
int					builtin_exit(int ac, char **av, char **envp);
int					builtin_cd(int ac, char **av, char **envp);
int					builtin_env(int ac, char **av, char **envp);
int					builtin_setenv(int ac, char **av, char **envp);
int					builtin_unsetenv(int ac, char **av, char **envp);

typedef struct		s_builtin_fn {
	char	name[255];
	int		(*ptr)(int ac, char **av, char **envp);
}					t_builtin_fn;

static t_builtin_fn	g_builtins[] = {
	{"echo", builtin_echo},
	{"cd", builtin_cd},
	{"exit", builtin_exit},
	{"env", builtin_env},
	{"setenv", builtin_setenv},
	{"unsetenv", builtin_unsetenv}
};

#endif
