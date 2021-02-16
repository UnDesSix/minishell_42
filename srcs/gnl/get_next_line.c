#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 1024

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
	ft_strncpy(new_str, old_str, ft_strlen(old_str);
	free(old_str);
	return (new_str);
}

char	*line_saver(char *buffer, ssize_t read_bytes, char **line)
{
	size_t	i;

	i = 0;
	while (i < read_bytes && buffer[i] != '\n')
		i++;
	if (!(*line))
	{
		*line = realloc_str(*line, i);
		ft_strncpy(*line, buffer, i);
		
	}
}

int		get_next_line(int fd, char **line)
{
	static char		buffer[BUFF_SIZE];
	static size_t	index = 0;
	ssize_t			read_bytes;
	int				status;

	read_bytes = 1;
	*line = NULL;
	while (read_bytes)
	{
		read_bytes = read(fd, buffer, BUFF_SIZE);
		status = line_saver(buffer, read_bytes, line);
		if (read_bytes < 0)
			return (-1);
		if (status)
	}
	
}

int		main()
{
	char	*line = NULL;
	int		i = 0;

	while (get_next_line(0, &line) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
	free(line);
	return (0);
}
