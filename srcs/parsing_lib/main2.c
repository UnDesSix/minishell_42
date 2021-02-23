/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 09:40:39 by calide-n          #+#    #+#             */
/*   Updated: 2021/02/23 10:25:18 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	get_next_word(char *str, int on, t_word *word);
int	get_nb_word(char *str, int on);

int	ft_count_lines()
{
	int nb;
	char *line;

	nb = 0;
	while (get_next_line(0, &line) != 0)
		nb++;
	return (nb);
}

int	ft_bksl(char *str)
{
	int i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
		i++;
	if (str[i - 1] == '\'')
		return (1);
	return (0);
}

int	ft_nb_blocks(char *str)
{
	int i;
	int quote;
	int nb;

	i = 0;
	nb = 0;
	quote = 0;
	if (str[i])
		nb++;
	while (str[i])
	{
		if (str[i] == '\'' && quote == 0)
			quote = 1;
		if (str[i] == '"' && quote == 0)
			quote = 2;
		if (str[i] == ';' && quote == 0)
		{
			i++;
			while (str[i])
			{
				if (str[i] != ' ')
					break;
				i++;
			}
			if (str[i] == '\0')
				nb--;
			nb++;
		}
		i++;
	}
	return (nb);
}

int	main(int argc, char **argv)
{
	char *line;

	while (get_next_line(0, &line) != 0)
		free(line);
	free(line);
	return (0);
}
