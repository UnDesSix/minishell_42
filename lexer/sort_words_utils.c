/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_words_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 09:39:35 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/22 15:04:13 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		ft_word_size(t_word *word)
{
	int	i;

	i = 0;
	while (word[i].content)
		i++;
	return (i);
}

t_word	*ft_wordjoin(t_word *w1, t_word *w2)
{
	int		len1;
	int		len2;
	int		i;
	t_word	*dst;

	i = 0;
	if (!w1)
		return (ft_wordup(w2));
	if (!w2)
		return (ft_wordup(w1));
	len1 = ft_word_size(w1);
	len2 = ft_word_size(w2);
	dst = malloc(sizeof(t_word) * (len1 + len2 + 1));
	len1 = 0;
	len2 = 0;
	while (w1[len1].content)
	{
		dst[len1] = w1[len1];
		dst[len1].content = w1[len1].content;
		len1++;
	}
	while (w2[len2].content)
		dst[len1++] = w2[len2++];
	dst[len1].content = NULL;
	return (dst);
}
