/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:15:33 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/15 12:56:28 by calide-n         ###   ########.fr       */
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

int	ft_while_pipe(t_word *word, t_ast_var ast_var, t_node *node, t_list *begin_list)
{
	int	tmp_index;
	ast_var.i = ast_var.index;
	while (word[ast_var.i].content)
	{
		if (ft_strcmp(word[ast_var.i].content, "|") == 0)
		{
			node->type = PIPE;
			tmp_index = ast_var.index;
			ast_var.index = ast_var.i + 1;
			if (ft_manage_branch(word, &node->right, ast_var, begin_list) < 0)
				return (-1);
			ast_var.index = tmp_index;
			free(word[ast_var.i].content);
			word[ast_var.i].content = NULL;
			if (ft_manage_branch(word, &node->left, ast_var, begin_list) < 0)
				return (-1);
			word[ast_var.i].content = ft_strdup("|");
			return (1);
		}
		ast_var.i++;
	}
	return (0);
}
