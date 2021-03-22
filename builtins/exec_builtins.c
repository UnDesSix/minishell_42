/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:58:49 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/21 21:22:52 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	exec_builtins(t_word *word, t_list *begin_list)
{
	if (ft_strcmp(word[0].content, "env") == 0)
		return (env_builtin(begin_list, word));
	else if (ft_strcmp(word[0].content, "unset") == 0)
		return (unset_builtin(&begin_list, word));
	else if (ft_strcmp(word[0].content, "export") == 0)
		return (export_builtin(begin_list, word));
	else if (ft_strcmp(word[0].content, "echo") == 0)
		return (echo(word));
	else if (ft_strcmp(word[0].content, "cd") == 0)
		return (cd(word, begin_list));
	else if (ft_strcmp(word[0].content, "pwd") == 0)
		return (pwd());
	else if (ft_strcmp(word[0].content, "exit") == 0)
		return (ft_exit(word));
	return (0);
}
