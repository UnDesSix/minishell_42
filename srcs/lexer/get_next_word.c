/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:41:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/04 20:40:14 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

#define SPEOP_LST "=>|<;"

char	*ft_strdup_with_limits(char *str, int b, int e)
{
	int		i;
	int		tmp;
	char	*dst;

	i = e - b;
	dst = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	if (!dst)
		return (NULL);
	while (b < e)
	{
		dst[i] = str[b];
		b++;
		i++;
	}
	dst[i] = 0;
	return (dst);
}

int	get_next_word_init(int reset, int *i, t_word *word, char *str)
{
	if (reset == 0)
		*i = 0;
	if (str[*i] == 0)
	{
		word->content = NULL;
		return (0);
	}
	while (str[*i] == ' ')
		*i += 1;
	return (1);
}

void	get_next_word_incre(char stop, char *str, int *i, t_word *word)
{
	if (stop == '\'')
		word->sep = 1;
	if (stop == '"')
		word->sep = 2;
	if (stop == '\'' || stop == '"')
		while (str[*i] != stop && str[*i])
			*i += 1;
	else
		while (str[*i] && str[*i] != ' ' && !ft_is_special_operator(str[*i]))
			*i += 1;
	if (str[*i] == ' ')
		word->space = TRUE;
}

int	get_next_word(char *str, t_word *word, int reset)
{
	static int	i = 0;
	char		stop;
	int			begin;
	int			ret;

	stop = ' ';
	if (!get_next_word_init(reset, &i, word, str))
		return (0);
	begin = i;
	ret = ft_count_special_operator(str, &i, stop);
	if (ret == 0)
	{
		ret = ft_count_quote(str, &i, &stop);
		if (ret == -1)
			return (-1);
		else if (ret == 1)
			begin++;
		get_next_word_incre(stop, str, &i, word);
	}
	word->content = ft_strdup_with_limits(str, begin, i);
	if (str[i] == stop)
		i++;
	return (1);
}

/*
 * type of strings tested:
 * 	- space (0 1 2 3)
 * 	- single quote ('0 1 2 3')
 * 	- double quote ("0 1 2 3")
 * 	- all three (0 1 '2 3' "4 5")
 * 	- single quote without space (hello'hey' -> count as one)
 * 	- double quote without space (hello"hey" -> count as one)
 * 	- empty ()
 * 	- special operators with space (1 = 2, 1 > 2, 1 >> 2, 1 < 2, 1 | 2, 1 ; 2)
 * 	- special operators without space (1=2, 1>2, 1>>2, 1<2, 1|2, 1;2)
 * 	- special operators with single quotes ('1=2', '1>2', '1>>2', '1<2', '1|2', '1;2')
 * 	- special operators with double quotes ("1=2", "1>2", "1>>2", "1<2", "1|2", "1;2")
 * 	- single quote error ('1)
 * 	- double quote error ("1)
 *
 * 	idk section:
 *	- (1==2)
 */
