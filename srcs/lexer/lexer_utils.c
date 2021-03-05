/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:45:36 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/04 19:12:52 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
 * FT_IS_SPECIAL_OPERATOR -> Checks if a character is a special operator
 * Return value ->  0 char is not in the special operator list
 *                  1 char is in the special operator list
 */

int	ft_is_special_operator(char c)
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
 *  FT_CHECK_NEXT_QUOTE -> Check if a quotes has its corresponding pair
 *  Return value -> 0 pair is missing
 *                  1 pair is present
 */

int	ft_check_next_quote(char *str, int i, char c)
{
	i++;
	while (str[i] != c)
		if (str[i++] == '\0')
			return (-1);
	if (str[i + 1] != ' ' && str[i + 1] != 0)
		return (0);
	return (1);
}
/*
 * FT_COUNT_SPECIAL_OPERATOR -> Counts a word if the current char is 
 * a special operator.
 * Return values -> 1 character is a new word
 *                  0 character is not a new word
 */

int	ft_count_special_operator(char *str, int *i, char stop)
{
	if (ft_is_special_operator(str[*i]) && stop == ' ')
	{
		*i += 1;
		if (str[*i] == '>')
		{
			*i += 1;
			return (2);
		}
		return (1);
	}
	return (0);
}

/*
 * FT_COUNT_QUOTES -> Checks if the word is between quotes,
 * and if so will check if the closing quote is missing.
 * It also sets the stop character to the corresponding quote
 * Return value -> -1 error
 *                  1 the word is between a pair of quotes
 *                  0 the word is not between quotes
 */

int	ft_count_quote(char *str, int *i, char *stop)
{
	int	ret;

	ret = 0;
	if ((str[*i] == '\'' || str[*i] == '"') && *stop == ' ')
	{
		ret = ft_check_next_quote(str, *i, str[*i]);
		if (ret == -1)
		{
			printf("Error quote\n");
			*i += 1;
			return (-1);
		}
		if (ret == 0)
		{
			*stop = ' ';
			return (0);
		}
		*stop = str[*i];
		*i += 1;
		return (1);
	}
	return (0);
}
