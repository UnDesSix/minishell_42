/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:29:16 by calide-n          #+#    #+#             */
/*   Updated: 2021/02/19 18:42:37 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int	ft_check_cmd(char *str)
{
	if (strcmp(str, "pwd")		&&
			strcmp(str, "echo")		&&
			strcmp(str, "cat")		&&
			strcmp(str, "cd")		&&
			strcmp(str, "export")	&&
			strcmp(str, "unset")	&&
			strcmp(str, "env")		&&
			strcmp(str, "exit"))
		return (0);
	return (1);
}

int		ft_count_words(int i, char **tabs)
{
	int nb_word;

	nb_word = 0;
	while (tabs[i] && ft_strcmp(tabs[i], "|") != 0 && (ft_strcmp(tabs[i], ";") != 0))
	{
		nb_word++;
		i++;
	}
//	printf("[%d]\n", nb_word);
	return (nb_word);
}

t_input	*ft_selector(char **tabs)
{
	int i = 0;
	int j = 0;
	int nb_input = 1;
	t_input *input;

	if (tabs[0])
	{
		while (tabs[i])
		{
			if (!ft_strcmp(tabs[i], "|") || (!ft_strcmp(tabs[i], ";")))
				nb_input++;
			i++;
		}	
		i = 0;
		input = malloc(sizeof(t_input) * nb_input + 1);
		nb_input = 0;
		while (tabs[i])
		{
			j = 0;
			input[nb_input].args = malloc(sizeof(char *) * (ft_count_words(i, tabs) + 1));
			while (tabs[i] && ft_strcmp(tabs[i], "|") != 0 && (ft_strcmp(tabs[i], ";") != 0))
			{
				input[nb_input].args[j] = tabs[i];
				j++;
				i++;
			}
			input[nb_input].args[i] = NULL;
			nb_input++;
			if (tabs[i + 1] && tabs[i])
				i++;
		}
	}
	i = 0;
	int tmp = nb_input;
	nb_input = 0;
	while (nb_input < tmp)
	{
		i = 0;
		ft_putstr("[");
		while (input[nb_input].args[i])
		{
			ft_putstr(input[nb_input].args[i]);
			ft_putstr(" ");
			i++;
		}
		ft_putstr("]");
		ft_putstr("\n");
		nb_input++;
	}
	return (input);
}
