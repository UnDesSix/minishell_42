/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:26:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/15 19:01:45 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"
#define COUNT 5

void	ft_free_words(t_word *word)
{
	int	x;

	x = 0;
	while (word[x].content)
	{
//		print_word(word[x]);
		free(word[x].content);
		x++;
	}
	ft_putstr("\n");
	free(word);
}

int	ft_manage_line(char **line, t_list *begin_list)
{
	t_word	*word;
	t_node *root;
	t_saver *saver;
	t_ast_var	ast_var;

	*line = expansion(*line, begin_list);
	word = ft_lexer(*line);
	if (!word)
		return (0);
	if (word[0].content)
	{
		if (ft_strcmp(word[0].content, "exit") == 0)
		{
			ft_free_words(word);
			return (0);
		}
	}
	root = (t_node *)malloc(sizeof(t_node));
	ast_var.index = 0;
	ast_var.i = 0;
	ast(word, ast_var, root, begin_list);
	if (check_ast(root) == -1)
	{
		ft_free_words(word);
		return (1);
	}
	print2DUtil(root, 0);
	//saver = malloc(sizeof(t_saver));
	//saver->past_pfd = NULL;
	//saver->current_pfd = NULL;
	//saver->envp_list = begin_list;
//	btree_prefix_exec(root, saver, 0);
	ft_free_words(word);
	ft_free_ast(root);
	//free(saver);
	return (1);
}

int	get_input(t_list *begin_list)
{
	char	*line;
	int		ret;

	ret = 0;
	line = NULL;
	ft_putstr_fd("➜ msh ", 1);
	while (42)
	{
		ret = get_next_line(0, &line);
		if (line)
		{
			if (ret == 0)
				break ;
			ret = ft_manage_line(&line, begin_list);
			if (ret == 0)
				break;
			free(line);
		}
		ft_putstr_fd("➜ msh ", 1);
	}
	free(line);
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	t_list	*begin_list;

	begin_list = tabs_to_list(envp);
	get_input(begin_list);
	ft_list_clear(begin_list, free_var);
	return (0);
}
