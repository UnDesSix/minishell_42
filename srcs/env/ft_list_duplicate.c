/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_duplicate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:08:23 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/03 18:57:50 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
**	This function duplicates the structure t_var.
**	If the src_list is NULL *dst_list will be NULL too and the function returns
**	(0). If src_list is not NULL and *dst_list will equal to the address of the
**	beginning of the list and will return (0). If something wrong happens, most
**	likely malloc errors, the function returns (-1).
*/

t_var	*ft_var_duplicate(t_var *data)
{
	t_var	*new_data;

	if (!data)
		return (NULL);
	new_data = malloc(sizeof(t_var));
	if (!new_data)
		return (NULL);
	new_data->name = ft_strdup(data->name);
	new_data->content = ft_strdup(data->content);
	new_data->is_define = data->is_define;
	return (new_data);
}

/*
**	This function duplicates an existing list and its datas.
**	If the src_list is NULL *dst_list will be NULL too and the function returns
**	(0). If src_list is not NULL and *dst_list will equal to the address of the
**	beginning of the list and will return (0). If something wrong happens (most)
**	likely malloc errors, the function returns (-1).
**	The only case *dst_size can be NULL because of an error is if malloc failed
**	on the first call of ft_list_push_back. 
*/

int		ft_list_duplicate(t_list **dst_list, t_list *src_list)
{
	t_var	*tmp;

	*dst_list = NULL;
	if (!src_list)
		return (0);
	while (src_list)
	{
		tmp = ft_var_duplicate(src_list->data);
		if (tmp == NULL)
			return (-1);
		ft_list_push_back(dst_list, tmp);
		if (*dst_list == NULL)
			return (-1);
		src_list = src_list->next;
	}
	return (0);
}
