#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	char	*tmp;
	t_list	*elem;

	i = 0;
	elem = 0;
	if (!strs)
		return (0);
	while (i < size)
	{
		tmp = ft_strdup(strs[i]);
		ft_list_push_back(&elem, tmp);
		i++;
	}
	return (elem);
}
