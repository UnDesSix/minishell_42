#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_handle_err(int ret, char **line, char **stack)
{
	if (!ret && !*stack)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (ret < 0)
	{
		if (*stack != NULL)
		{
			free(*stack);
			*stack = NULL;
		}
		return (-1);
	}
	return (1);
}

int		ft_verify_line(int ret, char **line, char **stack)
{
	size_t	i;
	char	*tmp;
	char	*tmp_stack;
	int		err;

	i = 0;
	if ((err = ft_handle_err(ret, line, stack)) != 1)
		return (err);
	if ((tmp = ft_nl(*stack, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(*stack);
		tmp_stack = ft_strdup(tmp + 1);
		free(*stack);
		*stack = tmp_stack;
		return (1);
	}
	else if (ft_nl(*stack, '\0'))
	{
		*line = ft_strdup(*stack);
		free(*stack);
		*stack = NULL;
		return (0);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*stack[256];
	char		*buff;
	int			ret;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL ||
			(!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!stack[fd])
			stack[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(stack[fd], buff);
			free(stack[fd]);
			stack[fd] = tmp;
		}
		if (ft_nl(stack[fd], '\n'))
			break ;
	}
	free(buff);
	buff = NULL;
	return (ft_verify_line(ret, &*line, &stack[fd]));
}
