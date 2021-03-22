/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:04:29 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/22 16:15:45 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		get_return(int ret, t_node *root, t_saver *saver)
{
	int	status;

	if (ret != 2)
	{
		if (ret == -2)
		{
			btree_prefix_clean(root);
			free(saver);
			return (-2);
		}
		while (wait(&status) > 0)
			;
		if (g_proc.ret == -1 || status == 0)
			g_proc.ret = status / 256;
	}
	if (g_proc.ret == 3)
		g_proc.ret = 131;
	return (0);
}

int		ast_run(t_node *root, t_list *begin_list)
{
	t_saver	*saver;
	int		ret;

	ret = 0;
	saver = malloc(sizeof(t_saver));
	saver->arg_nb = 0;
	saver->redi_right = FALSE;
	saver->redi_left = FALSE;
	saver->past_pfd = NULL;
	saver->curr_pfd = NULL;
	saver->envp_list = begin_list;
	btree_prefix_count(root, &(saver->arg_nb));
	btree_prefix_pipe(root, begin_list, saver);
	ret = btree_prefix_exec(root, saver);
	if (get_return(ret, root, saver) == -2)
		return (-2);
	btree_prefix_clean(root);
	free(saver);
	return (0);
}
