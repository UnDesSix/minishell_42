/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:02:10 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/22 17:47:10 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	change_underscore_var(t_node *node, t_list *begin_list, t_saver *saver)
{
	t_list	*elm_found;
	int		i;

	i = 0;
	if (node->arg_id == saver->arg_nb)
	{
		while (node->args[i] && node->args[i + 1])
			i++;
		elm_found = ft_list_find(begin_list, "_", ft_strcmp);
		free(((t_var *)elm_found->data)->content);
		if (ft_strcmp("$_", node->args[i]))
			((t_var *)elm_found->data)->content = ft_strdup(node->args[i]);
		else
			((t_var *)elm_found->data)->content = ft_strdup("");
	}
}

int		clean_node(t_node *node)
{
	if (node->type == PIPE)
	{
		close(node->pfd[0]);
		close(node->pfd[1]);
		if (node->pfd)
			free(node->pfd);
	}
	else if (node->type == ARG)
	{
		free(node->word);
		if (node->redi_right_fd >= 0)
			close(node->redi_right_fd);
		if (node->redi_left_fd >= 0)
			close(node->redi_left_fd);
		if (node->pfd_input != STDOUT)
			close(node->pfd_input);
		if (node->pfd_output != STDIN)
			close(node->pfd_output);
	}
	return (0);
}

void	btree_prefix_clean(t_node *node)
{
	if (!node)
		return ;
	clean_node(node);
	if (node->left)
		btree_prefix_clean(node->left);
	if (node->right)
		btree_prefix_clean(node->right);
}
