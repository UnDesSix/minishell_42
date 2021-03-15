/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:02:08 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/13 21:20:23 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		exec_arg(t_node *node, t_saver *saver, int flag)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		printf("Process issues.\n");
		return (-1);
	}
	if (pid == 0)
	{
	node->envp = list_to_tabs(saver->envp_list, 0);
		if (flag == 1)
		{
			if (saver->past_pfd)
			{
				close(saver->past_pfd[1]);
				close(0);
				dup(saver->past_pfd[0]);
			}
			close(saver->current_pfd[0]);
			close(1);
			dup(saver->current_pfd[1]);
		}
		else if (flag == 0)
		{
			close(saver->current_pfd[1]);
			close(0);
			dup(saver->current_pfd[0]);
		}
		execve(node->cmd, node->args, node->envp);
		exit(0);
	}
	return (0);
}

int		exec_pipe(t_node *node, t_saver *saver)
{
	if (saver->current_pfd != NULL)
		saver->past_pfd = saver->current_pfd;
	else
		saver->past_pfd = NULL;
	node->pfd = malloc(sizeof(int) * 2);
	if (pipe(node->pfd) < 0)
	{
		printf("Pipe issues.\n");
		return (-1);
	}
	saver->current_pfd = node->pfd;
	return (0);
}

int		exec_node(t_node *node, t_saver *saver, int flag)
{
	if (node->type == PIPE)
		exec_pipe(node, saver);
//	else if(node->type == REDI)
//		execute_arg(node, saver);
	else if (node->type == ARG)
		exec_arg(node, saver, flag);
	return (0);
}


void	btree_prefix_exec(t_node *node, t_saver *saver, int flag)
{
	if (!node)
		return ;
	exec_node(node, saver, flag);
	if (node->left)
		btree_prefix_exec(node->left, saver, 1);
	if (node->right)
		btree_prefix_exec(node->right, saver, 0);
}
