/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_redi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:14:56 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/21 23:53:20 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	ft_handle_redi_type(char *str, t_node *node)
{
	if (ft_strcmp(str, ">>") == 0)
		node->redi_type = DOUBLE_R;
	else if (ft_strcmp(str, ">") == 0)
		node->redi_type = SIMPLE_R;
	else
		node->redi_type = SIMPLE_L;
}

int		ft_left_branch_redi(t_node *node, t_word *word,
		t_ast_var ast_var, t_list *begin_list)
{
	if (ast_var.i == 0)
		node->right = NULL;
	else if (ft_manage_branch(word, &node->right, ast_var, begin_list) < 0)
		return (-1);
	return (0);
}

void	free_null_word(t_word *word, int i)
{
	free(word[i].content);
	word[i].content = NULL;
}

int		ft_while_redi(t_word *word, t_ast_var ast_var,
		t_node *node, t_list *begin_list)
{
	char	*tmp_word;
	int		tmp_i;

	while (word[ast_var.i].content)
	{
		if (word_is_redi(word[ast_var.i].content) &&
				word[ast_var.i].sep == 0)
		{
			ft_handle_redi_type(word[ast_var.i].content, node);
			fill_node(node, REDI, NULL, word[ast_var.i + 1].content);
			tmp_i = ast_var.index;
			ast_var.index = ast_var.i + 2;
			if (ft_manage_branch(word, &node->left, ast_var, begin_list) < 0)
				return (-1);
			ast_var.index = tmp_i;
			tmp_word = ft_strdup(word[ast_var.i].content);
			free_null_word(word, ast_var.i);
			if (ft_left_branch_redi(node, word, ast_var, begin_list) < 0)
				return (-1);
			word[ast_var.i].content = tmp_word;
			return (1);
		}
		ast_var.i++;
	}
	return (0);
}
