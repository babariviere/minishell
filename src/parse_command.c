/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:07:01 by briviere          #+#    #+#             */
/*   Updated: 2017/12/11 17:19:44 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static size_t	command_size(const char *str)
{
	size_t		count;
	size_t		level;

	count = 1;
	level = 0;
	while (*str)
	{
		if (*str == ';')
			return (count);
		if (*str == '\'' || *str == '\"')
			str += ft_skip_until(str, *str);
		if (ft_iswhitespace(*str))
		{
			count++;
			while (ft_iswhitespace(*str))
				str++;
		}
		else
			str++;
	}
	return (count);
}

t_command		*parse_command(const char *str)
{
	char		*tmp;
	size_t		begin;
	size_t		end;

	begin = 0;
	end = 0;
	while (str[end])
	{
		if (ft_iswhitespace(str[end]))
		{
			tmp = ft_strsub(str, begin, end);
			begin = end;
			while (ft_iswhitespace(str[end]) && str[end + 1])
				end++;
			// TODO: create function to check if it's env variable
			// TODO: create function to concat env
		}

		end++;
	}
	return ((char *)str);
}

t_command		**parse_commands(const char *str)
{
	t_command	**cmds;
	char		*tmp;
	size_t		idx;
	size_t		len;

	len = command_size(str);
	if ((cmds = ft_memalloc(sizeof(t_command *) * (len + 1))) == 0)
		return (0);
	idx = 0;
	tmp = (char *)str;
	while (idx < len)
	{
		cmds[idx++] = parse_command(tmp);
		tmp = ft_strchr(tmp, ';');
		if (tmp != 0)
			tmp += 1;
	}
	return (cmds);
}
