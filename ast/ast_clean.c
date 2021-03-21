/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:02:10 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/21 15:21:49 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		clean_node(t_node *node)
{
	if (node->type == PIPE)
	{
		close(node->pfd[0]);
		close(node->pfd[1]);
		if (node->pfd)
			free(node->pfd);
	}
	else if (node->type == ARG)
	{
		free(node->word);
		if (node->redi_right_fd >= 0)
			close(node->redi_right_fd);
		if (node->redi_left_fd >= 0)
			close(node->redi_left_fd);
		if (node->pfd_input != STDOUT)
			close(node->pfd_input);
		if (node->pfd_output != STDIN)
			close(node->pfd_output);
	}
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
