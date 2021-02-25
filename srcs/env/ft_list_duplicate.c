/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_duplicate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:08:23 by mlarboul          #+#    #+#             */
/*   Updated: 2021/02/25 11:53:53 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_var	*ft_var_duplicate(t_var *data)
{
	t_var	*new_data;

	new_data = malloc(sizeof(t_var));
	if (!new_data)
		return (NULL);
	new_data->name = ft_strdup(data->name);
	new_data->content = ft_strdup(data->content);
	new_data->is_define = data->is_define;
	return (new_data);
}

void	ft_list_duplicate(t_list **new_list, t_list *begin_list)
{
	t_var	*tmp;

	*new_list = NULL;
	if (!begin_list)
		return ;
	while (begin_list)
	{
		tmp = ft_var_duplicate(begin_list->data);
		ft_list_push_back(new_list, tmp);
		begin_list = begin_list->next;
	}
}
