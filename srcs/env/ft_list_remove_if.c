#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
											int (*cmp)(), int len)
{
	t_list *elem;
	t_list *temp;

	while (*begin_list && !((*cmp)((*begin_list)->data, data_ref, len)))
	{
		temp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(temp->data);
		free(temp);
	}
	elem = *begin_list;
	while (elem && elem->next)
	{
		if (!((*cmp)(elem->next->data, data_ref, len)))
		{
			temp = elem->next;
			elem->next = temp->next;
			free(temp->data);
			free(temp);
		}
		else
			elem = elem->next;
	}
}
