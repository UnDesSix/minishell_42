/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:46:48 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/03 18:18:51 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*elem;

	if (!(*begin_list))
		*begin_list = ft_create_elem(data);
	else
	{
		elem = *begin_list;
		while (elem->next)
			elem = elem->next;
		elem->next = ft_create_elem(data);
	}
}
