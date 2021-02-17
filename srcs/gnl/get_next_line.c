#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFF_SIZE 3

typedef struct	s_gnl_saver
{
	char	buffer[BUFF_SIZE];
	ssize_t	read_bytes;
	ssize_t	size_line;
	size_t	index; // Index tells us where we are in the buffer
}				t_gnl_saver;

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

char	*realloc_str(char *old_str, size_t add_size)
{
	char	*new_str;
	// Possibility to add a new var -> size of old str

	if (!old_str)
	{
		new_str = malloc(sizeof(char) * (add_size + 1));
		new_str[add_size + 1] = '\0';
		if (!new_str)
			return (NULL);
		return (new_str);
	}
	new_str = malloc(sizeof(char) * (ft_strlen(old_str) + add_size + 1));
	if (!new_str)
		return (NULL);
	new_str[ft_strlen(old_str) + add_size + 1] = '\0';
	ft_strncpy(new_str, old_str, ft_strlen(old_str));
	free(old_str);
	return (new_str);
}

/*
//	This function allocate (or reallocate) enough space to copy the buffer
//	int final line.
//	The return value "status" can be :
//		- 1  : there is a '\n'
//		- 0  : there is not a '\n'
//		- -1 : something wrong happened
*/
int		line_saver(t_gnl_saver *saver, char **line)
{
	size_t	i;
	size_t	j;
	int		status;

	i = saver->index;
	while (i < saver->read_bytes && saver->buffer[i] != '\n')
		i++;
	if (saver->buffer[i] == '\n')
		status = 1;
	else
		status = 0;
	if (!(*line))
	{
		*line = realloc_str(*line, i);
		ft_strncpy(*line, saver->buffer, i - saver->index);
		saver->size_line = i - saver->index;
		saver->index += i;
		return (status);
	}
	*line = realloc_str(*line, i);
	ft_strncpy(*line + saver->size_line, saver->buffer + saver->index, i - saver->index);
	saver->index += i;
	return (status);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl_saver	saver;
	int					status;

	saver.read_bytes = 1;
	saver.size_line = 0;
	saver.index = 0;
	status = 0;
	*line = NULL;
	while (saver.read_bytes && !status)
	{
		saver.read_bytes = read(fd, saver.buffer, BUFF_SIZE);
		status = line_saver(&saver, line);
		if (saver.read_bytes < 0)
			return (-1);
	}
	if (!saver.read_bytes)
		return (0);
	return (1);
}

int		main()
{
	char	*line;
	int		i = 0;

	while (get_next_line(0, &line) == 1)
	{
		if (line)
		{
			printf("%s\n", line);
			free(line);
		}
	}
	if (line)
		free(line);
	return (0);
}
