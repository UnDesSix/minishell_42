#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_nl(char const *str, int c);

int	ft_handle_err(int ret, char **line, char **stack)
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

int	ft_verify_line(int ret, char **line, char **stack)
{
	char	*tmp;
	char	*tmp_stack;
	int		err;

	err = ft_handle_err(ret, line, stack);
	if (err != 1)
		return (err);
	tmp = ft_nl(*stack, '\n');
	if (tmp)
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
	}
	return (0);
}

int	ft_extra_function_because_the_norm_sucks(char **buff, int fd, char **line)
{
	*buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL || (!(buff)))
		return (-1);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*stack[256];
	char		*buff;
	int			ret;
	char		*tmp;

	if (ft_extra_function_because_the_norm_sucks(&buff, fd, line) == -1)
		return (-1);
	ret = 1;
	while (ret)
	{
		ret = read(fd, buff, BUFFER_SIZE);
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
	return (ft_verify_line(ret, &*line, &stack[fd]));
}
