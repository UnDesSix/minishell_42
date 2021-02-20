#include "ft_list.h"

void	ft_list_clear(t_list *begin_list)
{
	t_list	*tmp;

	while (begin_list)
	{
		tmp = begin_list->next;
		free(begin_list);
		begin_list = tmp;
	}
}

void	ft_list_clear_data(t_list *begin_list, void (*f)(void *))
{
	t_list	*tmp;

	while (begin_list)
	{
		tmp = begin_list->next;
		f(begin_list->data);
		free(begin_list);
		begin_list = tmp;
	}
}
