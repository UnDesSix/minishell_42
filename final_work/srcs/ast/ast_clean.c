/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:02:10 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/18 10:16:16 by mlarboul         ###   ########.fr       */
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
//	else if(node->type == REDI)
//		execute_arg(node, saver);
	if (node->type == ARG)
	{

		if (node->pfd_input != STDOUT)
		{
//			printf("CLEAN : CMD    : %s\n", node->args[0]);
//			printf("CLEAN : input  : %d\n", node->pfd_input);
//			printf("CLEAN : output : %d\n\n", node->pfd_output);
			close(node->pfd_input);
		}
		if (node->pfd_output != STDIN)
		{
//			printf("CLEAN : CMD    : %s\n", node->args[0]);
//			printf("CLEAN : input  : %d\n", node->pfd_input);
//			printf("CLEAN : output : %d\n\n", node->pfd_output);
			close(node->pfd_output);
		}
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

