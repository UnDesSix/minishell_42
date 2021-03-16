/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:58:49 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/15 17:10:01 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	exec_builtins(char **tab, t_list *begin_list)
{
	if (ft_strcmp(tab[0], "env") == 0)
		env_builtin(begin_list, word);
	else if (ft_strcmp(tab[0], "unset") == 0)
		unset_builtin(&begin_list, word);
	else if (ft_strcmp(tab[0], "export") == 0)
		export_builtin(begin_list, word);
	else if (ft_strcmp(tab[0], "echo") == 0)
		echo(tab);
	else if (ft_strcmp(tab[0], "cd") == 0)
		cd(tab, begin_list);
	else if (ft_strcmp(tab[0], "pwd") == 0)
		pwd();
}
