/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:48:00 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/21 18:18:49 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
** TODO : Split main into ENV / EXPORT / UNSET
*/

/*
**	The function tabs_to_list converts envp (char **) into a
**	chained list. The function takes one parameter : envp.
**	It returns a pointer to the begenning of the list if everything went well.
**	Otherwise, it returns a NULL pointer (if malloc failed for instance).
*/

t_list	*tabs_to_list(char **envp)
{
	t_list	*begin_list;
	int		env_size;
	
	env_size = 0;
	while (envp[env_size])
		env_size++;
	begin_list = ft_list_push_strs(env_size, envp);
	if (!begin_list)
		return (NULL);
	return (begin_list);
}

/*
**	The function env_builtin displays the environment.
**	The function takes two parameters, beginning of the list and argv.
**	It should be called alone without any arguments. If there are argument
**	it returns error 1 and display a error message. This error dooesn t exist 
**	in the real function. 
**	Otherwise, it displays the list of environemental variables, with the last
**	variables at the end of the list and returns 0.
*/

int		env_builtin(t_list *begin_list, t_word *word)
{
	t_list	*tmp;

	tmp = begin_list;
	if (!(word[1].content))
	{
		while (tmp)
		{
			if (((t_var *)tmp->data)->is_define)
			{
				printf("%s=", ((t_var *)tmp->data)->name);
				printf("%s\n", ((t_var *)tmp->data)->content);
			}
			tmp = tmp->next;
		}
		return (0);
	}
	printf("env: env should be used without option or argument\n");
	return (1);
}

/*
**	The function unset_builtin remove a variable from the env list.
**	The function takes two parameters, the address of the address of the
**	beginning of list and argv. It takes a 't_list **' because the first
**	element can be remove. Simply using a 't_list *' would generate mistakes.
**	The only way the function returns an error (1), is if the variable name
**	is not valid : see var_syntac_is_ok function.
**	Otherwise, it removes the given variables and returns 0.
*/

int		unset_builtin(t_list **begin_list, t_word *word)
{
	int		i;

	i = 1;
// CHECK SYNTAX FOR ALL VARIABLES
	while (word[i].content)
	{
		if (!var_is_well_syntaxed(word[i].content, "unset"))
			return (1);
		ft_list_remove_if(begin_list, word[i].content, ft_strcmp, free_var);
		i++;
	}
//	t_list	*tmp1 = *begin_list;
//	while (tmp1)
//	{
//		printf("%s=", ((t_var *)tmp1->data)->name);
//		printf("%s\n", ((t_var *)tmp1->data)->content);
//		tmp1 = tmp1->next;
//	}
	return (0);
}

/*
**	Segfault without argument because first if is going somewhere it should not
*/

//int		sub_main(t_block block, char **envp)
//{
//	t_list	*begin_list;
//
//	begin_list = tabs_to_list(envp);
//	if (ft_strcmp(block.word[0].content, "env") == 0)
//		env_builtin(begin_list, block);
//	else if (ft_strcmp(block.word[0].content, "unset") == 0)
//		unset_builtin(&begin_list, block);
//	else if (ft_strcmp(block.word[0].content, "export") == 0)
//		export_builtin(begin_list, block);
//	ft_list_clear(begin_list, free_var);
//	return (0);
//}
