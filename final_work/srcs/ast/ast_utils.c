/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:16:19 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/15 12:24:59 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
 * FT_MANAGE_BRANCH -> defines a branch depending on the given array of word.
 * If it's empty it sets the node to NULL. Else it will call the recursion
 * to create other nodes below the current one.
 */

int	ft_manage_branch(t_word *word, t_node **node, t_ast_var ast_var, t_list *begin_list)
{
	if (word[ast_var.index].content == NULL)
		*node = NULL;
	else
	{
		*node = (t_node *)malloc(sizeof(t_node));
		if (!(*node))
			return (-1);
		ast(word, ast_var, *node, begin_list);
	}
	return (0);
}

/*
 * FILL_NODE -> fills an existing node with the given data
 */

void	fill_node(t_node *node, int type, char *cmd, char *file_name)
{
	node->cmd = ft_strdup(cmd);
	node->file_name = ft_strdup(file_name);
	node->type = type;
}

/*
 * FT_TOKEN_TO_TAB -> creates an array of string from an array of word
 */

char	**ft_token_to_tab(t_word *word)
{
	int		i;
	char	**tab;

	i = 0;
	while (word[i].content)
		i++;
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (word[i].content)
	{
		tab[i] = word[i].content;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

/*
 * SET_NODE -> sets all the parameters of a node to a default value of
 * NULL or 0
 */

void	set_node(t_node *node)
{
	node->right = NULL;
	node->left = NULL;
	node->type = ARG;
	node->file_name = NULL;
	node->fd = 0;
	node->redi_type = 0;
	node->cmd = NULL;
	node->args = NULL;
}

/*
 * FT_FREE_AST -> frees the whole tree except the strings of node->args
 * which are part of the main token array. They are freed in another function.
 * The tree is freed from left to right
 */

void	ft_free_ast(t_node *node)
{
	int	x;

	x = 0;
	if (node->left)
		ft_free_ast(node->left);
	if (node->right)
		ft_free_ast(node->right);
	if (node->file_name)
		free(node->file_name);
	if (node->args)
		free(node->args);
	free(node);
	return ;
}
