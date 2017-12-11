/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:51:45 by briviere          #+#    #+#             */
/*   Updated: 2017/12/11 17:06:51 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H

# include "libft.h"

typedef struct	s_command {
	char	*command;
	char	**arg;
	char	**env;
}				t_command;

t_command	**parse_commands(const char *str);
void		shell_loop(char **envp, char **epath);

#endif
