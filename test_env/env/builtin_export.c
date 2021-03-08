/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:08:37 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/03 15:38:38 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
**	This function is called when export builtin doesn't have any argument.
**	The function export_alone duplicates the existing list, sorts it by ASCII
**	order, converts it into 'char **' tabs using state '1' (see list_to_tabs).
**	Then the function adds 'declare -x' to each varaible and prints the tabs.
**	The function takes one parameter, the address of the beginning of list.
**	Returns '-1' if something wrong happens (most likely malloc issue).
**	Otherwise function should return '0'.
*/

int	export_alone(t_list *begin_list)
{
	char	**tabs;
	char	*tmp;
	t_list	*dup_list;
	int		i;

	i = 0;
	if (ft_list_duplicate(&dup_list, begin_list) < 0)
		return (-1);
	ft_list_sort(&dup_list, ft_strcmp);
	tabs = list_to_tabs(dup_list, 1);
	if (!tabs)
		return (-1);
	ft_list_clear(dup_list, free_var);
	while (tabs[i])
	{
		tmp = ft_strjoin("declare -x ", tabs[i]);
		if (!tmp)
			return (-1);
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
**	The function takes two parameters, the address of the address of the
**	beginning of list and the address of a s_block variable.
**	It can be called alone or with several arguments. If at least one of the
**	argument is bad-syntaxed it returns error 1 and display a error message.
**	Otherwise, it displays the list of environemental variables, with the last
**	variables at the end of the list and returns 0.
**	TODO :	- line 69 -> add export_argv
**			- change "char **argv" by "t_block *block"
*/

int	export_builtin(t_list *begin_list, t_block block)
{
	int		i;
	int		var_is_def;
	t_var	*var;

	i = 2;
	if (!block.word[1].content)
		return (export_alone(begin_list));
	return (export_variable(block, &begin_list));
}
