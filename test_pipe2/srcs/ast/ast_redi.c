/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_redi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:14:56 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/15 12:53:13 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
 *	FT_HANDLE_REDI_TYPE -> defines the node's type of redirection according
 *	to the given string
 */

void	ft_handle_redi_type(char *str, t_node *node)
{
	if (ft_strcmp(str, ">>") == 0)
		node->redi_type = DOUBLE_R;
	else if (ft_strcmp(str, ">") == 0)
		node->redi_type = SIMPLE_R;
	else
		node->redi_type = SIMPLE_L;
}

/*
 *	FT_LEFT_BRANCH_REDI -> Checks if redirections isn't first word
 *	if so it sets it to NULL else it calls the recursion
 */

int	ft_left_branch_redi(t_node *node, t_word *word, t_ast_var ast_var, t_list *begin_list)
{
	if (ast_var.i == 0)
		node->right = NULL;
	else
		if (ft_manage_branch(word, &node->right, ast_var, begin_list) < 0)
			return (-1);
	return (0);
}

/*
 *	FT_WHILE_REDI -> checks for redirections in array of word
 *	if it finds one, it defines the type of redirection and 
 *	it creates a node. Then it calls the recursion for both branchs
 */

int	ft_while_redi(t_word *word, t_ast_var ast_var, t_node *node, t_list *begin_list)
{
	char	*tmp_word;
	int		tmp_i;

	ast_var.i = ast_var.index;
	while (word[ast_var.i].content)
	{
		if (ft_strcmp(word[ast_var.i].content, ">") == 0
			|| ft_strcmp(word[ast_var.i].content, "<") == 0
			|| ft_strcmp(word[ast_var.i].content, ">>") == 0)
		{
			ft_handle_redi_type(word[ast_var.i].content, node);
			fill_node(node, REDI, NULL, word[ast_var.i + 1].content);
			tmp_i = ast_var.index;
			ast_var.index = ast_var.i + 2;
			if (ft_manage_branch(word, &node->left, ast_var, begin_list) < 0)
				return (-1);
			ast_var.index = tmp_i;
			tmp_word = ft_strdup(word[ast_var.i].content);
			free(word[ast_var.i].content);
			word[ast_var.i].content = NULL;
			if (ft_left_branch_redi(node, word, ast_var, begin_list) < 0)
				return (-1);
			word[ast_var.i].content = tmp_word;
			return (1);
		}
		ast_var.i++;
	}
	return (0);
}
