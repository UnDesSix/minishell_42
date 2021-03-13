/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:57:22 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/12 08:54:49 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	handle_space(char *line, t_lexer *lex, t_word *word)
{
	if (!line[lex->i])
		return (0);
	if (lex->begin == -1)
		lex->begin = lex->i;
	while (line[lex->i] != ' ' && line[lex->i])
	{
		if (line[lex->i] == '\'' || line[lex->i] == '"')
			break;
		lex->i++;
	}
	if (line[lex->i] == '\'' || line[lex->i] == '"')
		return (1);
	word->content = ft_strdup_with_limits(line, lex->begin, lex->i);
	if (!word->content)
		return (-1);
	lex->begin = -1;
	lex->x += 1;
	return (0);
}

int	handle_quotes(char *line, t_lexer *lex, t_word *word)
{
	char	tmp;
	int		on;

	on = 0;
	tmp = line[lex->i];
	set_word_sep(word, line[lex->i]);
	if (lex->begin == -1)
		lex->begin = lex->i;
	lex->i += 1;
	if (line[lex->i] == tmp)
	{
		while (line[lex->i] == tmp)
		{
			lex->i += 1;
			on++;
		}
		if ((on % 2) != 1)
		{
			printf("-Error quote\n");
			return (-1);
		}
	}
	else
	{
		while (line[lex->i] != tmp)
		{
			if (line[lex->i] == '\0')
			{
				printf("-Error quote\n");
				return (-1);
			}
			lex->i += 1;
		}
		lex->i += 1;
	}
	if (line[lex->i] == ' ' || line[lex->i] == '\0' || line[lex->i] == '"')
	{
		word->content = ft_strdup_with_limits(line, lex->begin, lex->i);
		lex->begin = -1;
		lex->x += 1;
	}
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
	printf("%d\n", nb_word);
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

int	handle_spechar(char *line, t_lexer *lex, t_word *word)
{
	lex->begin = lex->i;
	lex->i += 1;
	if (line[lex->i] == '>')
		lex->i += 1;
	word->content = ft_strdup_with_limits(line, lex->begin, lex->i);
	if (!word->content)
		return (-1);
	lex->begin = -1;
	lex->x += 1;
	if (line[lex->i] == ' ')
		word->space = TRUE;
	return (0);
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
		if (ft_is_special_operator(line[lex.i]))
			if (handle_spechar(line, &lex, &word[lex.x]) < 0)
				return (NULL);
		if (line[lex.i] != ' ' && line[lex.i] != '"' && line[lex.i] != '\'')
			if (handle_space(line, &lex, &word[lex.x]) < 0)
				return (NULL);
		if (line[lex.i] == '"' || line[lex.i] == '\'')
			if (handle_quotes(line, &lex, &word[lex.x]) < 0)
				return (NULL);
	}
	word[lex.x].content = NULL;
	return (word);
}
