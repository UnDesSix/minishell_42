/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:10:27 by mlarboul          #+#    #+#             */
/*   Updated: 2021/02/25 11:53:58 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
** NEED TO ADD (t_var *) line 15 ?
*/

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*elem;

	if (!begin_list)
		return (NULL);
	elem = begin_list;
	while (elem)
	{
		if (!((*cmp)(elem->data->name, data_ref)))
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}
