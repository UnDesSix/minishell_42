/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:48:00 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/22 00:19:21 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	increment_shlvl(t_list *begin_list)
{
	t_list	*elm_found;
	int		level;
	t_var	*new_var;

	elm_found = ft_list_find(begin_list, "SHLVL", ft_strcmp);
	if (!elm_found)
	{
		new_var = malloc(sizeof(t_var));
		new_var->name = ft_strdup("SHLVL");
		new_var->content = ft_strdup("1");
		ft_list_push_back(&begin_list, new_var);
		return ;
	}
	level = ft_atoi(((t_var *)elm_found->data)->content);
	level++;
	free(((t_var *)elm_found->data)->content);
	((t_var *)elm_found->data)->content = ft_itoa(level);
}

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
	increment_shlvl(begin_list);
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

char	*unset_conca(t_word *word, int *i)
{
	char	*tmp;
	char	*str_to_unset;

	str_to_unset = ft_strdup(word[*i].content);
	if (str_to_unset == NULL)
		return (NULL);
	while (word[*i].content && !word[*i].space && word[*i + 1].content)
	{
		tmp = ft_strdup(str_to_unset);
		if (tmp == NULL)
			return (NULL);
		free(str_to_unset);
		str_to_unset = ft_strjoin(tmp, word[*i + 1].content);
		if (str_to_unset == NULL)
			return (NULL);
		free(tmp);
		*i = *i + 1;
	}
	return (str_to_unset);
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
	int		ret;
	char	*str_to_unset;

	i = 1;
	ret = 0;
	while (word[i].content)
	{
		str_to_unset = unset_conca(word, &i);
		if (str_to_unset == NULL)
			return (1);
		if (var_is_well_syntaxed(str_to_unset, "unset"))
			ft_list_remove_if(begin_list, str_to_unset, ft_strcmp, free_var);
		else
			ret = 1;
		if (str_to_unset)
			free(str_to_unset);
		i++;
	}
	return (ret);
}
