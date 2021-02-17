/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:47:41 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/30 16:45:25 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsh.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*dst;
	unsigned int	i;

	dst = (char *)malloc(count * size);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		dst[i] = 0;
		i++;
	}
	return ((void *)dst);
}
