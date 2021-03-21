/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_words_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 09:39:35 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/19 11:08:07 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_word	*ft_wordjoin(t_word *w1, t_word *w2)
{
	int		len1;
	int		len2;
	int		i;
	t_word	*dst;

	len1 = 0;
	len2 = 0;
	i = 0;
	if (!w1)
		return (ft_wordup(w2));
	if (!w2)
		return (ft_wordup(w1));
	while (w1[len1].content)
		len1++;
	while (w2[len2].content)
		len2++;
	dst = malloc(sizeof(t_word) * (len1 + len2 + 1));
	len1 = 0;
	len2 = 0;
	while (w1[len1].content)
	{
		dst[len1] = w1[len1];
		len1++;
	}
	while (w2[len2].content)
		dst[len1++] = w2[len2++];
	dst[len1].content = NULL;
	return (dst);
}
