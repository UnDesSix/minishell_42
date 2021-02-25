/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_word_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:11:05 by calide-n          #+#    #+#             */
/*   Updated: 2021/02/25 11:22:03 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

t_word	ft_manage_quote(char *str, int *i, char c)
{
	t_word	word;
	int		j;
	int		k;

	k = 0;
	*i += 1;
	j = *i;
	word.space = 0;
	while (str[j] && str[j] != c && str[j] != ';')
		j++;
	word.content = malloc(sizeof(char) * (j + 1));
	while (str[*i] && str[*i] != c && str[j] != ';')
	{
		word.content[k] = str[*i];
		*i += 1;
		k++;
	}
	word.content[k] = '\0';
	*i += 1;
	if (str[*i] == ' ' || str[*i - 2])
		word.space = 1;
	return (word);
}

t_word	ft_manage_space(char *str, int *i)
{
	t_word	word;
	int		j;
	int		k;

	j = *i;
	k = 0;
	while (str[j] && str[j] != ' ' && str[j] != '\''
		&& str[j] != '"' && str[j] != '\'' && str[j] != ';' && str[j] != '=')
		j++;
	word.content = malloc(sizeof(char) * (j + 1));
	while (str[*i] && str[*i] != ' ' && str[*i] != '\''
		&& str[*i] != '"' && str[*i] != '\'' && str[*i] != ';' && str[*i] != '=')
	{
		word.content[k] = str[*i];
		*i += 1;
		k++;
	}
	word.content[k] = '\0';
	if (str[*i] == ' ')
	{
		word.space = 1;
		*i += 1;
	}
	return (word);
}

int	ft_manage_null(char c, t_word *word, int *ret)
{
	if (!c)
	{
		*ret = 0;
		word->content = NULL;
		return (1);
	}
	return (0);
}

int	ft_manage_semicolon(char c, t_word *word, int *ret, int *i)
{
	if (c == ';')
	{
		word->content = ft_strdup(";");
		word->sep = 0;
		*ret = 2;
		*i += 1;
		return (1);
	}
	return (0);
}

int	ft_manage_speop(char c, t_word *word, int *i)
{
	if (c == '=' || c == '|' || c == '<' || c == '>')
	{
		word->content = (char *)malloc(sizeof(char) * 2);
		word->content[0] = c;
		word->content[1] = '\0';
		word->sep = 0;
		*i += 1;
		if (c == ' ')
			word->space = 1;
		return (1);
	}
	return (0);
}
