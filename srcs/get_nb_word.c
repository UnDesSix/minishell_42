/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:41:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/04 12:04:58 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int	ft_check_next_quote_count(char *str, int i, char c)
{
	while (str[i] != c)
		if (str[i++] == '\0')
			return (0);
	return (1);
}

void	ft_manage_quote_count(char *str, int *i, char c)
{
	*i += 1;
	if (!ft_check_next_quote_count(str, *i, c))
	{
		printf("Error quote\n");
		return ;
	}
	while (str[*i] && str[*i] != c)
	{
		*i += 1;
	}
	*i += 1;
}

void	ft_manage_space_count(char *str, int *i)
{
	while (str[*i] && str[*i] != ' ' && str[*i] != '\''
		&& str[*i] != '"' && str[*i] != ';' && str[*i] != '=')
		*i += 1;
	if (str[*i] != '\'' && str[*i] != '"' && str[*i] != ';' && str[*i] != '=')
		*i += 1;
}

int	get_nb_spe_char(char *str, int *i)
{
	if (str[*i] == ';')
	{
		*i += 1;
		return (2);
	}
	if (str[*i] == '=' || str[*i] == '|' || str[*i] == '<' || str[*i] == '>')
	{
		if (str[*i + 1] == '>')
			*i += 1;
		*i += 1;
		return (1);
	}
	return (0);
}

int	get_nb_word(char *str)
{
	static int	i = 0;
	int			k;
	int			j;
	int 		ret;

	k = 0;
	j = 0;
	ret = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] == ' ')
		i++;
	ret = get_nb_spe_char(str, &i);
	if (ret != 0)
		return (ret);
	if (str[i] != '\'' && str[i] != '"')
		ft_manage_space_count(str, &i);
	else if (str[i] == '\'')
		ft_manage_quote_count(str, &i, '\'');
	else if (str[i] == '"')
		ft_manage_quote_count(str, &i, '"');
	return (1);
}

/* get_nb_word will get the number of word in a string until it finds a semicolon
 * semi colon is considered as a word so it will be counted.
 * get_nb_word takes in consideration spaces, single quotes, double quotes...
 */
