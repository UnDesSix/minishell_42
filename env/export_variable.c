/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:48:12 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/21 23:28:46 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
**	This function is called when the variable content is not empty. It takes
**	four parameters :
**		- begin_list : in order to create a new variable and add the element
**		to the current list (using create_var function).
**		- elm_found : equal to the element with a the same variable name.
**		Otherwise it is equal to NULL.
**		- word : to access to the variable name and content.
**		- i : the adress of the index so it can be increment from that
**		particular function.
**	The function returns (-1) if a error occurs and (0) if everything went well.
*/

int	perm_var_filled(t_list **begin_list, t_list *elm_found,
		t_word *word, int *i)
{
	int	j;

	j = *i;
	if (!elm_found)
	{
		if (create_var(begin_list, word[j].content, word[j + 2].content, 1) < 0)
			return (-1);
	}
	else
	{
		free(((t_var *)elm_found->data)->content);
		((t_var *)elm_found->data)->content = ft_strdup(word[j + 2].content);
		if (!(((t_var *)elm_found->data)->content))
			return (-1);
	}
	j += 2;
	*i = j;
	return (0);
}

/*
**	This function is called when the variable content is empty. It takes four
**	parameters :
**		- begin_list : in order to create a new variable and add the element
**		to the current list (using create_var function).
**		- elm_found : equal to the element with a the same variable name.
**		Otherwise it is equal to NULL.
**		- word : to access to the variable name and content.
**		- i : the adress of the index so it can be increment from that
**		particular function.
**	The function returns (-1) if a error occurs and (0) if everything went well.
*/

int	perm_var_empty(t_list **begin_list, t_list *elm_found,
		t_word *word, int *i)
{
	int	j;

	j = *i;
	if (!elm_found)
	{
		if (create_var(begin_list, word[j].content, "", 1) < 0)
			return (-1);
	}
	else
	{
		free(((t_var *)elm_found->data)->content);
		((t_var *)elm_found->data)->content = ft_strdup("");
		if (!(((t_var *)elm_found->data)->content))
			return (-1);
	}
	j++;
	*i = j;
	return (0);
}

/*
**	perm_variables simply checks if the variable content is right after the `='
**	(no space between) and if the content is different from a null-byte only.
**	The function returns (-1) if a error occurs and (0) if everything went well.
*/

int	perm_variables(t_list **begin_list, t_word *word, int *i)
{
	t_list	*elm_found;

	elm_found = ft_list_find(*begin_list, word[*i].content, ft_strcmp);
	if (!word[*i + 1].space && word[*i + 2].content
			&& ft_strcmp(word[*i + 2].content, ""))
	{
		if (perm_var_filled(begin_list, elm_found, word, i) < 0)
			return (-1);
	}
	else
	{
		if (perm_var_empty(begin_list, elm_found, word, i) < 0)
			return (-1);
	}
	return (0);
}

int	exp_var_well_synt(t_word *word, t_list **begin_list, int *i)
{
	t_list	*elm_found;
	
	if (!word[*i].space && word[*i + 1].content
			&& !ft_strcmp(word[*i + 1].content, "="))
	{
		if (perm_variables(begin_list, word, i) < 0)
			return (-1);
	}
	else
	{
		elm_found = ft_list_find(*begin_list, word[*i].content, ft_strcmp);
		if (!elm_found)
			if (create_var(begin_list, word[*i].content, NULL, 0) < 0)
				return (-1);
	}
	return (0);
}


/*
**	export_variables adds new elements to the list. There are two kinds of var
**	that can be added : permanent variables (stay in the envp even when execve
**	is called) and temporary variables. Temporary variables have a content equal
**	to NULL unlike permanent variables which at least have a content of one
**	null-byte.
**	This function returns either a (0) if everything went well, otherwise it
**	returns (-1), which probably results of a malloc issue.
**	The first purpose of the function is to define if the variable is either
**	permanent or temporary. Then it either call the sub-function perm_variable
**	either it creates a temp_variable (if it doesn't already exit).
**	This verification keeps going as long as the word exists, the ID equal 2
**	and the syntax is correct.
*/

int	export_variable(t_word *word, t_list **begin_list)
{
	int		i;
	int		ret;

	i = 1;
	ret = 0;
	while (word[i].content && word[i].type == 2)
	{
		if (var_is_well_syntaxed(word[i].content, "export"))
		{
			if (exp_var_well_synt(word, begin_list, &i) < 0)
				return (1);
		}
		else
			ret = 1;
		i++;
	}
	return (ret);
}
