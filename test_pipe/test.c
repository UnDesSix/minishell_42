void	btree_apply_prefix(t_node *root, void (*applyf)(void *), int pfd[2])
{
	if (!root)
		return ;
	(*applyf)(root, pfd);
	if (root->left)
		btree_apply_prefix(root->left, applyf, pfd); // fd[1]
	if (root->right)
		btree_apply_prefix(root->right, applyf, pfd); // fd[0]
}

exec_node(t_node *node, int pfd[2])
		if (pfd[0])
			tmp = pfd[0]
		else
			tmp = 0;
	if (type == PIPE)
	{
		pipe(pfd); // int pfd[2] => input fd[1] & output fd[0]
	}

	if (type == ARG)
	{
		execute_arg(node, struct s_pfd);
	}


execute_arg(t_node *node, int pfd[2], t_list *envp_list)
	t_pid	pid;
	char	**new_envp;

	pid = fork();
	if (pid < 0)
		ERROR
	if (pid == 0)
	{
		// CHILD
		close(fd[0]);
		cmd = look_for_binary();
		new_envp = list_to_tabs(envplist, 0);
		dup2(1, pfd[1]);
		dup2(0, tmp);
		execve(cmd, arg, envp);
	}
	else
	{
		// close(fd[1]); 
	}

	cat main.c  | grep "int"

	grep "int" main.c
