#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_node
{
	void			*operator;
	int				value;
	struct s_node	*right;
	struct s_node	*left;

}				t_node;

t_node	*create_node(void *operator, int value, t_node *right, t_node *left)
{
	t_node *node = malloc(sizeof(t_node));
	node->operator = operator;
	node->value = value;
	node->right = right;
	node->left = left;
	return (node);
}

int	evaluate(t_node *elem)
{
	//printf("[%s] [%d] r[%d] l[%d]\n", elem->operator, elem->value, elem->right->value, elem->left->value);
	if (!elem)
		return (0);
	if (elem->value != 0)
		return (elem->value);
	if (elem->operator != NULL)
	{
		if (strcmp(elem->operator, "+") == 0)
			return (evaluate(elem->right) + evaluate(elem->left));
		if (strcmp(elem->operator, "x") == 0)
			return (evaluate(elem->right) * evaluate(elem->left));
		if (strcmp(elem->operator, "-") == 0)
			return (evaluate(elem->right) - evaluate(elem->left));
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_node	*oneNode = create_node(NULL, 1, NULL, NULL);
	t_node	*three1Node = create_node(NULL, 3, NULL, NULL);
	t_node	*three2Node = create_node(NULL, 3, NULL, NULL);
	t_node	*timeNode = create_node("x", 0, three1Node, three2Node);
	t_node	*rootNode = create_node("+", 0, oneNode, timeNode);

	printf("-> %d\n", evaluate(rootNode));
	return (0);
}

