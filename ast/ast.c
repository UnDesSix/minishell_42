#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define PIPE 0
# define CMD 1
# define ARG 2

typedef struct s_word
{
    char    *content;
    int     sep;
    int     space;
    int     type;
    int     builtin;
}               t_word;

typedef struct	s_node
{
	void			*content;
	struct s_node	*right;
	struct s_node	*left;
}				t_node;

t_word	*create_word(char *str, int type)
{
	t_word *word = malloc(sizeof(t_word));

	word->content = strdup(str);
	word->type = type;
	return (word);
}

t_node	*create_node(t_word *word, t_node *right, t_node *left)
{
	t_node *node = malloc(sizeof(t_node));

	node->content = word->content;
	node->right = NULL;
	node->left = NULL;
	return (node);
}

int main(int argc, char **argv)
{
	t_word	**word;
	t_node	*root;
	int index;

	index = 0;
	word = malloc(sizeof(t_word *) * 6);

	word[0] = create_word("echo", CMD);
	word[1] = create_word("ok", ARG);
	word[2] = create_word("|", PIPE);
	word[3] = create_word("cat", CMD);
	word[4] = create_word("ak", ARG);
	word[5] = create_word("|", PIPE);
	word[6] = create_word("ls", CMD);
	word[7] = create_word("ok", ARG);
	word[8] = NULL;

	root = NULL;
	while (word[index])
	{
		if (word[index]->content[0] == '|')
		{
			root = create_node(word[index], NULL, NULL);
			if (root && root->right == NULL)
				root->right = create_node(word[index], NULL, NULL);
		}
		index++;
	}
	index = 0;
	while (word[index])
	{
		if (word[index]->type == CMD)
		{
			if (root->left == NULL)
				root->left = create_node(word[index], NULL, NULL);
			else
				root->right = create_node(word[index], NULL, NULL);
		}
		index++;
	}

	printf("\t%s\n", root->content);
	printf("%s", root->left->content);
	printf("\t\t%s\n", root->right->content);
	return (0);
}
