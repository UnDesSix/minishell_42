/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:15:33 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/08 15:05:09 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
 * FT_WHILE_PIPE -> loops on the word table to find a pipe
 * if it does it will send on the right side of the pipe to the
 * right branch of the node. It will then call the recursion on this
 * right branch. After that it will do the exact same thing with the left 
 * branch. You'll notice that the pipe is replaced by a NULL word to define the
 * word tabs needed by the left branch. At the end it is put back to its
 * original state
 */

int	ft_while_pipe(t_word *word, int i, t_node *node, int index)
{
	i = index;
	while (word[i].content)
	{
		if (ft_strcmp(word[i].content, "|") == 0)
		{
			node->type = PIPE;
			if (ft_manage_branch(word, &node->right, i + 1) < 0)
				return (-1);
			free(word[i].content);
			word[i].content = NULL;
			if (ft_manage_branch(word, &node->left, index) < 0)
				return (-1);
			word[i].content = ft_strdup("|");
			return (1);
		}
		i++;
	}
	return (0);
}
