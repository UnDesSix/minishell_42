#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFF_SIZE 1024

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	free(s1);
	str[i] = '\0';
	return (str);
}

char	*update_str(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	tmp = ft_strdup(str + i);
	free(str);
	return (tmp);
}

int		create_line(char **line, char *tmp, int i, int r_v)
{
	int j;

	j = -1;
	*line = malloc(sizeof(char) * (i + 1));
	if (!*line)
		return (-1);
	while (++j < i)
		(*line)[j] = tmp[j];
	(*line)[j] = '\0';
	
	return (r_v);
}

int		check_tmp(char **line, char *tmp)
{
	int	i;
	int	j;

	i = 0;
	while (tmp[i] && (tmp[i] != '\n'))
		i++;
	if (tmp[i] == '\n')
		return (create_line(line, tmp, i, 1));
	if (tmp[i] == '\0')
		return (create_line(line, tmp, i, 0));
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*tmp = NULL;
	char 		buffer[BUFF_SIZE + 1];
	ssize_t		read_b;

	*line = NULL;
	read_b = 1;
	while (read_b)
	{
		read_b = read(fd, buffer, BUFF_SIZE);
		if (read_b == 0)
			break ;
		buffer[read_b] = '\0';
		if (!tmp || !tmp[0])
		{
			if (tmp)
				free(tmp);
			tmp = ft_strdup(buffer);
		}
		else
			tmp = ft_strjoin(tmp, buffer);
		if (check_tmp(line, tmp) == 1)
		{
			tmp = update_str(tmp);
			return (1);
		}
	}
	free(tmp);
	return (0);
}

int		main()
{
	char	*line;
	int		i = 0;

	while (get_next_line(0, &line) == 1)
	{
		printf("line %d : \"%s\"\n", i++, line);
		free(line);
	}
	printf("line %d : \"%s\"\n", i++, line);
	free(line);
	return (0);
}
