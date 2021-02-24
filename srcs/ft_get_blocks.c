/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_blocks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 09:40:39 by calide-n          #+#    #+#             */
/*   Updated: 2021/02/24 15:28:21 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

t_word	get_next_word(char *str, int on, int *ret);
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
		if (str[i] == '\'' && quote == 1)
			quote = 0;
		if (str[i] == '"' && quote == 0)
			quote = 2;
		if (str[i] == '"' && quote == 2)
			quote = 0;
		if (str[i] == ';' && quote == 0)
		{
			i++;
			while (str[i] == ' ')
				i++;
			if (str[i] == '\0')
				break;
			nb++;
		}
		i++;
	}
	return (nb);
}

int	ft_nb_word(char *line, int reset)
{
	int ret;
	int nb;

	nb = 0;
	ret = 1;
	while (1)
	{
		ret = get_nb_word(line, reset);
		if (ret == 2)
		{
			nb++;
			break;
		}
		if (ret == 0)
			break;
		nb++;
		reset = 1;
	}
	return (nb);
}

t_word	*ft_word(char *line, int reset)
{
	int ret;
	int windex;
	int nb;
	t_word *word;
	int new_line;

	windex = 0;
	ret = 1;
	nb = ft_nb_word(line, reset);
	new_line = reset;
	word = malloc(sizeof(t_word) * (nb + 1));
	while (ret)
	{
		word[windex] = get_next_word(line, new_line, &ret);
		new_line = 1;
		if (ret == 2)
			break;
		windex++;
	}
	word[nb].content = NULL;
	return (word);
}

t_block	*ft_get_blocks(char *line)
{
	int		nb_blocks;
	t_block	*block;
	int		reset;
	int index = 0;

	nb_blocks = ft_nb_blocks(line);
	block = (t_block *)malloc(sizeof(t_block) * (nb_blocks + 1));

	reset = 0;
	while (index < nb_blocks)
	{
		block[index].word = ft_word(line, reset);
		block[index].stop = 1;
		reset = 1;
		index++;	
	}
	block[nb_blocks].stop = 0;
	return (block);
}
