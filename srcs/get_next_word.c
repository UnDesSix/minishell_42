/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:41:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/02/25 11:20:00 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int	ft_check_next_quote(char *str, int i, char c)
{
	while (str[i] != c)
		if (str[i++] == '\0')
			return (0);
	return (1);
}

int	ft_manage_all_quotes(char *str, t_word *word, int *i)
{
	if (str[*i] == '\'')
	{
		if (!ft_check_next_quote(str, *i, str[*i]))
		{
			printf("Error quote\n");
			word->content = NULL;
			return (1);
		}
		*word = ft_manage_quote(str, i, '\'');
		word->sep = 1;
		return (1);
	}
	else if (str[*i] == '"')
	{
		if (!ft_check_next_quote(str, *i, str[*i]))
		{
			printf("Error quote\n");
			word->content = NULL;
			return (0);
		}
		*word = ft_manage_quote(str, i, '"');
		word->sep = 2;
		return (1);
	}
	return (0);
}

t_word	get_next_word(char *str, int on, int *ret)
{
	static int	i;
	int			k;
	int			j;
	t_word		word;

	k = 0;
	j = 0;
	if (on == 0)
		i = 0;
	word.sep = 0;
	word.space = 0;
	if (ft_manage_null(str[i], &word, ret))
		return (word);
	while (str[i] == ' ')
		i++;
	if (ft_manage_semicolon(str[i], &word, ret, &i))
		return (word);
	else if (ft_manage_speop(str[i], &word, &i))
		return (word);
	else if (str[i] != '\'' && str[i] != '"')
		word = ft_manage_space(str, &i);
	else if (ft_manage_all_quotes(str, &word, &i))
		return (word);
	*ret = 1;
	return (word);
}

/* Get next word works like GNL, it will get the next word.
 * It looks at the first character to determine if the word is 
 * between quotes, NULL, a special operator...
 * Once a word is defined, it is malloc and returned.
 */
