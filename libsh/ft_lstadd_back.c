/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:56:03 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/30 16:48:48 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsh.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*ptr;

	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			ptr = ft_lstlast(*(alst));
			ptr->next = new;
		}
	}
}
