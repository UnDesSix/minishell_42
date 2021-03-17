/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_words.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:08:03 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/17 11:53:40 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		word_is_redi(char *str)
{
	return (ft_strcmp(str, ">") == 0
		|| ft_strcmp(str, ">>") == 0
		|| ft_strcmp(str, "<") == 0);
}

int		get_words_tabs_sizes(t_word **new_word,
		t_word **store_redi, t_word *word)
{
	int	i;
	int	nb_redi;

	i = 0;
	nb_redi = 0;
	while (word[i].content)
		if (word_is_redi(word[i++].content))
			nb_redi++;
	*store_redi = (t_word *)malloc(sizeof(t_word) * ((2 * nb_redi) + 1));
	*new_word = (t_word *)malloc(sizeof(t_word) * (i + 1));
	return (0);
}

int		copy_word(t_word *new_word, t_word *store_redi, t_word *word)
{
	int		i;
	int		y;
	int		x;

	i = 0;
	x = 0;
	y = 0;
	while (word[i].content)
	{
		if (word_is_redi(word[i].content))
		{
			store_redi[y++] = word[i++];
			store_redi[y++] = word[i++];
		}
		else
			new_word[x++] = word[i++];
	}
	store_redi[y].content = NULL;
	return (x);
}

t_word	*sort_words(t_word *word)
{
	t_word	*store_redi;
	t_word	*new_word;
	int		x;
	int		y;

	x = 0;
	y = 0;
	get_words_tabs_sizes(&new_word, &store_redi, word);
	if (!new_word || !store_redi)
		return (NULL);
	x = copy_word(new_word, store_redi, word);
	y = 0;
	while (store_redi[y].content)
		new_word[x++] = store_redi[y++];
	new_word[x].content = NULL;
	free(store_redi);
	free(word);
	return (new_word);
}
