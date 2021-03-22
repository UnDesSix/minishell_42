/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:41:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/22 17:50:46 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		get_ret(char stop, int i, char *line, int nb_word)
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

void	get_nb_spe_op(char *line, int *nb_word, int i)
{
	if (line[i + 1] != ' ' && line[i + 1] != '\0')
		*nb_word += 1;
	if (i > 0)
		if (line[i - 1])
			if (line[i - 1] != ' ' && line[i - 1] != '\0')
				*nb_word += 1;
}

void	if_quotes_bcklsh(char *line, char *stop, int i)
{
	if (line[i] == '\\' && *stop != '\'')
		i++;
	if (line[i] == '"' && *stop == ' ')
		*stop = '"';
	if (line[i] == '\'' && *stop == ' ')
		*stop = '\'';
	if (line[i] == '"' && *stop == '"')
		*stop = ' ';
	if (line[i] == '\'' && *stop == '\'')
		*stop = ' ';
}

int		get_nb_word(char *line)
{
	int		i;
	int		nb_word;
	char	stop;

	i = 0;
	nb_word = 0;
	stop = ' ';
	while (line[i])
	{
		if_quotes_bcklsh(line, &stop, i);
		if (ft_is_special_operator(line[i]) && stop == ' ')
			get_nb_spe_op(line, &nb_word, i);
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
