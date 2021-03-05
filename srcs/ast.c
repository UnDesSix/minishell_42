/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:38:38 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/05 22:20:38 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

t_node	*create_node(void *data, t_node *right, t_node *left)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->cmd = ft_strdup(data);
	node->right = right;
	node->left = left;
	return (node);
}

int	ast(t_word *word, int index, t_node *node)
{
	int	i;
	t_word	*tmp;

	i = index;
	tmp = word;
	while (word[i].content)
	{
		if (ft_strcmp(word[i].content,"|") == 0)
		{
			node->cmd = ft_strdup("|");
			node->right = (t_node *)malloc(sizeof(t_node));
			node->left = (t_node *)malloc(sizeof(t_node));
			ast(word, i + 1, node->right);
			word[i].content = NULL;
			ast(word, index, node->left);
			return (1);
		}
		i++;
	}
	i = index;
	while (word[i].content)
	{
		if (ft_strcmp(word[i].content,">") == 0 || ft_strcmp(word[i].content,"<") == 0)
		{
			node->cmd = ft_strdup(">");
			node->right = (t_node *)malloc(sizeof(t_node));
			node->left = (t_node *)malloc(sizeof(t_node));
			//node->right->right = (t_node *)malloc(sizeof(t_node));
			//node->left->cmd = word[i + 1].content;
			word[i].content = NULL;
			ast(word, index, node->right);
			node = node->left;
		}
		i++;
	}
	i = index;
	while (word[i].content)
	{
		if (ft_strcmp(word[i].content, "echo") == 0 || ft_strcmp(word[i].content,"ls") == 0)
		{
			node->cmd = ft_strdup(word[i].content);
			return (1);
		}
		i++;
	}
	return (0);
}
