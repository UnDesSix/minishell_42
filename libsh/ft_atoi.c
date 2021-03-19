/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:46:05 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/30 16:36:59 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsh.h"

int	ft_atoi(char const *str)
{
	int				i;
	long long int	sign;
	long long int	nb;

	nb = 0;
	i = 0;
	sign = 1;
	while (((str[i] > 8 && str[i] < 14) || str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + ((long long int)str[i] - 48);
		if (nb > 2147483648 && sign == 1)
			return (-1);
		if (nb > 2147483648 && sign == -1)
			return (0);
		i++;
	}
	return (nb * sign);
}
