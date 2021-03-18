/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:04:29 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/17 17:42:01 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		ast_run(t_node *root, t_list *begin_list)
{
	t_saver	*saver;

	saver = malloc(sizeof(t_saver));
	saver->arg_nb = 0;
	saver->past_pfd = NULL;
	saver->curr_pfd = NULL;
	saver->envp_list = begin_list;
	btree_prefix_count(root, &(saver->arg_nb));
	btree_prefix_pipe(root, saver, 2);
	btree_prefix_exec(root, saver, 2);
	while (wait(NULL) > 0)
		;
	btree_prefix_clean(root);
	free(saver);
	return (0);
}
