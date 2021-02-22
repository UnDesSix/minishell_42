/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 09:40:39 by calide-n          #+#    #+#             */
/*   Updated: 2021/02/22 09:44:04 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

char *get_next_word(char *str, int on);

int	main(int argc, char **argv)
{
	int		i;
	char	*word;
	char	*line;
	char	**tab;

	i = 0;
	while (get_next_line(0, &line) != 0)
	{
		word = get_next_word(line, 0);
		while (word)
		{
			printf("%s\n", word);
			word = get_next_word(line, 1);
		}
	}
	return (0);
}
