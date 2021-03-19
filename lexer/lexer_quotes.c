/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:11:52 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/17 12:05:08 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	incre_word(char *line, t_lexer *lex, t_word *word)
{
	if (line[lex->i] == ' ')
		word->space = TRUE;
	if (line[lex->i] == ' ' || line[lex->i] == '\0'
			|| ft_is_special_operator(line[lex->i]))
		lex->x += 1;
}

int		set_up_handle_quote(char *line, t_lexer *lex, t_word *word, int *stop)
{
	if (line[lex->i] != '\'' && line[lex->i] != '"')
		return (0);
	word->sep = 1;
	if (line[lex->i] == '"')
		word->sep += 1;
	*stop = line[lex->i];
	lex->i++;
	return (1);
}

void	handle_quotes_while_not_stop(char *line, t_lexer *lex, int stop)
{
	while (line[lex->i] != stop && line[lex->i])
	{
		if (line[lex->i] == '\\' && stop == '"')
			lex->i++;
		lex->i++;
	}
}

int		handle_quotes(char *line, t_lexer *lex, t_word *word)
{
	int		stop;
	char	*tmp;
	int		begin;
	char	*tmp_word;

	begin = lex->i;
	if (!set_up_handle_quote(line, lex, word, &stop))
		return (0);
	handle_quotes_while_not_stop(line, lex, stop);
	tmp = ft_strdup_with_limits(line, begin, lex->i);
	if (!word->content)
		word->content = ft_strdup(tmp);
	else
	{
		tmp_word = ft_strdup(word->content);
		free(word->content);
		word->content = ft_strjoin(tmp_word, tmp);
		free(tmp_word);
	}
	free(tmp);
	if (line[lex->i] == stop)
		lex->i++;
	incre_word(line, lex, word);
	return (0);
}
