/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:26:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/04 21:25:20 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int	ft_manage_line(char *line, char **envp, t_list *begin_list)
{
	t_word	*word;
	int		x;

	x = 0;
	word = ft_lexer(line);

	if (ft_strcmp(word[0].content, "env") == 0)
		env_builtin(begin_list, word);
	else if (ft_strcmp(word[0].content, "unset") == 0)
		unset_builtin(&begin_list, word);
	else if (ft_strcmp(word[0].content, "export") == 0)
		export_builtin(begin_list, word);		

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
	t_list	*begin_list;

	ret = 0;
	line = NULL;
	ft_putstr("➜ msh ");
	begin_list = tabs_to_list(envp);
	while (get_next_line(0, &line) != 0)
	{
		if (line)
			ret = ft_manage_line(line, envp, begin_list);
		ft_putstr("➜ msh ");
		free(line);
	}
	free(line);
	ft_list_clear(begin_list, free_var);
	return (0);
}
