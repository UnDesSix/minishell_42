/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:26:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/02 15:37:10 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"
# define PIPE 3
# define EXEC 4

t_node	*ft_create_node(int type, char *content, t_node *left, t_node *right)
{
	t_node *node = malloc(sizeof(t_node));

	node->type = type;
	node->content = content;
	node->left = left;
	node->right = right;
	return (node);
}

int	evaluate(t_node *node)
{
	if (node->type == EXEC)
	{
		printf("executing %s\n", node->left->content);
		return (0);
	}
	if (node->type == PIPE)
	{
		printf("Pipe\n");
		evaluate(node->right);
		evaluate(node->left);
		return (0);
	}
	return (0);
}

int	ft_manage_line(char *line, char **envp)
{
	t_block	*block;
	int index;
	int windex = 0;
	t_word	*word;

	index = 0;
	block = ft_get_blocks(line);

	t_node *root_node;
	t_node *first;
	t_node *first_arg;
	t_node *sec;
	t_node *sec_arg;

	first = ft_create_node(CMD, block[0].word[0].content, NULL, NULL);
	first_arg = ft_create_node(ARG, block[0].word[1].content, NULL, NULL);
	sec = ft_create_node(CMD, block[1].word[0].content, NULL, NULL);
	printf("ici -> %s\n", block[1].word[0].content);
	sec_arg = ft_create_node(ARG, block[1].word[1].content, NULL, NULL);
	root_node = ft_create_node(PIPE, NULL, NULL, NULL);
	root_node->left = ft_create_node(EXEC, NULL, first, first_arg);
	root_node->right = ft_create_node(EXEC, NULL, sec, sec_arg);

	evaluate(root_node);

	index = 0;
	while (block[index].stop)
	{
		//		ft_execute_block(block[index]);
		free(block[index].word);
		index++;
	}
	free(block);
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	char	*line;

	ft_putstr("➜ msh ");
	while (get_next_line(0, &line) != 0)
	{
		ft_manage_line(line, envp);
		ft_putstr("➜ msh ");
		free(line);
	}
	free(line);
	return (0);
}
