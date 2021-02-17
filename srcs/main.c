#include <stdio.h>

char **ft_split(char *str, char c);

int main(int argc, char **argv)
{
	char **tab;

	tab = ft_split(argv[1], ' ');
	for (int i = 0; tab[i]; i++)
		printf("[%s]\n", tab[i]);
	return (0);
}
