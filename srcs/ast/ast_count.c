/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:02:08 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/17 17:32:15 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		count_node(t_node *node, int *count)
{
	if (node->type == ARG)
	{
		(*count)++;
		node->arg_id = (*count);
	}
	return (0);
}


void	btree_prefix_count(t_node *node, int *count)
{
	if (!node)
		return ;
	count_node(node, count);
	if (node->left)
		btree_prefix_count(node->left, count);
	if (node->right)
		btree_prefix_count(node->right, count);
}
