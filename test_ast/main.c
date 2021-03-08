#include "ft_btree.h"
#define COUNT 10

void print2DUtil(t_btree *node, int space) 
{ 
	// Base case 
	if (!node) 
		return; 

	// Increase distance between levels 
	space += COUNT; 

	// Process right child first 
	print2DUtil(node->right, space); 

	// Print current node after space 
	// count 
	printf("\n"); 
	for (int i = COUNT; i < space; i++) 
		printf(" "); 
	printf("[%s]\n", node->item); 

	// Process left child 
	print2DUtil(node->left, space); 
} 


void	create_ast(t_btree **node, char **tabs, int index)
{
	int		i;

	i = index;
	while (tabs[i])
	{
		if (!strcmp(tabs[i], "|"))
		{
			*node = btree_create_node(strdup(tabs[i]));
			tabs[i] = NULL;
			create_ast(&(*node)->left, tabs, index);
			create_ast(&(*node)->right, tabs, i + 1);
		}
		i++;
	}
	i = index;
	while (tabs[i])
	{
		if (!strcmp(tabs[i], ">"))
		{
			*node = btree_create_node(strdup(tabs[i]));
			tabs[i] = NULL;
			create_ast(&(*node)->right, tabs, index);
			create_ast(&(*node)->left, tabs, i + 1);
		}
		i++;
	}
	i = index;
	while (tabs[i])
	{
		if (!strcmp(tabs[i], "ls") || !strcmp(tabs[i], "echo")
			|| !strcmp(tabs[i], "oups"))
		{
			*node = btree_create_node(strdup(tabs[i]));
			tabs[i] = NULL;
			return ;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	**tabs;
	t_btree *root = NULL;

	tabs = malloc(sizeof(char *) * (argc + 1));
	for (i = 0; i < argc - 1; i++)
		tabs[i] = strdup(argv[i + 1]);
	tabs[i] = NULL;
//	for (i = 0; tabs[i]; i++)
//		printf("%s\n", tabs[i]);
	create_ast(&root, tabs, 0);
//	printf("root  : [%s]\n", root->item);
//	printf("left  : [%s]\n", root->left->item);
//	printf("right : [%s]\n", root->right->item);
	print2DUtil(root, 0);
}
