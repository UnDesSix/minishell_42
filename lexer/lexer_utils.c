/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:45:36 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/21 18:39:14 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
** FT_IS_SPECIAL_OPERATOR -> Checks if a character is a special operator
** Return value ->  0 char is not in the special operator list
**                  1 char is in the special operator list
*/

int		ft_is_special_operator(char c)
{
	int	i;

	i = 0;
	while (SPEOP_LST[i])
	{
		if (SPEOP_LST[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/*
** FT_INIT_WORD -> init word with default values
*/

void	ft_init_word(t_word *word)
{
	word->content = NULL;
	word->sep = 0;
	word->space = 0;
	word->type = ARG;
	word->builtin = FALSE;
}

/*
** SET_QUOTE -> set the quotes variable to the corresponding
** quotes (double, single or none) and increments line index
*/

void	set_quote(int *b, int *quotes, int value, char *str)
{
	(void)str;
	*quotes = value;
	*b += 1;
}

int		ft_is_bs_spechar(char c)
{
	int	i;

	i = 0;
	while (DQ_BS_SPECHAR[i])
	{
		if (c == DQ_BS_SPECHAR[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup_with_limits(char *str, int b, int e)
{
	int		i;
	char	*dst;
	int		quotes;

	quotes = 0;
	if (str[b] == '"')
		set_quote(&b, &quotes, 2, str);
	else if (str[b] == '\'')
		set_quote(&b, &quotes, 1, str);
	i = e - b;
	dst = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	if (!dst)
		return (NULL);
	while (b < e)
	{
		if (quotes != 1)
			if (str[b] == '\\' && ft_is_bs_spechar(str[b + 1]))
				b++;
		dst[i++] = str[b++];
	}
	dst[i] = 0;
	return (dst);
}
