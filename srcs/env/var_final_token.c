#include "ft_list.h"

int		create_var(t_list **begin_list, char *name, char *content, int status)
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

int		perm_variables(t_list **begin_list, s_word *word, int *i)
{
	t_list	*elm_found;

	elm_found = ft_list_find(*begin_list, word[i].name, ft_strcmp);
	if (!word[i + 1].space && !word[i + 2])
	{
		if (!elm_found)
			if (!create_var(begin_list, word[i], word[i + 2], 1))
				return (-1);
		if (elm_found)
		{
			free(elm_found->data->content); // NEED TO ADD (t_var *) ?
			elm_found->data->content = ft_strdup(content); // NEED TO ADD (t_var *) ?
		}
		i += 2;
	}
	else
	{
		if (!elm_found)
			if (!create_var(begin_list, word[i], "", 1))
				return (-1);
		if (elm_found)
		{
			free(elm_found->data->content); // NEED TO ADD (t_var *) ?
			elm_found->data->content = ft_strdup(content); // NEED TO ADD (t_var *) ?
		}
		i++;
	}
	return (0);
}

/*
 ** var_final_token adds new elements to the list. 
 */
int		export_variable(t_block *block, t_list **begin_list)
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
				return (-1)
		}
		else
		{
			elm_found = ft_list_find(*begin_list, word[i].name, ft_strcmp);
			if (!elm_found)
				if (!create_var(begin_list, word[i], NULL, 0))
					return (-1);
		}
		i++;
	}
	return (0);
}
