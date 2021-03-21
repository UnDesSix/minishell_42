/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:15:26 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/21 18:41:24 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

char	*ft_check_if_binary(char **paths, char *str)
{
	int			i;
	char		*tmp;
	struct stat	stats;

	i = 0;
	while (paths[i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(tmp, "/");
		free(tmp);
		tmp = ft_strjoin(paths[i], str);
		if (stat(tmp, &stats) == 0)
			return (tmp);
		free(tmp);
		i++;
	}
	tmp = ft_strdup(str);
	return (tmp);
}

int		ft_is_builtin(char *arg)
{
	return (ft_strcmp(arg, "echo") == 0 || ft_strcmp(arg, "cd") == 0
		|| ft_strcmp(arg, "pwd") == 0 || ft_strcmp(arg, "export") == 0
		|| ft_strcmp(arg, "unset") == 0 || ft_strcmp(arg, "env") == 0);
}

char	**ft_get_paths(t_list *begin_list)
{
	t_list	*tmp_list;
	char	*path;
	char	**paths;

	tmp_list = begin_list;
	while (tmp_list)
	{
		if (ft_strcmp((((t_var *)(tmp_list->data))->name), "PATH") == 0)
			break ;
		tmp_list = tmp_list->next;
	}
	path = ft_strdup((((t_var *)(tmp_list->data))->content));
	if (!path)
		return (NULL);
	paths = ft_split(path, ':');
	free(path);
	return (paths);
}

void	free_paths(char **paths)
{
	int	w;

	w = 0;
	while (paths[w])
	{
		free(paths[w]);
		w++;
	}
	free(paths);
}

char	*ft_check_cmd(char *str, t_list *begin_list)
{
	char	**paths;
	int		ret;
	char	*tmp;
	char	*dst;

	ret = 0;
	dst = NULL;
	paths = ft_get_paths(begin_list);
	if (!paths)
		return (NULL);
	if (str != NULL)
	{
		if (!ft_is_builtin(str) && str[0] != '/')
		{
			tmp = ft_strdup(str);
			dst = ft_check_if_binary(paths, tmp);
			free(tmp);
		}
		else
			dst = ft_strdup(str);
	}
	free_paths(paths);
	return (dst);
}
