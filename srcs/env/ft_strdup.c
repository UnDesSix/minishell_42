#include "ft_list.h"

char	*ft_strdup(const char *str)
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

