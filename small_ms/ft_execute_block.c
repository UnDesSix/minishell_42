/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_block.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:26:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/01 14:06:06 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

char **ft_block_to_tabs(t_block block)
{
	int		w;
	char	**tab;

	w = 0;
	while (block.word[w].content)
		w++;
	tab = malloc(sizeof(char *) * (w + 1));
	w = 0;
	while (block.word[w].content)
	{
		tab[w] = block.word[w].content;
		w++;
	}
	tab[w] = NULL;
	return (tab);
}

int	ft_execute_binary(char **tab)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
		execve(tab[0], tab, NULL);
	else
		wait(&status);
	return (0);
}

int	ft_execute_builtin(t_block block)
{
	return (0);
}

int ft_execute_block(t_block block)
{
	int 	w;
	char	**tab;
	char 	*tmp;
	char	*path;
	char 	**paths;
	int		i;

	w = 0;
	tab = ft_block_to_tabs(block);
	if (block.word[0].builtin == TRUE)
		ft_execute_builtin(block);
	else
		ft_execute_binary(tab);
	while (block.word[w].content)
	{
		free(tab[w]);
		w++;
	}
	free(tab);
	return (0);
}

