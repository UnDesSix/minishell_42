/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:35:28 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/22 18:42:33 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	check_node(t_node *node)
{
	if (node->type == PIPE)
	{
		if (node->right == NULL || node->left == NULL)
		{
			printf("msh: syntax error\n");
			return (-1);
		}
	}
	if (node->type == REDI)
	{
		if (node->file_name == NULL)
		{
			printf("msh: syntax error\n");
			return (-1);
		}
	}
	return (0);
}

int	check_ast(t_node *node)
{
	int x;

	x = 0;
	if (node->left)
		if (check_ast(node->left) == -1)
			return (-1);
	if (node->right)
		if (check_ast(node->right) == -1)
			return (-1);
	if (check_node(node) == -1)
		return (-1);
	return (0);
}
