/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 20:18:45 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/02 21:11:38 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	create_var(t_list **begin_list, char *name, char *content, int status)
{
	t_var	*new_data;

	new_data = malloc(sizeof(t_var));
	if (!new_data)
		return (-1);
	new_data->name = ft_strdup(name);
	if (!new_data->name)
		return (-1);
	new_data->is_define = 0;
	if (status)
	{
		new_data->is_define = 1;
		new_data->content = ft_strdup(content);
		if (!new_data->content)
			return (-1);
	}
	else
		new_data->content = NULL;
	ft_list_push_back(begin_list, new_var);
	if (!(*begin_list))
		return (-1);
	return (0);
}
