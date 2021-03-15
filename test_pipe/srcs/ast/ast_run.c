/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:04:29 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/13 15:11:54 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		ast_run(t_node *root, t_list *begin_list)
{
	t_saver	*saver;

	saver = malloc(sizeof(t_saver));
	saver->past_pfd = NULL;
	saver->current_pfd = NULL;
	saver->envp_list = begin_list;
	btree_prefix_exec(root, saver, 2);
	wait(NULL);
	btree_prefix_clean(root);
	free(saver);
	return (0);
}
