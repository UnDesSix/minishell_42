/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:41:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/08 16:32:49 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
 * GET_NB_WORD_INCREMENTATION -> is the part of GET_NB_WORD
 * that manages the incrementation if the stop char is space
 * It also manages in case there are quotes without spaces preceding them
 */

int	get_nb_word_incrementation(char *str, int *i, char *stop)
{
	int	ret;
	int	tmp_stop;

	while (str[*i] && str[*i] != ' ' && !ft_is_special_operator(str[*i]))
	{
		if (str[*i] == '\'' || str[*i] == '"')
		{
			ret = ft_check_next_quote(str, *i, str[*i]);
			if (ret == 1)
			{
				tmp_stop = str[*i];
				*i += 1;
				while (str[*i] != tmp_stop)
					*i += 1;
			}
			if (ret == -1)
				return (-1);
		}
		*i += 1;
	}
	return (0);
}

/* 
 * GET_NB_WORD -> gets the number of word in a string
 * A word is defined by space or quotes.
 * Return values -> 1 if a word is found
 * 					0 if no word is found
 * 					-1 for any errors
 * The functions take the character at the current index,
 * It checks mutliple things:
 * 	- it's a special operator -> creates a new word containing this operator
 * 	- if's a quote -> finds the closing quote and
 * 		sets the stop character to the corresponding quote (double or single)
 * 	- if it's '\0' -> end of the line, returns (0)
 * 	
 * 	After that, it will increment the index to the end of the word
 */

int	get_nb_word(char *str, int reset)
{
	static int	i = 0;
	char		stop;

	if (reset == 0)
		i = 0;
	stop = ' ';
	while (str[i] == ' ')
		i++;
	if (str[i] == 0)
		return (0);
	if (ft_count_special_operator(str, &i, stop) > 0)
		return (1);
	if (ft_count_quote(str, &i, &stop) == -1)
		return (-1);
	if (stop == '\'' || stop == '"')
		while (str[i] != stop && str[i])
			i++;
	else
		if (get_nb_word_incrementation(str, &i, &stop) == -1)
			return (-1);
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
