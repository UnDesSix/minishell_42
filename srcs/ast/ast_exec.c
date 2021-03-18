/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:02:08 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/18 16:01:28 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		exec_arg(t_node *node, t_saver *saver, int flag)
{
	pid_t	pid;
	int		ret;

	pid = fork();
	if (pid < 0)
	{
		printf("Process issues.\n");
		return (-1);
	}
	if (pid == 0)
	{
		node->envp = list_to_tabs(saver->envp_list, 0);
//		printf("EXEC : CMD    : %s\n", node->args[0]);
//		printf("EXEC : input  : %d\n", node->pfd_input);
//		printf("EXEC : output : %d\n\n", node->pfd_output);
		if (node->pfd_input != STDOUT)
		{
			close(0);
			dup(node->pfd_input);
		}
		if (node->pfd_output != STDIN)
		{
			close(1);
			dup(node->pfd_output);
		}
		if (ft_is_builtin(node->word[0].content))
			exec_builtins(node->word, saver->envp_list);
		else
			execve(node->args[0], node->args, node->envp);
		exit(0);
	}
	g_proc.pid[g_proc.index] = pid;
	g_proc.index++;
	if (node->pfd_input != STDOUT)
		close(node->pfd_input);
	if (node->pfd_output != STDIN)
		close(node->pfd_output);
	return (0);
}

/*
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
 */

int		exec_node(t_node *node, t_saver *saver, int flag)
{
	//	if (node->type == PIPE)
	//		exec_pipe(node, saver);
	//	else if(node->type == REDI)
	//		execute_arg(node, saver);
	if (node->type == ARG)
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
