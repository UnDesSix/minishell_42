/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:26:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/05 15:59:06 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"
#define COUNT 5

void print2DUtil(t_node *root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->right, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("[%s]\n", root->data); 
  
    // Process left child 
    print2DUtil(root->left, space); 
}

int	ft_manage_line(char *line, char **envp, t_list *begin_list)
{
	t_word	*word;
	int		x;

	x = 0;
	word = ft_lexer(line);
//	if (ft_strcmp(word[0].content, "env") == 0)
//		env_builtin(begin_list, word);
//	else if (ft_strcmp(word[0].content, "unset") == 0)
//		unset_builtin(&begin_list, word);
//	else if (ft_strcmp(word[0].content, "export") == 0)
//		export_builtin(begin_list, word);		
	t_node *root;
	root = (t_node *)malloc(sizeof(t_node));
	root->data = NULL;
	root->right = NULL;
	root->left = NULL;
	ast(word, 0, root);
	print2DUtil(root, 0);
	while (word[x].content)
	{
//		ft_putstr(word[x].content);
//		ft_putstr("\n");
		free(word[x].content);
		x++;
	}
	free(word);
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	char	*line;
	int		ret;
	t_list	*begin_list;

	ret = 0;
	line = NULL;
	ft_putstr("➜ msh ");
	begin_list = tabs_to_list(envp);
	while (get_next_line(0, &line) != 0)
	{
		if (line)
			ret = ft_manage_line(line, envp, begin_list);
		ft_putstr("➜ msh ");
		free(line);
	}
	free(line);
	ft_list_clear(begin_list, free_var);
	return (0);
}
