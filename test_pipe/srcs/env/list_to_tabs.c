/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_tabs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:47:54 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/03 18:19:10 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		ft_list_size(t_list *begin_list, int type)
{
	int	count;

	count = 0;
	while (begin_list)
	{
		if (!type && ((t_var *)begin_list->data)->is_define)
			count++;
		else if (type && ft_strcmp(((t_var *)begin_list->data)->name, "_"))
			count++;
		begin_list = begin_list->next;
	}
	return (count);
}

int		list_to_tabs_env(t_list *begin_list, char **tabs, int size)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < size)
	{
		tabs[i] = ft_strdup(((t_var *)begin_list->data)->name);
		if (!tabs[i])
			return (-1);
		tmp = ft_strjoin(tabs[i], "=");
		if (!tmp[i])
			return (-1);
		free(tabs[i]);
		tabs[i] = ft_strjoin(tmp, ((t_var *)begin_list->data)->content);
		if (!tabs[i])
			return (-1);
		free(tmp);
		i++;
	}
	tabs[i] = NULL;
	return (0);
}

char	*conc_var(char *tmp, char *content)
{
	char	*tab;

	tab = ft_strjoin(tmp, "=\"");
	if (!tab)
		return (NULL);
	free(tmp);
	tmp = ft_strjoin(tab, content);
	if (!tmp)
		return (NULL);
	free(tab);
	tab = ft_strjoin(tmp, "\"");
	if (!tab)
		return (NULL);
	free(tmp);
	return (tab);
}

int		list_to_tabs_export(t_list *begin_list, char **tabs, int size)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < size)
	{
		if (!ft_strcmp(((t_var *)begin_list->data)->name, "_"))
			begin_list = begin_list->next;
		else
		{
			tmp = ft_strdup(((t_var *)begin_list->data)->name);
			if (!(((t_var *)begin_list->data)->content))
				tabs[i] = tmp;
			else
				tabs[i] = conc_var(tmp, ((t_var *)begin_list->data)->content);
			if (!tabs[i])
				return (-1);
			i++;
			begin_list = begin_list->next;
		}
	}
	tabs[i] = NULL;
	return (0);
}

/*
**	The function list_to_tabs converts chained list into a array of char *.
**	The function takes two parameters, the beginning of the list and a the
**	type of tabs output required. The output can be for env(0), which simply
**	has a syntax like : var_name=var_content. Plus, it doesn't include varibles
**	for which  var_is_define different from 1.
**	Otherwise, the output is for export (1) which has a syntax a bit different
**	: var_name="var_content". It takes all variables into account exept a
**	specific one : "_=var_content".
*/

char	**list_to_tabs(t_list *begin_list, int type)
{
	int		size;
	char	**tabs;

	size = ft_list_size(begin_list, type);
	tabs = malloc(sizeof(char *) * (size + 1));
	if (!tabs)
		return (NULL);
	if (type == 0)
		if (list_to_tabs_env(begin_list, tabs, size) < 0)
			return (NULL);
	if (type == 1)
		if (list_to_tabs_export(begin_list, tabs, size) < 0)
			return (NULL);
	return (tabs);
}
