/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:51:45 by briviere          #+#    #+#             */
/*   Updated: 2017/12/12 11:16:34 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H

# include "libft.h"

typedef struct	s_command {
	char	*command;
	int		ac;
	char	**av;
	char	**env;
}				t_command;

t_command	**parse_commands(const char *str, char **envp, char **epath);
void		shell_loop(char **envp, char **epath);

/*
** PARSING
*/
char		*parse_ident(const char *str, size_t *idx);
char		**parse_envs(const char *str, size_t *idx);

#endif
