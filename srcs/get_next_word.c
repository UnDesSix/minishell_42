/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:41:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/02/24 20:11:26 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int	ft_check_next_quote(char *str, int i, char c)
{
	while (str[i] != c)
		if (str[i++] == '\0')
			return (0);
	return (1);
}

t_word	ft_manage_quote(char *str, int *i, char c)
{
	t_word	word;
	int		j;
	int		k;

	k = 0;
	*i += 1;
	j = *i;
	word.space = 0;
	if (!ft_check_next_quote(str, *i, c))
	{
		printf("Error quote\n");
		word.content = NULL;
		return (word);
	}
	while (str[j] && str[j] != c && str[j] != ';')
		j++;
	word.content = malloc(sizeof(char) * (j + 1));
	while (str[*i] && str[*i] != c && str[j] != ';')
	{
		word.content[k] = str[*i];
		*i += 1;
		k++;
	}
	word.content[k] = '\0';
	*i += 1;
	if (str[*i] == ' ' || str[*i - 2])
		word.space = 1;
	return (word);
}

t_word	ft_manage_space(char *str, int *i)
{
	t_word	word;
	int		j;
	int		k;

	j = *i;
	k = 0;
	word.sep = 0;
	word.space = 0;
	while (str[j] && str[j] != ' ' && str[j] != '\''
		&& str[j] != '"' && str[j] != '\'' && str[j] != ';' && str[j] != '=')
		j++;
	word.content = malloc(sizeof(char) * (j + 1));
	while (str[*i] && str[*i] != ' ' && str[*i] != '\''
		&& str[*i] != '"' && str[*i] != '\'' && str[*i] != ';' && str[*i] != '=')
	{
		word.content[k] = str[*i];
		*i += 1;
		k++;
	}
	word.content[k] = '\0';
	if (str[*i] == ' ')
	{
		word.space = 1;
		*i += 1;
	}
	return (word);
}

t_word	get_next_word(char *str, int on, int *ret)
{
	static int	i;
	int			k;
	int			j;
	t_word		word;

	k = 0;
	j = 0;
	if (on == 0)
		i = 0;
	word.sep = 0;
	word.space = 0;
	if (!str[i])
	{
		*ret = 0;
		word.content = NULL;
		return (word);
	}
	while (str[i] == ' ')
		i++;
	if (str[i] == ';')
	{
		word.content = ft_strdup(";");
		word.sep = 0;
		*ret = 2;
		i++;
		return (word);
	}
	else if (str[i] == '=')
	{
		word.content = ft_strdup("=");
		word.sep = 0;
		i++;
		if (str[i] == ' ')
			word.space = 1;
	}
	else if (str[i] != '\'' && str[i] != '"')
		word = ft_manage_space(str, &i);
	else if (str[i] == '\'')
	{
		word = ft_manage_quote(str, &i, '\'');
		word.sep = 1;
	}
	else if (str[i] == '"')
	{
		word = ft_manage_quote(str, &i, '"');
		word.sep = 2;
	}
	while (str[i] == ' ')
		i++;
	*ret = 1;
	return (word);
}
