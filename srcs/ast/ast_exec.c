#include "../includes/header.h"

int		exec_arg(t_node *node, t_saver *saver, int side)
{
	pid_t	pid;
	char	**new_envp;
	int		status;

	pid = fork();
	if (pid < 0)
	{
		printf("Process issues.\n");
		return (-1);
	}
	if (pid == 0)
	{
//		if (side == 0)
//			dup2(saver->current_pfd[1], 1);
//		if (side == 1)
//			dup2(saver->current_pfd[0], 0);
		new_envp = list_to_tabs(saver->envp_list, 0);
		execve(node->args[0], node->args, new_envp);
		exit(0);
	}
	else
		wait(&status);
	return (0);
}

int		exec_pipe(t_node *node, t_saver *saver)
{
	if (saver->current_pfd != NULL)
		saver->past_pfd = saver->current_pfd;
	else
		saver->past_pfd = NULL;
	if (pipe(node->pfd) < 0)
	{
		printf("Pipe issues.\n");
		return (-1);
	}
	saver->current_pfd = node->pfd;
	return (0);
}

int		exec_node(t_node *node, t_saver *saver, int side)
{
	if (node->type == PIPE)
		exec_pipe(node, saver);
	//	if (node->type == REDI)
	//		execute_arg(node, saver);
	if (node->type == ARG)
		exec_arg(node, saver, side);
	return (0);
}


void	btree_prefix_exec(t_node *node, t_saver *saver, int side)
{
	if (!node)
		return ;
	exec_node(node, saver, side);
	if (node->left)
		btree_prefix_exec(node->left, saver, 0);
	if (node->right)
		btree_prefix_exec(node->right, saver, 1);
}
