/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:18:16 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/19 16:21:37 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	ft_check_lexer(t_word *word)
{
	int	i;

	i = 0;
	while (word[i].content)
	{
		if (ft_strcmp(word[i].content, ";") == 0)
			if (word[i + 1].content == NULL && i == 0)
			{
				ft_putstr("bash: syntax error near unexpected token `;'\n");
				return (0);
			}
		i++;
	}
	return (1);
}
