#include "ft_list.h"

void	free_tabs(char **tabs)
{
	int	i;

	i = 0;
	while (tabs[i])
		free(tabs[i++]);
	free(tabs);
}

int	ft_list_size(t_list *begin_list, int type)
{
	int count;

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

void	list_to_tabs_env(t_list *begin_list, char **tabs, int size)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < size)
	{
		tabs[i] = ft_strdup(((t_var *)begin_list->data)->name);
		tmp = ft_strjoin(tabs[i], "=");
		free(tabs[i]);
		tabs[i] = ft_strjoin(tmp, ((t_var *)begin_list->data)->content);
		free(tmp);
		i++;
	}
	tabs[i] = NULL;
}

char	*conc_var(char *tmp, char *content)
{
	char *tab;

	tab = ft_strjoin(tmp, "=\"");
	free(tmp);
	tmp = ft_strjoin(tab, content);
	free(tab);
	tab = ft_strjoin(tmp, "\"");
	free(tmp);
	return (tab);
}

void	list_to_tabs_export(t_list *begin_list, char **tabs, int size)
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
			i++;
			begin_list = begin_list->next;
		}
	}
	tabs[i] = NULL;
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
		list_to_tabs_env(begin_list, tabs, size);
	if (type == 1)
		list_to_tabs_export(begin_list, tabs, size);
	return (tabs);
}
