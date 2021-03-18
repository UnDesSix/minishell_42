/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:06:29 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/15 13:47:13 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	update_pwds(t_list *begin_list)
{
	t_list	*tmp_list;
	char	*old_pwd;
	char	pwd[512];

	tmp_list = begin_list;
	getcwd(pwd, 512);
	while (tmp_list)
	{
		if (ft_strcmp((((t_var *)(tmp_list->data))->name), "PWD") == 0)
			old_pwd = ft_strdup((((t_var *)(tmp_list->data))->content));
		tmp_list = tmp_list->next;
	}
	tmp_list = begin_list;
	while (tmp_list)
	{
		if (ft_strcmp((((t_var *)(tmp_list->data))->name), "OLD_PWD") == 0)
			(((t_var *)(tmp_list->data))->content) = old_pwd;
		if (ft_strcmp((((t_var *)(tmp_list->data))->name), "PWD") == 0)
			(((t_var *)(tmp_list->data))->content) = pwd;
		tmp_list = tmp_list->next;
	}
	return (0);
}

int update_env(t_list *begin_list, char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0)
		update_pwds(begin_list);
	return (0);
}
