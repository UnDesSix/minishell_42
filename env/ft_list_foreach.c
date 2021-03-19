/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:46:43 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/03 18:18:46 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

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
