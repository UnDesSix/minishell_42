#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, char *(*f)(char *, char *))
{
	t_list	*elem;

	if (!begin_list)
		return ;
	elem = begin_list;
	while (elem)
	{
		elem->data = (*f)("export -x ", elem->data);
		elem = elem->next;
	}
}
