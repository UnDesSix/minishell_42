#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFF_SIZE 3

void	update_buff(char *buffer)
{
	int		i;
	int		j;
	char	tmp[BUFF_SIZE + 1];

	i = -1;
	while (buffer[++i])
		tmp[i] = buffer[i];
	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (i < BUFF_SIZE)
		buffer[j++] = tmp[i++];
	while (j < BUFF_SIZE)
		buffer[j++] = '\0';
}

int		save_line(char **line, char *buffer)
{
	int	i;
	int	j;
	int	r_val;

	i = 0;
	j = -1;
	r_val = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		r_val = 1;
	if (!(*line))
	{
		*line = malloc(sizeof(char) * (i + 1));
		if (!*line)
			return (-1);
		while (++j < i)
			(*line)[j] = buffer[j];
		(*line)[j] = '\0';
		return (r_val);
	}
	return (r_val);
}

int		get_next_line(int fd, char **line)
{
	static char	buffer[BUFF_SIZE + 1];
	int			read_bytes;
	int			i;

	read_bytes = 1;
	*line = NULL;
	i = 0;
	while (read_bytes)
	{
		if (!buffer[0])
			read_bytes = read(fd, buffer, BUFF_SIZE);
		buffer[BUFF_SIZE] = '\0';
		if (save_line(line, buffer) == 1)
		{
			update_buff(buffer);
			return (1);
		}
	}
	return (0);
}

int		main()
{
	char	*line;
	int		i = 0;

	while (get_next_line(0, &line) == 1)
	{
		if (line)
		{
			printf("line %d : \"%s\"\n", i++, line);
			free(line);
		}
	}
	if (line)
		free(line);
	return (0);
}
