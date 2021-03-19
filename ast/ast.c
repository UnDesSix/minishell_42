/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:38:38 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/17 10:12:13 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
** AST -> builds an AST (Abstract Syntax Tree)
** The order of priority in the tree is
** [|] -> [>][<][>>] -> cmd/files/args
** pipe	redirections	the rest
*/

int	ast(t_word *word, t_ast_var ast_var, t_node *node, t_list *begin_list)
{
	t_word	*tmp;
	int		ret;

	set_node(node);
	if (!word[ast_var.index].content)
		return (0);
	ast_var.i = ast_var.index;
	ret = ft_while_pipe(word, ast_var, node, begin_list);
	if (ret != 0)
		return (ret);
	ret = ft_while_redi(word, ast_var, node, begin_list);
	if (ret != 0)
		return (ret);
	ret = ft_while_args(word, ast_var, node, begin_list);
	if (ret != 0)
		return (ret);
	return (0);
}
