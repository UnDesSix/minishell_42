/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_std_inout.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:10:27 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/22 20:01:02 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		define_std_inout_1(t_node *node, t_saver *saver)
{
	if (saver->redi_left == TRUE)
	{
		node->pfd_input = saver->redi_left_fd;
		saver->redi_left = FALSE;
	}
	if (saver->redi_right == TRUE)
	{
		node->pfd_output = saver->redi_right_fd;
		saver->redi_right = FALSE;
	}
	return (0);
}

int		define_std_inout_2(t_node *node, t_saver *saver)
{
	if (saver->redi_left == TRUE)
	{
		node->pfd_input = saver->redi_left_fd;
		saver->redi_left = FALSE;
	}
	if (saver->redi_right == TRUE)
	{
		node->pfd_output = saver->redi_right_fd;
		saver->redi_right = FALSE;
	}
	else
		node->pfd_output = saver->curr_pfd[1];
	return (0);
}

int		define_std_inout_3(t_node *node, t_saver *saver)
{
	if (saver->redi_left == TRUE)
	{
		node->pfd_input = saver->redi_left_fd;
		saver->redi_left = FALSE;
	}
	else
		node->pfd_input = saver->past_pfd[0];
	if (saver->redi_right == TRUE)
	{
		node->pfd_output = saver->redi_right_fd;
		saver->redi_right = FALSE;
		close(saver->curr_pfd[1]);
	}
	else
		node->pfd_output = saver->curr_pfd[1];
	return (0);
}

int		define_std_inout_4(t_node *node, t_saver *saver)
{
	if (saver->redi_left == TRUE)
	{
		node->pfd_input = saver->redi_left_fd;
		saver->redi_left = FALSE;
	}
	else
		node->pfd_input = saver->curr_pfd[0];
	if (saver->redi_right == TRUE)
	{
		node->pfd_output = saver->redi_right_fd;
		saver->redi_right = FALSE;
	}
	return (0);
}

int		define_std_inout(t_node *node, t_list *begin_list, t_saver *saver)
{
	(void)begin_list;
	node->pfd_input = 0;
	node->pfd_output = 1;
	node->redi_right_fd = -2;
	node->redi_left_fd = -2;
	node->redi_open = saver->redi_open;
	if (saver->curr_pfd == NULL)
		return (define_std_inout_1(node, saver));
	if (saver->past_pfd == NULL && node->arg_id < saver->arg_nb)
		define_std_inout_2(node, saver);
	else if (node->arg_id < saver->arg_nb)
		define_std_inout_3(node, saver);
	else
		define_std_inout_4(node, saver);
	return (0);
}
