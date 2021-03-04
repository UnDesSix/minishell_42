/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:02:27 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/30 16:54:25 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsh.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		size;
	char	*dest;

	i = 0;
	size = ft_strlen(str);
	if (!str)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (0);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
