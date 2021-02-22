/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:13:32 by calide-n          #+#    #+#             */
/*   Updated: 2021/02/19 22:30:54 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static char	ft_check_quotes(char *s, char *c, size_t i)
{
	while (s[i] && s[i] == ' ')
		i++;
	if (s[i] == '\'')
	{
		*c = '\'';
		i++;
	}
	else if (s[i] == '"')
	{
		*c = '"';
		i++;
	}
	else if (s[i] == '|')
	{
		*c = ' ';
		i++;
	}
	return (i);
}

static char	*ft_strdup_to_char(char const *str, char c)
{
	int		i;
	char	*dest;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_get_word_nb(char *s, char c)
{
	size_t	i;
	size_t	nb;
	int		tmpc;

	i = 0;
	nb = 0;
	tmpc = c;
	while (s[i])
	{
		if (s[i] == '|')
			nb++;
		while (s[i] && s[i] == c)
			i++;
		i = ft_check_quotes(s, &c, i);
		if (s[i] != '\0')
			nb++;
		while (s[i] && s[i] != c)
			i++;
		c = tmpc;
		while (s[i] && s[i] != c)
			i++;
	}
	return (nb);
}

int	ft_index(char *s, int i, char *c, char tmpc)
{
	while (s[i] && s[i] != *c)
		i++;
	if (s[i] == *c)
		i++;
	*c = ' ';
	while (s[i] == ' ')
		i++;
	return (i);
}

char	**ft_split(char *s, char c)
{
	size_t	nb_of_words;
	char	**tab;
	size_t	i;
	size_t	j;
	char	tmpc;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	nb_of_words = ft_get_word_nb(s, c);
	tab = (char **)malloc(sizeof(char *) * (nb_of_words + 1));
	if (!tab)
		return (0);
	tmpc = c;
	while (j < nb_of_words)
	{
		i = ft_check_quotes(s, &c, i);
		tab[j++] = ft_strdup_to_char(s + i, c);
		i = ft_index(s, i, &c, tmpc);
	}
	tab[j] = 0;
	return (tab);
}
