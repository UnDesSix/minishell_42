/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:15:26 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/11 18:01:51 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

char *ft_check_if_binary(char **paths, char *str)
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
	//	printf("[%s] - [%s]\n", paths[i], str);
		tmp = ft_strjoin(paths[i], str);
		if (stat(tmp, &stats) == 0)
		{   
			if (str)
				free(str);
			return (tmp);
		}
		free(tmp);
		i++;
	}
	return (0);
}

int ft_is_builtin(char *arg)
{   
	return (ft_strcmp(arg, "echo") == 0 
			|| ft_strcmp(arg, "pwd") == 0 || ft_strcmp(arg, "export") == 0
			|| ft_strcmp(arg, "unset") == 0 || ft_strcmp(arg, "env") == 0);
}

char *ft_check_cmd(char *str)
{   
	char	*path;
	char	**paths;
	int		w;
	int		ret;
	char	*tmp;

	w = 0;
	ret = 0;
	path = ft_strdup("/usr/local/opt/ruby/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin");
	paths = ft_split(path, ':');
	if (str)
	{   
		if (!ft_is_builtin(str) && str[0] != '/')
		{
			tmp = str;
			str = ft_check_if_binary(paths, tmp);
		}
	}
	while (paths[w])
	{   
		free(paths[w]);
		w++;
	}
	free(paths);
	free(path);
	return (str);
}

int	ft_check_speop(char *word)
{
	return (ft_strcmp(word, "|") == 0 || ft_strcmp(word, "<") == 0
			|| ft_strcmp(word, ">") == 0 || ft_strcmp(word, ">>") == 0
			|| ft_strcmp(word, "=") == 0);
}

int	ft_identify_word(t_word *word)
{
	word->builtin = FALSE;
	word->type = ARG;
	if (ft_check_cmd(word->content))
		return (1);
	//ft_check_speop(word->content);
	return (0);
}
