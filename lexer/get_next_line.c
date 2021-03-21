/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:05:25 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/21 21:05:42 by calide-n         ###   ########.fr       */
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

int		ft_check_multi_lines(char **stack, char buffer)
{
	int		i;
	char	*tmp_stack;

	i = 0;
	if (buffer != '\n')
		return (1);
	if (!*stack)
		return (0);
	while ((*stack)[i])
		i++;
	if ((*stack)[i - 1] == '\\' && (*stack)[i - 2] != '\\')
	{
		ft_putstr("> ");
		(*stack)[i - 1] = 0;
		tmp_stack = ft_strdup(*stack);
		free(*stack);
		*stack = tmp_stack;
		return (1);
	}
	return (0);
}

int		ctrl_d(char **line, char buffer, char *stack)
{
	(void)stack;
	if (buffer == '\0')
	{
		*line = ft_strdup("exit");
		printf("exit\n");
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*stack = NULL;
	char		buffer;
	int			ret;
	char		*tmp;

	*line = NULL;
	stack = NULL;
	buffer = '\0';
	while (1)
	{
		ret = read(fd, &buffer, 1);
		if (ctrl_d(line, buffer, stack))
			return (1);
		if (buffer != '\n' && ret != 0)
		{
			tmp = manage_stack(stack, buffer);
			free(stack);
			stack = tmp;
		}
		if (!ft_check_multi_lines(&stack, buffer))
			break ;
	}
	*line = stack;
	return (1);
}
