/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:57:22 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/04 20:10:36 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	reset_lexer_var(int *nb_word, int *reset, int *ret, int *index)
{
	*nb_word = 0;
	*reset = 0;
	*ret = 1;
	*index = 0;
}

void	ft_init_word(t_word *word)
{
	word->content = NULL;
	word->sep = 0;
	word->space = 0;
	word->type = ARG;
	word->builtin = FALSE;
}

t_word	*ft_lexer(char *line)
{
	t_word	*word;
	int		index;
	int		nb_word;
	int		reset;
	int		ret;

	reset_lexer_var(&nb_word, &reset, &ret, &index);
	while (ret)
	{
		ret = get_nb_word(line, reset);
		reset = 1;
		nb_word++;
	}
	word = (t_word *)malloc(sizeof(t_word) * (nb_word));
	reset_lexer_var(&nb_word, &reset, &ret, &index);
	while (ret)
	{
		ft_init_word(&word[index]);
		ret = get_next_word(line, &word[index], reset);
		index++;
		reset = 1;
	}
	return (word);
}
