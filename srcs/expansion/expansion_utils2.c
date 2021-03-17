/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:22:12 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/17 11:25:54 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

char	*add_quote_word(char *str)
{
	int		len;
	char	*dst;
	int		i;

	i = 0;
	len = ft_strlen(str);
	dst = (char *)malloc(sizeof(char) * (len + 3));
	dst[0] = '"';
	while (str[i])
	{
		dst[i + 1] = str[i];
		i++;
	}
	dst[i + 1] = '"';
	dst[i + 2] = '\0';
	return (dst);
}

char	*add_quotes(char *str)
{
	char	**split;
	int		i;
	char	*tmp;
	char	*dst;

	i = 0;
	split = ft_split(str, ' ');
	dst = ft_strdup("");
	while (split[i])
	{
		tmp = add_quote_word(split[i]);
		free(split[i]);
		split[i] = ft_strdup(tmp);
		if (split[i + 1])
			split[i] = ft_strjoin(split[i], " ");
		free(tmp);
		tmp = ft_strjoin(dst, split[i]);
		free(dst);
		dst = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	return (dst);
}

char	*replace_var(char *str, t_list *begin_list)
{
	char	*var;
	int		i;
	t_list	*tmp_list;
	char	*var_with_quotes;

	i = 1;
	tmp_list = begin_list;
	var = NULL;
	while (tmp_list)
	{
		if (ft_strcmp(&str[1], ((t_var *)(tmp_list->data))->name) == 0)
		{
			var_with_quotes = add_quotes(((t_var *)(tmp_list->data))->content);
			var = ft_strdup(var_with_quotes);
			free(var_with_quotes);
			break ;
		}
		tmp_list = tmp_list->next;
	}
	if (!var)
		var = ft_strdup("");
	return (var);
}

int		get_exp_var(char *tmp_line, int tmp_i,
		t_env_str *env, t_list *begin_list)
{
	char	*tmp_var;

	tmp_var = ft_strdup(&tmp_line[tmp_i]);
	free(env->var);
	env->var = replace_var(tmp_var, begin_list);
	free(tmp_var);
	return (0);
}
