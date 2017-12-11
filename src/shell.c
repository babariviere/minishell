/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:02:00 by briviere          #+#    #+#             */
/*   Updated: 2017/12/11 12:23:25 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void		print_command(t_lst *elem)
{
	ft_putendl(elem->content);
}

void		shell_loop(void)
{
	char	*readed;
	t_lst	*cmd;

	while (1)
	{
		ft_putstr("> ");
		if (ft_gnl(0, &readed) <= 0)
		{
			ft_putendl("exit");
			break ;
		}
		cmd = parse_command(readed);
		ft_lstiter(cmd, print_command);
		if (ft_strcmp(cmd->content, "exit") == 0)
			break ;
		ft_putendl("command not found");
	}
}
