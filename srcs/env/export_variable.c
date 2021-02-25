/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:48:12 by mlarboul          #+#    #+#             */
/*   Updated: 2021/02/25 13:52:08 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	create_var(t_list **begin_list, char *name, char *content, int status)
{
	t_var	*new_data;

	new_data = malloc(sizeof(t_var));
	if (!new_data)
		return (0);
	new_data->name = ft_strdup(name);
	new_data->is_define = 0;
	if (status)
	{
		new_data->is_define = 1;
		new_data->content = ft_strdup(content);
	}
	else
		new_data->content = NULL;
	ft_list_push_back(begin_list, new_var);
	return (1);
}

/*
**	TODO : NEED TO ADD (t_var *) for (elm_found->data)
*/

int	perm_var_filled(t_list **begin_list, t_list *elm_found,
					s_word *word, int *i)
{
	int	j;

	j = *i;
	if (!elm_found)
	{
		if (!create_var(begin_list, word[j].name, word[j + 2].content, 1))
			return (-1);
	}
	else
	{
		free(elm_found->data->content);
		elm_found->data->content = ft_strdup(content);
	}
	j += 2;
	*i = j;
	return (0);
}

/*
**	TODO : NEED TO ADD (t_var *) for (elm_found->data)
*/

int	perm_var_empty(t_list *elm_found, s_word *word, int *i)
{
	int	j;

	j = *i;
	if (!elm_found)
	{
		if (!create_var(begin_list, word[j].name, "", 1))
			return (-1);
	}
	else
	{
		free(elm_found->data->content);
		elm_found->data->content = ft_strdup(content);
	}
	j++;
	*i = j;
	return (0);
}

int	perm_variables(t_list **begin_list, s_word *word, int *i)
{
	t_list	*elm_found;

	elm_found = ft_list_find(*begin_list, word[i].name, ft_strcmp);
	if (!word[i + 1].space && !word[i + 2])
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

/*
** export_variables adds new elements to the list.
*/

int	export_variable(t_block *block, t_list **begin_list)
{
	int		i;
	s_word	*word;
	t_list	*elm_found;

	i = 0;
	word = block->word;
	while (word[i] && word[i].type == 1
		&& var_syntax_is_ok(word[i].content, "export"))
	{
		if (!word[i].space && !word[i] && !ft_strcmp(word[i + 1], "="))
		{
			if (perm_variables(begin_list, word, &i) < 0)
				return (-1);
		}
		else
		{
			elm_found = ft_list_find(*begin_list, word[i].name, ft_strcmp);
			if (!elm_found)
				if (!create_var(begin_list, word[i].name, NULL, 0))
					return (-1);
		}
		i++;
	}
	return (0);
}
