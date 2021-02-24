/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:46:06 by calide-n          #+#    #+#             */
/*   Updated: 2021/02/24 20:07:29 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int	ft_expand_word(t_word *word)
{
	int i;

	i = 0;
	//if (word->sep != '\'' && word->content[i] == '$')
	//{
	//	
	//}
	return (0);
}

int ft_expansion(t_block *block)
{
	int b;
	int w;

	b = 0;
	w = 0;
	while (block[b].stop)
	{
		while (block[b].word[w].content)
		{
			ft_expand_word(&block[b].word[w]);
			w++;
		}
		b++;
	}
	return (0);
}
