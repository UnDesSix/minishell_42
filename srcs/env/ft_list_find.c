#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list *elem;

	if (!begin_list)
		return (NULL);
	elem = begin_list;
	while (elem)
	{
		if (!((*cmp)(elem->data->name, data_ref))) // NEED TO ADD (t_var *) ?
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}
