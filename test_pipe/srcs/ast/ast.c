/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:38:38 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/08 15:08:53 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
 * AST -> builds an AST (Abstract Syntax Tree)
 * The order of priority in the tree is
 *    [|] -> [>][<][>>] -> cmd/files/args 
 *    pipe	redirections	the rest
 */

int	ast(t_word *word, int index, t_node *node)
{
	int		i;
	t_word	*tmp;
	int		ret;

	set_node(node);
	if (!word[index].content)
		return (0);
	i = index;
	ret = ft_while_pipe(word, i, node, index);
	if (ret != 0)
		return (ret);
	ret = ft_while_redi(word, i, node, index);
	if (ret != 0)
		return (ret);
	ret = ft_while_args(word, i, node, index);
	if (ret != 0)
		return (ret);
	return (0);
}
