/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_var_syntax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:48:17 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/02 20:15:18 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_bool	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (TRUE);
	return (FALSE);
}

t_bool	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (TRUE);
	return (FALSE);
}

/*
**	This function takes two parameters the variable name to check and the name
**	name of the builtin which called the function (in order to display the
**	right error message).
**	The function return TRUE or FALSE depending if syntax is correct.
**	the variable name must began with alpha char or '_'. Then it can only
**	contains alphanumeric chars or an '_'.
*/

t_bool	var_is_well_syntaxed(char *str, char *builtin)
{
	int	i;

	i = 0;
	if (ft_isalpha(str[i]) == FALSE && str[i] != '_')
	{
		printf("bash: %s: `%s': invalid parameter name\n", builtin, argv[i]);
		return (FALSE);
	}
	i++;
	while (str[i])
	{
		if (ft_isalnum(str[i]) == FALSE && str[i] != '_')
		{
			printf("bash: %s: `%s': invalid parameter name\n", builtin, argv[i]);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
