/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:02:10 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/13 17:19:39 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		clean_node(t_node *node)
{
	if (node->type == PIPE)
	{
		close(node->pfd[0]);
		close(node->pfd[1]);
		free(node->pfd);
	}
//	else if(node->type == REDI)
//		execute_arg(node, saver);
//	else if (node->type == ARG)
//	{
//		free(node->envp);
//		printf("B\n");
//	}
	return (0);
}

void	btree_prefix_clean(t_node *node)
{
	if (!node)
		return ;
	clean_node(node);
	if (node->left)
		btree_prefix_clean(node->left);
	if (node->right)
		btree_prefix_clean(node->right);
}

