/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:51:45 by briviere          #+#    #+#             */
/*   Updated: 2017/12/12 12:33:11 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H

# include "libft.h"
# include <sys/stat.h>
# include <unistd.h>

typedef struct	s_command {
	char	**env;
	char	*bin;
	char	**av;
}				t_command;

t_command	**parse_commands(const char *str, const char **envp);
void		shell_loop(char **envp);

/*
** COMMAND
*/
char		*cmd_bin_path(char *cmd, const char *epath);
void		interpret(t_command *cmd);

/*
** PARSING
*/
char		*parse_ident(const char *str, size_t *idx);
char		**parse_envs(const char *str, size_t *idx);
char		*parse_cmd(const char *str, size_t *idx);
char		**parse_args(const char *str, size_t *idx);

#endif
