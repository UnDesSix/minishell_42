#include "ft_list.h"

void	free_var(void *data)
{
	free(((t_var *)data)->name);
	free(((t_var *)data)->content);
	free(data);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
								int (*cmp)(), void (*free_fct)(void *))
{
	t_list *elem;
	t_list *temp;

	while (*begin_list &&
			!(cmp(((t_var *)(*begin_list)->data)->name, data_ref)))
	{
		temp = *begin_list;
		*begin_list = (*begin_list)->next;
		(*free_fct)(temp->data);
		free(temp);
	}
	elem = *begin_list;
	while (elem && elem->next)
	{
		if (!(cmp(((t_var *)elem->next->data)->name, data_ref)))
		{
			temp = elem->next;
			elem->next = temp->next;
			free_fct(temp->data);
			free(temp);
		}
		else
			elem = elem->next;
	}
}
