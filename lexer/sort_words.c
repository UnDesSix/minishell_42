/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_words.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:08:03 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/22 14:54:59 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		word_is_redi(char *str)
{
	return (ft_strcmp(str, ">") == 0
			|| ft_strcmp(str, ">>") == 0
			|| ft_strcmp(str, "<") == 0);
}

t_word	*sort_segment(t_word *word)
{
	t_word	*before;
	t_word	*redi;
	t_word	*new;
	int		i;

	i = 0;
	before = copy_without_redi(word);
	redi = copy_only_redi(word);
	new = ft_wordjoin(before, redi);
	free(before);
	free(redi);
	return (new);
}

t_word	*manage_enf_of_word(t_word *word, t_word *new)
{
	t_word		*segment;
	t_word		*tmp_new;

	segment = sort_segment(word);
	tmp_new = ft_wordjoin(new, segment);
	if (new)
		free(new);
	free(segment);
	return (tmp_new);
}

t_word	*sort_word(t_word *word)
{
	t_sort_var	var;
	t_word		*new;

	var.x = 0;
	var.begin = 0;
	new = NULL;
	while (1)
	{
		if (!word[var.x].content)
		{
			new = manage_enf_of_word(&word[var.begin], new);
			break ;
		}
		else if (ft_strcmp(word[var.x].content, "|") == 0)
		{
			free(word[var.x].content);
			word[var.x].content = NULL;
			new = manage_enf_of_word(&word[var.begin], new);
			var.begin = var.x;
			word[var.x].content = ft_strdup("|");
		}
		var.x++;
	}
	free(word);
	return (new);
}
