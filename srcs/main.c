/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:26:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/13 15:04:22 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"
#define COUNT 5

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

int	ft_manage_line(char **line, char **envp, t_list *begin_list)
{
	t_word	*word;
	char	*line_cpy;
	t_node *root;
	t_saver *saver;
	int		x;

	x = 0;
	*line = expansion(*line, begin_list);
	//	printf("%s\n", *line);
	word = ft_lexer(*line);
	if (!word)
		return (0);
	//	root = (t_node *)malloc(sizeof(t_node));
	//if (ft_strcmp(word[0].content, "env") == 0)
	//	env_builtin(begin_list, word);
	//else if (ft_strcmp(word[0].content, "unset") == 0)
	//	unset_builtin(&begin_list, word);
	//else if (ft_strcmp(word[0].content, "export") == 0)
	//	export_builtin(begin_list, word);
	//	ast(word, 0, root);
	//	saver = malloc(sizeof(t_saver));
	//    saver->past_pfd = NULL;
	//    saver->current_pfd = NULL;
	//    saver->envp_list = begin_list;
	//    btree_prefix_exec(root, saver, 0);

	///	print2DUtil(root, 0);
	while (word[x].content)
	{
		ft_putstr("[");
		ft_putstr(word[x].content);
		ft_putstr("]");
		ft_putstr(" ");
		free(word[x].content);
		x++;
	}
	ft_putstr("\n");
	//	ft_free_ast(root);
	free(word);
	return (0);
}

void	exit_ms(int signal)
{
	printf("exiting ms...\n");
	exit(0);
}

int main(int argc, char **argv, char **envp)
{
	char	*line;
	int		ret;
	t_list	*begin_list;

	ret = 0;
	line = NULL;
	ft_putstr("➜ msh ");
	begin_list = tabs_to_list(envp);
	signal(SIGINT, exit_ms);
	while (get_next_line(0, &line) != 0)
	{
		if (line)
		{
			printf("%s\n", line);
			ret = ft_manage_line(&line, envp, begin_list);
		}
		ft_putstr("➜ msh ");
		free(line);
	}
	free(line);
	ft_list_clear(begin_list, free_var);
	return (0);
}
