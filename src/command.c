/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:07:01 by briviere          #+#    #+#             */
/*   Updated: 2017/12/11 12:20:01 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

t_lst		*parse_command(const char *str)
{
	t_lst	*res;
	char	*tmp;
	size_t	beg;
	size_t	end;

	res = 0;
	beg = 0;
	end = 0;
	while (str[end])
	{
		if (str[end] == '\'' || str[end] == '\"')
			; // TODO
		if (ft_iswhitespace(str[end]))
		{
			tmp = ft_strsub(str, beg, end - beg);
			ft_lstpush(&res, ft_lstnew(tmp, sizeof(char *)));
			ft_strdel(&tmp);
			while (str[end] && ft_iswhitespace(str[end]))
				end++;
			beg = end;
		}
		end++;
	}
	if (str[beg] && beg < end)
	{
		tmp = ft_strsub(str, beg, end - beg);
		ft_lstpush(&res, ft_lstnew(tmp, sizeof(char *)));
		ft_strdel(&tmp);
	}
	return (res);
}
