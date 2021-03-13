/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:14:08 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/11 17:17:53 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
 * FT_WHILE_ARGS -> transforms an array of word into an array of strings
 * then it set the node parameters according to this new array.
 */

int	ft_while_args(t_word *word, int i, t_node *node, int index)
{
	char	**tab;

	i = index;
	if (word[i].content)
	{
		tab = ft_token_to_tab(&word[index]);
		if (!tab)
			return (-1);
		node->cmd = tab[0];
		node->args = tab;
		node->type = ARG;
		return (1);
	}
	return (0);
}
