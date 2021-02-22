#include "includes/header.h"

int main(int argc, char **argv)
{
	char	*line;
	int		ret = 0;
	char 	**tabs;
	t_input	*input;
	int		nb_blocks = 0;

	while (1)
	{
		ft_putstr("➜ msh ");
		ret = get_next_line(0, &line);
		if (ret <= 0)
			return (0);
		tabs = ft_split(line, ' ');
		input = ft_selector(tabs, &nb_blocks);
//		ft_redirections(&input);		
		if (input)
			ft_execute(input, nb_blocks);
	}
	return (0);
}
