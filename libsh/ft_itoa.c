/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:50:47 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/22 00:15:09 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsh.h"

static int	ft_get_nbr_size(int nb)
{
	int	size;

	size = 0;
	if (nb <= 0)
		size++;
	while (nb)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	char			*nbr;
	unsigned int	nb;
	int				size;
	int				i_stop;

	nb = n;
	size = ft_get_nbr_size(n);
	i_stop = 0;
	if (n < 0)
	{
		i_stop = 1;
		nb = -n;
	}
	nbr = malloc(sizeof(char) * (size + 1));
	if (!(nbr))
		return (0);
	if (i_stop == 1)
		nbr[0] = '-';
	nbr[size] = '\0';
	while (--size >= i_stop)
	{
		nbr[size] = nb % 10 + 48;
		nb /= 10;
	}
	return (nbr);
}
