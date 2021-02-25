/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_syntax_is_ok.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:48:17 by mlarboul          #+#    #+#             */
/*   Updated: 2021/02/25 13:53:46 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	var_syntax_is_ok(char *str, char *builtin)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[i]) && str[i] != '_')
	{
		printf("bash: %s: %s: invalid parameter name\n", builtin, argv[i]);
		return (0);
	}
	i++;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
		{
			printf("bash: %s: %s: invalid parameter name\n", builtin, argv[i]);
			return (0);
		}
		i++;
	}
	return (1);
}
