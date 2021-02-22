/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:41:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/02/22 09:41:34 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	ft_check_next_quote(char *str, int i, char c)
{
	while (str[i] != c)
		if (str[i++] == '\0')
			return (0);
	return (1);
}

char	*ft_manage_quote(char *str, int *i, char c)
{
	char	*word;
	int		j;
	int		k;

	k = 0;
	*i += 1;
	j = *i;
	if (!ft_check_next_quote(str, *i, c))
	{
		printf("Error quote\n");
		return (NULL);
	}
	while (str[j] && str[j] != c)
		j++;
	word = malloc(sizeof(char) * (j + 1));
	while (str[*i] && str[*i] != c)
	{
		word[k] = str[*i];
		*i += 1;
		k++;
	}
	word[k] = '\0';
	*i += 1;
	return (word);
}

char	*ft_manage_space(char *str, int *i)
{
	char	*word;
	int		j;
	int		k;

	j = *i;
	k = 0;
	while (str[j] && str[j] != ' ' && str[j] != '\'' && str[j] != '"')
		j++;
	word = malloc(sizeof(char) * (j + 1));
	while (str[*i] && str[*i] != ' ' && str[*i] != '\'' && str[*i] != '"')
	{
		word[k] = str[*i];
		*i += 1;
		k++;
	}
	word[k] = '\0';
	if (str[*i] != '\'' && str[*i] != '"')
		*i += 1;
	return (word);
}

char	*get_next_word(char *str, int on)
{
	static int	i;
	char		*word;
	int			k;
	int			j;

	k = 0;
	j = 0;
	if (on == 0)
		i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] == ' ')
		i++;
	if (str[i] != '\'' && str[i] != '"')
		word = ft_manage_space(str, &i);
	else if (str[i] == '\'')
		word = ft_manage_quote(str, &i, '\'');
	else if (str[i] == '"')
		word = ft_manage_quote(str, &i, '"');
	while (str[i] == ' ')
		i++;
	return (word);
}
