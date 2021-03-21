/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:41:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/21 15:25:19 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	get_ret(char stop, int i, char *line, int nb_word)
{
	if (stop != ' ')
	{
		printf("Error quotes\n");
		return (-1);
	}
	if (i > 0)
		if ((line[i] == 0 && line[i - 1] != ' '))
			nb_word++;
	return (nb_word);
}

int	get_nb_word(char *line)
{
	int		i;
	int		nb_word;
	char	stop;

	i = 0;
	nb_word = 0;
	stop = ' ';
	while (line[i])
	{
		if (line[i] == '\\' && stop != '\'')
			i++;
		else if (line[i] == '"' && stop == ' ')
			stop = '"';
		else if (line[i] == '\'' && stop == ' ')
			stop = '\'';
		else if (line[i] == '"' && stop == '"')
			stop = ' ';
		else if (line[i] == '\'' && stop == '\'')
			stop = ' ';
		else if (ft_is_special_operator(line[i]) && stop == ' ')
		{
			if (line[i + 1] != ' ' && line[i + 1] != '\0')
				nb_word++;
			if (line[i - 1])
				if (line[i - 1] != ' ' && line[i - 1] != '\0')
					nb_word++;
		}
		else if (line[i] == ' ' && stop == ' ')
		{
			nb_word++;
			i++;
			while (line[i] == ' ')
				i++;
			continue ;
		}
		i++;
	}
	return (get_ret(stop, i, line, nb_word));
}
