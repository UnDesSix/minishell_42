/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_var_syntax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:48:17 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/21 20:25:57 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

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
		printf("msh: %s: `%s': invalid parameter name\n", builtin, str);
		return (FALSE);
	}
	i++;
	while (str[i])
	{
		if (ft_isalnum(str[i]) == FALSE && str[i] != '_')
		{
			printf("msh: %s: `%s': invalid parameter name\n", builtin, str);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
