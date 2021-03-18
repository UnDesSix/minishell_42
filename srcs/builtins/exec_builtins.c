/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:58:49 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/18 15:47:56 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	exec_builtins(t_word *word, t_list *begin_list)
{
	if (ft_strcmp(word[0].content, "env") == 0)
	{
		if (env_builtin(begin_list, word) != 0)
			return (1);
	}
	else if (ft_strcmp(word[0].content, "unset") == 0)
		unset_builtin(&begin_list, word);
	else if (ft_strcmp(word[0].content, "export") == 0)
		export_builtin(begin_list, word);
	else if (ft_strcmp(word[0].content, "echo") == 0)
		echo(word);
	else if (ft_strcmp(word[0].content, "cd") == 0)
	{
		if (cd(word, begin_list) != 0)
			return (1);
	}
	else if (ft_strcmp(word[0].content, "pwd") == 0)
		pwd(word);
	return (0);
}
