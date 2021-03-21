/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:23:28 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/21 15:23:42 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		manage_pipe(t_node *node, t_saver *saver)
{
	if (saver->curr_pfd != NULL)
		saver->past_pfd = saver->curr_pfd;
	node->pfd = malloc(sizeof(int) * 2);
	if (pipe(node->pfd) < 0)
	{
		printf("Pipe issues.\n");
		return (-1);
	}
	saver->curr_pfd = node->pfd;
	return (0);
}

int		pipe_node(t_node *node, t_saver *saver, int flag)
{
	if (node->type == PIPE)
		manage_pipe(node, saver);
	else if (node->type == REDI)
		manage_redi(node, saver);
	else if (node->type == ARG)
		define_std_inout(node, saver, flag);
	return (0);
}

void	btree_prefix_pipe(t_node *node, t_saver *saver, int flag)
{
	if (!node)
		return ;
	pipe_node(node, saver, flag);
	if (node->left)
		btree_prefix_pipe(node->left, saver, LEFT);
	if (node->right)
		btree_prefix_pipe(node->right, saver, RIGHT);
}
