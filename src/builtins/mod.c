/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:12:12 by briviere          #+#    #+#             */
/*   Updated: 2017/12/12 16:56:33 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

int		get_builtin(char *str)
{
	size_t		idx;

	idx = 0;
	while (idx < (sizeof(g_builtins) / sizeof(g_builtins[0])))
	{
		if (ft_strcmp(str, g_builtins[idx].name) == 0)
			return (idx);
		idx++;
	}
	return (-1);
}
