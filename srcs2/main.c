/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:26:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/04 20:16:11 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int	ft_manage_line(char *line, char **envp)
{
	t_word	*word;
	int		x;

	x = 0;
	word = ft_lexer(line);
	while (word[x].content)
	{
		printf("[%s] space=%d sep=%d\n", word[x].content,  word[x].space,  word[x].sep);
		free(word[x].content);
		x++;
	}
	free(word);
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	char	*line;
	int		ret;

	ret = 0;
	line = NULL;
	ft_putstr("➜ msh ");
	while (get_next_line(0, &line) != 0)
	{
		if (line)
			ret = ft_manage_line(line, envp);
		ft_putstr("➜ msh ");
		free(line);
	}
	if (ret == -1)
		exit(0);
	return (0);
}
