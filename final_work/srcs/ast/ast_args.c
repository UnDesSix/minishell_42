/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:14:08 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/15 12:30:41 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
 * FT_WHILE_ARGS -> transforms an array of word into an array of strings
 * then it set the node parameters according to this new array.
 */

int	ft_while_args(t_word *word, t_ast_var ast_var, t_node *node, t_list *begin_list)
{
	char	**tab;
	char	*tmp_cmd;

	if (word[ast_var.i].content)
	{
		tmp_cmd = ft_check_cmd(word[ast_var.i].content, begin_list);
		free(word[ast_var.i].content);
		word[ast_var.i].content = tmp_cmd;
		tab = ft_token_to_tab(&word[ast_var.i]);
		if (!tab)
			return (-1);
		node->args = tab;
		node->type = ARG;
		return (1);
	}
	return (0);
}
