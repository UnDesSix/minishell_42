/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:41:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/01 13:04:28 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	get_next_word(char *str, int on, t_word *word)
{
	static int	i;
	int			k;
	int			j;

	k = 0;
	j = 0;
	if (on == 0)
		i = 0;
	word->sep = 0;
	word->space = 0;
	word->type = 0;
	if (ft_manage_null(str[i], word))
		return (0);
	while (str[i] == ' ')
		i++;
	if (ft_manage_semicolon(str[i], word, &i))
		return (2);
	else if (ft_manage_speop(str, word, &i))
		return (1);
	else if (ft_manage_space(str, &i, word))
		return (1);
	else if (ft_manage_all_quotes(str, word, &i))
		return (1);
	return (0);
}

/* Get next word works like GNL, it will get the next word.
 * It looks at the first character to determine if the word is 
 * between quotes, NULL, a special operator...
 * Once a word is defined, it is malloc and returned.
 */
