/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:04:21 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/22 00:16:16 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsh.h"

static int	ft_is_in_set(int c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == (int)set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_fill_str(char const *s1, char const *set, char *str, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_is_in_set(s1[i], set))
		i++;
	while (j < len)
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!set)
		return (ft_strdup(s1));
	if (!s1)
		return (0);
	while (ft_is_in_set(s1[i], set))
		i++;
	len = ft_strlen(s1) - i;
	if (len == 0)
		return (ft_strdup(""));
	i = ft_strlen(s1) - 1;
	while (ft_is_in_set(s1[i], set))
	{
		i--;
		len--;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	return (ft_fill_str(s1, set, str, len));
}
