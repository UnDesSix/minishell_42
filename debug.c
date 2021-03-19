/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:48:07 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/15 18:28:15 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"
#define COUNT 5

void	print_word(t_word word)
{
	ft_putnbr_fd(word.space, 1); 
	ft_putstr(":");
	ft_putnbr_fd(word.sep, 1); 
	ft_putstr(":");
	ft_putstr(word.content);
	ft_putstr(" ");
}

void print2DUtil(t_node *root, int space)
{
	if (root == NULL)
		return;
	space += COUNT;
	print2DUtil(root->right, space);
	printf("\n");
	for (int i = COUNT; i < space; i++)
		printf(" ");
	if (root->type == PIPE)
		printf("PIPE\n");
	else if (root->type == REDI)
	{
		printf("REDI ");
		if (root->redi_type == SIMPLE_R)
			printf("[>] ");
		else if (root->redi_type == DOUBLE_R)
			printf("[>>] ");
		else if (root->redi_type == SIMPLE_L)
			printf("[<] ");
		printf("[%s]\n", root->file_name);
	}
	else if (root->type == FD)
		printf("FILE->[%s]\n", root->file_name);
	else
	{
		printf("CMD->[");
		int x = 0;
		while (root->args[x + 1])
		{
			printf("%s ", root->args[x]);
			x++;
		}
		printf("%s", root->args[x]);
		printf("]\n");
	}
	print2DUtil(root->left, space);
}

