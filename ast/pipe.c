/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:t +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:02:08 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/18 23:37:26 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		pipe_arg(t_node *node, t_saver *saver, int flag)
{
	int tmp_output;

	node->pfd_input = 0;
	node->pfd_output = 1;
	printf("saver->redi_fd : %d\n", saver->redi_fd);
	printf("arg ID / TOTAL %d / %d\n", node->arg_id, saver->arg_nb);
	if (saver->curr_pfd == NULL)
	{
		printf("I GO HERE 0\n");
		if (saver->redi_on == TRUE)
		{
			printf("I GO HERE 4\n");
			node->pfd_output = saver->redi_fd;
			saver->redi_on = FALSE;
		}
		return (0);
	}
	if (saver->past_pfd == NULL && node->arg_id < saver->arg_nb)
	{
		printf("I GO HERE 1\n");
		if (saver->redi_on == TRUE)
		{
			printf("I GO HERE 1.4\n");
			node->pfd_output = saver->redi_fd;
			saver->redi_on = FALSE;
		}
		else
		{
			printf("I GO HERE 1.5\n");
			node->pfd_output = saver->curr_pfd[1];
		}
	}
	else if (node->arg_id < saver->arg_nb)
	{
		printf("I GO HERE 2\n");
		node->pfd_input = saver->past_pfd[0];
		node->pfd_output = saver->curr_pfd[1];
	}
	else
	{
		printf("I GO HERE 3\n");
		node->pfd_input = saver->curr_pfd[0];
	}
//	printf("PIPE : CMD    : %s\n", node->args[0]);
//	printf("PIPE : input  : %d\n", node->pfd_input);
//	printf("PIPE : output : %d\n\n", node->pfd_output);
	return (0);
}

int		pipe_pipe(t_node *node, t_saver *saver)
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
		pipe_pipe(node, saver);
	else if(node->type == REDI)
		manage_redi(node, saver);
	else if (node->type == ARG)
		pipe_arg(node, saver, flag);
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
