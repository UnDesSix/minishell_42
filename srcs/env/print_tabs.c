#include "ft_list.h"

void	print_tabs(char **tabs)
{
	int	i;

	i = 0;
	while (tabs[i])
	{
		printf("%s\n", tabs[i]);
		i++;
	}
}
