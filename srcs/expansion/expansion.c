/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 19:17:47 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/08 10:56:47 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	expand_word(t_word *word, t_list *begin_list)
{
	char	*tmp_content;
	t_list	*tmp_list;
	int		i;

	i = 0;
	tmp_list = begin_list;
	tmp_content = &word[i].content[1];
	while (tmp_list)
	{
		//printf("[%s]\n", envp[i]);
		if (ft_strcmp(tmp_content, ((t_var *)tmp_list->data)->name) == 0)
		{
			free(word->content);
			word->content = ft_strdup(((t_var *)tmp_list->data)->content);
			return (0);
		}
		tmp_list = tmp_list->next;
	}
	return (0);
}

int	expansion(t_word *word, t_list *begin_list)
{
	int	i;

	i = 0;
	while (word[i].content)
	{
		if (word[i].sep != 1 && word[i].content[0] == '$')
			expand_word(&word[i], begin_list);
		i++;
	}
	return (0);
}
