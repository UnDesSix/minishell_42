/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:05:25 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/04 12:12:26 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char *ft_strjoin_char(char *str, char c)
{
	int i;
	char *ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (sizeof(str) + 2));
	if (!ret)
		return (NULL);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = c;
	ret[i] = '\0';
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static char *stack;
	char buffer;
	int ret;

	while (ret)
    {
        ret = read(fd, &buffer, 1);
        if (!stack)
		{
			stack = (char *)malloc(sizeof(char));
			stack[0] = c;
			stack[1] = '\0';
		}
        else
        {
            tmp = ft_strjoin_char(stack, buffer);
            free(stack);
            stack = tmp;
        }
		if (buffer == '\n')
			break;
    }
	if (buffer == '\0')
		return (0);
	return (1)
}
