/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:14:00 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/20 16:22:46 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		set_pwd(t_list *begin_list, char *pwd)
{
	t_list	*tmp_list;

	tmp_list = begin_list;
	while (tmp_list)
	{
		if (ft_strcmp((((t_var *)(tmp_list->data))->name), "PWD") == 0)
		{
			free((((t_var *)(tmp_list->data))->content));
			(((t_var *)(tmp_list->data))->content) = ft_strdup(pwd);
			break ;
		}
		tmp_list = tmp_list->next;
	}
	return (0);
}

int		set_old_pwd(t_list *begin_list)
{
	t_list	*tmp_list;
	char	*old_pwd;

	tmp_list = begin_list;
	while (tmp_list)
	{
		if (ft_strcmp((((t_var *)(tmp_list->data))->name), "PWD") == 0)
		{
			old_pwd = ft_strdup((((t_var *)(tmp_list->data))->content));
			break ;
		}
		tmp_list = tmp_list->next;
	}
	tmp_list = begin_list;
	while (tmp_list)
	{
		if (ft_strcmp((((t_var *)(tmp_list->data))->name), "OLDPWD") == 0)
		{
			free((((t_var *)(tmp_list->data))->content));
			(((t_var *)(tmp_list->data))->content) = ft_strdup(old_pwd);
			break ;
		}
		tmp_list = tmp_list->next;
	}
	if (old_pwd)
		free(old_pwd);
	return (0);
}

char	*get_goto_default_pwd(t_list *begin_list)
{
	t_list	*tmp_list;
	char	*pwd;

	tmp_list = begin_list;
	while (tmp_list)
	{
		if (ft_strcmp((((t_var *)(tmp_list->data))->name), "HOME") == 0)
			break ;
		tmp_list = tmp_list->next;
	}
	chdir((((t_var *)(tmp_list->data))->content));
	pwd = ft_strdup((((t_var *)(tmp_list->data))->content));
	if (!pwd)
		return (NULL);
	return (pwd);
}

int		cd(t_word *word, t_list *begin_list)
{
	char	*pwd;
	char	tmp_pwd[4096];

	errno = 0;
	pwd = NULL;
	set_old_pwd(begin_list);
	if (word[1].content)
	{
		if (ft_strcmp(word[1].content, "") == 0)
			chdir(".");
		else
			chdir(word[1].content);
		if (errno != 0)
		{
			printf("msh: cd: %s: %s\n", word[1].content, strerror(errno));
			g_proc.ret = 1;
			return (1);
		}
		getcwd(tmp_pwd, sizeof(tmp_pwd));
		pwd = ft_strdup(tmp_pwd);
	}
	if (!pwd)
		pwd = get_goto_default_pwd(begin_list);
	set_pwd(begin_list, pwd);
	free(pwd);
	return (0);
}
