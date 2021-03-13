/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:41:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/13 14:21:13 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	get_nb_word_quotes(char *line, int *i, int *nb_word, char quote)
{
	if (line[*i] == quote)
	{
		*i += 1;
		return ;
	}
	*i += 1;
	while (line[*i] != quote)
	{
		if (line[*i] == '\0')
		{
			printf("Error quote\n");
			*nb_word = -1;
			return ;
		}
		*i += 1;
	}
	*i += 1;
	if (line[*i] == ' ' || line[*i] == '\0')
		nb_word++;
}

int	get_nb_word(char *line)
{
	int	i;
	int	nb_word;
	char	stop;

	i = 0;
	nb_word = 0;
	stop = ' ';
	while (line[i])
	{
		printf("%d : [%s]\n", stop, &line[i]);
		if (line[i] == '\\')
			i++;
		else if (ft_is_special_operator(line[i]) && stop == ' ')
		{
			if (line[i + 1] != ' ' && line[i + 1] != '\0')
				nb_word++;
			nb_word++;
		}
		else if (line[i] == '"' && stop == ' ')
			stop = '"';
		else if (line[i] == '\'' && stop == ' ')
			stop = '\'';
		else if (line[i] == '"' && stop == '"')
			stop = ' ';
		else if (line[i] == '\'' && stop == '\'')
			stop = ' ';
		else if (line[i] == ' ' && stop == ' ')
		{
			nb_word++;
			i++;
			while (line[i] == ' ')
				i++;
			continue;
		}
		i++;
	}
	if (i > 0)
		if (line[i] == 0 && line[i - 1] != ' ')
			nb_word++;
	return (nb_word);
}
