#include  "ft_list.h"

/*
**	This function is called when export builtin doesn't have any argument.
**	The function export_alone duplicates the existing list, sorts it by ASCII
**	order, converts it into 'char **' tabs using state '1' (see list_to_tabs).
**	Then the function adds 'declare -x' to each varaible and prints the tabs.
**	The function takes one parameter, the address of the beginning of list.
**	Returns '-1' if something wrong happens (most likely malloc issue).
**	Otherwise function should return '0'.
*/
int		export_alone(t_list *begin_list)
{
	char	**tabs;
	char	*tmp;
	t_list	*dup_list;
	int		i;

	i = 0;
	ft_list_duplicate(&dup_list, begin_list);
	ft_list_sort(&dup_list, ft_strcmp);
	tabs = list_to_tabs(dup_list, 1);
	ft_list_clear(dup_list, free_var);
	while (tabs[i])
	{
		tmp = ft_strjoin("declare -x ", tabs[i]);
		free(tabs[i]);
		tabs[i] = tmp;
		i++;
	}
	print_tabs(tabs);
	free_tabs(tabs);
	return (0);
}

/*
**	The function export_builtin
**	The function takes two parameters, the address of the address of the beginning of list and argv.
**	It should be called alone with at least one arguments. If there are argument
**	it returns error 1 and display a error message.
**	Otherwise, it displays the list of environemental variables, with the last
**	variables at the end of the list and returns 0.
*/
int		export_builtin(t_list *begin_list, char **argv)
{
	int		i;
	int		var_is_def;
	t_var	*var;

	i = 2;
	if (!argv[i])
		return (export_alone(begin_list));
	// 
	while (argv[i])

	return (0);
}








	/*
	** Only to check if everything is OK
	*/
	/*
		while (begin_list)
		{
			printf("%s=", ((t_var *)begin_list->data)->name);			//USE FD_PUTSTR
			printf("%s\n", ((t_var *)begin_list->data)->content);			//USE FD_PUTSTR
			begin_list = begin_list->next;
		}
	*/
