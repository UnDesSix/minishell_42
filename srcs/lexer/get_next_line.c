/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:05:25 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/04 20:05:36 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

char	*ft_strjoin_char(char *str, char c)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	ret = (char *)malloc(sizeof(char) * (i + 2));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i++] = c;
	ret[i] = '\0';
	return (ret);
}

char	*manage_stack(char *old_stack, char buffer)
{
	char	*tmp;
	char	*stack;

	if (!old_stack)
	{
		stack = (char *)malloc(sizeof(char) * 2);
		if (!stack)
			return (NULL);
		stack[0] = buffer;
		stack[1] = '\0';
	}
	else
	{
		stack = ft_strjoin_char(old_stack, buffer);
		if (!stack)
			return (NULL);
	}
	return (stack);
}

int	get_next_line(int fd, char **line)
{
	static char	*stack = NULL;
	char		buffer;
	int			ret;
	char		*tmp;

	ret = 1;
	*line = NULL;
	stack = NULL;
	buffer = '\0';
	while (ret)
	{
		ret = read(fd, &buffer, 1);
		if (buffer != '\n')
		{
			tmp = manage_stack(stack, buffer);
			free(stack);
			stack = tmp;
		}
		if (buffer == '\n')
			break ;
	}
	if (buffer == '\0')
		return (0);
	*line = stack;
	return (1);
}
