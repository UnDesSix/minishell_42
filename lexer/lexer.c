/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:57:22 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/21 18:39:53 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		handle_space(char *line, t_lexer *lex, t_word *word)
{
	char	*tmp;
	char	*tmp_word;
	int		begin;

	begin = lex->i;
	if (line[lex->i] == 0 || line[lex->i] == '\'' || line[lex->i] == '"'
		|| line[lex->i] == '\\' || line[lex->i] == ' ')
		return (0);
	while (line[lex->i] && line[lex->i] != ' ' &&
	!ft_is_special_operator(line[lex->i]) && line[lex->i] != '"'
	&& line[lex->i] != '\'' && line[lex->i] != '\\')
		lex->i++;
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
	incre_word(line, lex, word);
	return (0);
}

int		handle_bcklsh(char *line, t_lexer *lex, t_word *word)
{
	char	*tmp;
	char	*tmp_word;

	if (line[lex->i] != '\\')
		return (0);
	lex->i += 1;
	tmp = malloc(sizeof(char) * 2);
	tmp[0] = line[lex->i];
	tmp[1] = '\0';
	lex->i += 1;
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
	incre_word(line, lex, word);
	return (0);
}

int		handle_spechar(char *line, t_lexer *lex, t_word *word)
{
	char	*tmp;

	if (!ft_is_special_operator(line[lex->i]))
		return (0);
	if (line[lex->i + 1] == '>')
	{
		tmp = malloc(sizeof(char) * 3);
		tmp[0] = line[lex->i];
		tmp[1] = '>';
		tmp[2] = '\0';
		lex->i += 1;
	}
	else
	{
		tmp = malloc(sizeof(char) * 2);
		tmp[0] = line[lex->i];
		tmp[1] = '\0';
	}
	lex->i += 1;
	if (line[lex->i] == ' ')
		word->space = TRUE;
	word->content = tmp;
	lex->x += 1;
	return (0);
}

t_word	*malloc_word(char *line)
{
	int		nb_word;
	t_word	*word;
	int		i;

	i = 0;
	nb_word = 0;
	nb_word = get_nb_word(line);
	if (nb_word < 0)
		return (NULL);
	word = malloc(sizeof(t_word) * (nb_word + 1));
	if (!word)
		return (NULL);
	while (i < nb_word)
	{
		ft_init_word(&word[i]);
		i++;
	}
	ft_init_word(&word[i]);
	return (word);
}

t_word	*ft_lexer(char *line)
{
	t_lexer	lex;
	t_word	*word;

	lex.i = 0;
	lex.x = 0;
	lex.begin = -1;
	word = malloc_word(line);
	if (!word)
		return (NULL);
	while (line[lex.i])
	{
		if (line[lex.i] == ' ')
			lex.i++;
		else if (handle_bcklsh(line, &lex, &word[lex.x]) < 0)
			return (NULL);
		else if (handle_spechar(line, &lex, &word[lex.x]) < 0)
			return (NULL);
		else if (handle_space(line, &lex, &word[lex.x]) < 0)
			return (NULL);
		else if (handle_quotes(line, &lex, &word[lex.x]) < 0)
			return (NULL);
	}
	word[lex.x].content = NULL;
	return (word);
}
