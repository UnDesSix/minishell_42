/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:14:03 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/22 17:54:43 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		manage_endof_line(char *line, int i,
		t_list *begin_list, int begin)
{
	i--;
	while (line[i] == ' ')
		i--;
	if (begin <= i)
		if (ft_manage_line(&line[begin], begin_list) == 0)
			return (0);
	return (1);
}

int		check_semicolon_error(int i, char *lol)
{
	if (lol[i + 1] == ';' || i == 0)
	{
		printf("msh: syntax error near unexpected token `;'\n");
		g_proc.ret = 256;
		return (1);
	}
	return (0);
}

int		check_end_after_semicolon(char *lol, int i)
{
	while (lol[i] == ' ')
		i++;
	if (lol[i] == '\0')
		return (0);
	return (1);
}

void	check_ifs(char *lol, int *i, char *stop)
{
	if (lol[*i] == '\\')
		*i += 1;
	else if (lol[*i] == '"' && *stop == ' ')
		*stop = lol[*i];
	else if (lol[*i] == '\'' && *stop == ' ')
		*stop = lol[*i];
	else if ((lol[*i] == '"' || lol[*i] == ' ') && *stop == lol[*i])
		*stop = ' ';
}

int		divide_lines(char *line, t_list *begin_list)
{
	int		i;
	int		begin;
	char	stop;
	char	*lol;

	i = -1;
	begin = 0;
	stop = ' ';
	lol = line;
	while (lol[++i])
	{
		check_ifs(lol, &i, &stop);
		if (lol[i] == ';' && stop == ' ')
		{
			if (check_semicolon_error(i, lol))
				return (1);
			if (!check_end_after_semicolon(lol, i))
				break ;
			lol[i] = '\0';
			if (ft_manage_line(&line[begin], begin_list) == 0)
				return (0);
			begin = i + 1;
		}
	}
	return (manage_endof_line(line, i, begin_list, begin));
}
