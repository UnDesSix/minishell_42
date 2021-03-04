/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_blocks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 09:40:39 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/04 12:03:57 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int	ft_nb_blocks(char *str)
{
	int	i;
	int	quote;
	int	nb;

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
		if ((str[i] == ';' || str[i] == '|') && quote == 0)
		{
			i++;
			while (str[i] == ' ')
				i++;
			if (str[i] == '\0')
				break ;
			nb++;
		}
		i++;
	}
	return (nb);
}

int	ft_nb_word(char *line)
{
	int	ret;
	int	nb;
	int	reset;

	nb = 0;
	ret = 1;
	reset = 0;
	while (ret > 0)
	{
		ret = get_nb_word(line);
		if (ret == 2)
		{
			nb++;
			break ;
		}
		nb++;
		reset = 1;
	}
	return (nb);
}

void	ft_debug_word(t_word word)
{
	char *builtin;
	char *type;

	if (word.builtin == FALSE)
		builtin = ft_strdup("FALSE");
	else
		builtin = ft_strdup("TRUE");
	if (word.type == ARG)
		type = ft_strdup("ARG");
	else if (word.type == CMD)
		type = ft_strdup("CMD");
	else
		type = ft_strdup("SEPOP");
	printf("[%s] type[%s] builtin[%s]\n", word.content, type, builtin);
	free(builtin);
	free(type);
}

t_word	*ft_word(char *line)
{
	int		ret;
	int		windex;
	int		nb;
	t_word	*word;

	windex = 0;
	ret = 1;
	nb = ft_nb_word(line);
	word = malloc(sizeof(t_word) * (nb + 1));
	if (!word)
		return (NULL);
	printf("[\n");
	while (ret)
	{
		ret = get_next_word(line, &word[windex]);
		ft_identify_word(&word[windex]);
		ft_debug_word(word[windex]);
		if (ret == 2)
			break ;
		windex++;
	}
	printf("]\n");
	word[nb].content = NULL;
	return (word);
}

t_block	*ft_get_blocks(char *line)
{
	int		nb_blocks;
	t_block	*block;
	int		reset;
	int		index;

	index = 0;
	reset = 0;
	nb_blocks = ft_nb_blocks(line);
	block = (t_block *)malloc(sizeof(t_block) * (nb_blocks + 1));
	if (!block) 
		return (NULL);
	while (index < nb_blocks)
	{
		block[index].word = ft_word(line);
		block[index].stop = 1;
		index++;
	}
	block[nb_blocks].stop = 0;
	return (block);
}

/* ft_get_blocks take a char * as a parameter and will split it in different structures
 * first it will count the number of blocks (delimited by semi colons), then it will call
 * ft_word which will fill each block with its own words. The words are stored as a 
 * struct table and each have informations about their different states (quotes, space after...)
 */
