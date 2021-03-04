/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:15:26 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/04 11:48:31 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int ft_check_if_binary(char **paths, t_word *word)
{   
	int i;
	char *tmp;
	struct stat stats;

	i = 0;
	while (paths[i])
	{   
		tmp = paths[i];
		paths[i] = ft_strjoin(tmp, "/");
		free(tmp);
		tmp = ft_strjoin(paths[i], word->content);
		if (stat(tmp, &stats) == 0)
		{   
			if (word->content)
				free(word->content);
			word->content = tmp;
			return (1);
		}
		free(tmp);
		i++;
	}
	return (0);
}

int ft_is_builtin(char *arg)
{   
	return (ft_strcmp(arg, "echo") == 0 || ft_strcmp(arg, "ls") == 0
			|| ft_strcmp(arg, "pwd") == 0 || ft_strcmp(arg, "export") == 0
			|| ft_strcmp(arg, "unset") == 0 || ft_strcmp(arg, "env") == 0);
}

int ft_check_cmd(t_word *word)
{   
	char    *path;
	char    **paths;
	int     w;
	int		ret;

	w = 0;
	ret = 0;
	path = ft_strdup("/usr/local/opt/ruby/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin");
	paths = ft_split(path, ':');
	if (word->content)
	{   
		if (ft_is_builtin(word->content))
		{   
			word->type = CMD;
			word->builtin = TRUE;
			ret = 1;
		}
		else if (word->content[0] != '/')
		{
			ft_check_if_binary(paths, word);
			ret = 1;
		}
	}
	while (paths[w])
	{   
		free(paths[w]);
		w++;
	}
	free(paths);
	free(path);
	return (ret);
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
	if (ft_check_cmd(word))
		return (1);
	//ft_check_speop(word->content);
	return (0);
}
