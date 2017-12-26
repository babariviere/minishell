/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:24:41 by briviere          #+#    #+#             */
/*   Updated: 2017/12/26 09:01:19 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static void		echo_str_antislash(char *str, size_t *beg, size_t *end,
		int *prev_anti)
{
	write(1, str + *beg, *end - *beg - 1);
	*beg = *end + 1;
	*prev_anti = 1;
}

static void		echo_str(char *str)
{
	size_t	beg;
	size_t	end;
	int		prev_anti;

	prev_anti = 0;
	beg = 0;
	end = 0;
	while (str[end])
	{
		if (str[end] == '\\' && prev_anti == 0)
			echo_str_antislash(str, &beg, &end, &prev_anti);
		else if (prev_anti)
		{
			ft_putchar(str[end]);
			beg = end + 1;
			prev_anti = 0;
		}
		end++;
	}
	write(1, str + beg, end - beg);
	ft_putchar('\n');
}

int				builtin_echo(int ac, char **av, char **envp)
{
	char	*res;

	(void)ac;
	(void)envp;
	res = ft_strtab_join_sep(av + 1, ' ');
	echo_str(res);
	free(res);
	return (0);
}
