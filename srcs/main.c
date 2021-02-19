#include "includes/header.h"

int main(int argc, char **argv)
{
	char	*line;
	int		ret = 0;
	char 	**tabs;
	t_input	*input;

	while (1)
	{
		ft_putstr("➜ msh ");
		ret = get_next_line(0, &line);
		if (ret <= 0)
			return (0);
		tabs = ft_split(line, ' ');
		input = ft_selector(tabs);
//		ft_redirections(&input);		
		ft_execute(input);
	}
	return (0);
}
