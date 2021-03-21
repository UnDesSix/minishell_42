/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:04:29 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/21 12:52:05 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		ast_run(t_node *root, t_list *begin_list)
{
	t_saver	*saver;
	int		status;
	int		ret;

	ret = 0;
	saver = malloc(sizeof(t_saver));
	saver->arg_nb = 0;
	saver->past_pfd = NULL;
	saver->curr_pfd = NULL;
	saver->envp_list = begin_list;
	saver->redi_on = FALSE;
	btree_prefix_count(root, &(saver->arg_nb));
	btree_prefix_pipe(root, saver, 2);
	ret = btree_prefix_exec(root, saver, 2);
	if (ret != 2)
	{
		if (ret == -2)
		{
			btree_prefix_clean(root);
			free(saver);
			return (-2);
		}
//		printf("AFTER_EXEC____> [%d], WAIT->[%d]\n", g_proc.ret, status);
		while (wait(&status) > 0)
			;
		if (g_proc.ret == -1 || status == 0)
			g_proc.ret = status / 256;
	}
	//		g_proc.ret = 0;
	if (g_proc.ret == 3)
		g_proc.ret = 131;
//	printf("AFTER_WAIT____> [%d], WAIT->[%d]\n", g_proc.ret, status);
	btree_prefix_clean(root);
	free(saver);
	return (0);
}
