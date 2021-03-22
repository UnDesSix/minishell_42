/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:07:19 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/22 18:24:40 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	return_cases_ast(t_node *root, t_word *word, t_list *begin_list)
{
	if (check_ast(root) == -1)
	{
		ft_free_words(word);
		ft_free_ast(root);
		return (1);
	}
	if (ast_run(root, begin_list) == -2)
	{
		ft_free_words(word);
		ft_free_ast(root);
		return (0);
	}
	ft_free_words(word);
	ft_free_ast(root);
	return (1);
}

int	ft_manage_line(char *orline, t_list *begin_list)
{
	t_word		*word;
	t_node		*root;
	t_ast_var	ast_var;
	char		*line;

	word = NULL;
	line = expansion(orline, begin_list);
	word = ft_lexer(line);
	if (!word)
		return (1);
	if (!ft_check_lexer(word))
		return (1);
	word = sort_word(word);
	if (!word)
		return (1);
	free(line);
	root = (t_node *)malloc(sizeof(t_node));
	ast_var.index = 0;
	ast_var.i = 0;
	ast(word, ast_var, root, begin_list);
	return (return_cases_ast(root, word, begin_list));
}
