/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_word_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:54:00 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/22 14:54:51 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_word	*copy_only_redi(t_word *word)
{
	int		i;
	int		x;
	t_word	*new;

	i = 0;
	x = 0;
	while (word[i].content)
		i++;
	new = malloc(sizeof(t_word) * (i + 1));
	i = 0;
	while (word[i].content)
	{
		if (word_is_redi(word[i].content))
		{
			new[x++] = word[i++];
			new[x++] = word[i++];
		}
		else
			i++;
	}
	new[x].content = NULL;
	return (new);
}

t_word	*copy_without_redi(t_word *word)
{
	int		i;
	int		x;
	t_word	*new;

	i = 0;
	x = 0;
	while (word[i].content)
		i++;
	new = malloc(sizeof(t_word) * (i + 1));
	i = 0;
	while (word[i].content)
	{
		if (word_is_redi(word[i].content))
			i++;
		else
		{
			new[x] = word[i];
			x++;
		}
		i++;
	}
	new[x].content = NULL;
	return (new);
}
