/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 19:17:47 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/13 15:40:18 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

char	*replace_var(char *str, t_list *begin_list)
{
	char	*var;
	int		i;
	t_list	*tmp_list;

	i = 1;
	tmp_list = begin_list;
	var = NULL;
	while (tmp_list)
	{
		if (ft_strcmp(&str[1], ((t_var *)(tmp_list->data))->name) == 0)
		{
			var = ft_strdup(((t_var *)(tmp_list->data))->content);
			break ;
		}
		tmp_list = tmp_list->next;
	}
	if (!var)
		var = ft_strdup("");
	return (var);
}

int	get_exp_var(char *tmp_line, int tmp_i, t_env_str *env, t_list *begin_list)
{
	char	*tmp_var;

	tmp_var = ft_strdup(&tmp_line[tmp_i]);
	free(env->var);
	env->var = replace_var(tmp_var, begin_list);
	free(tmp_var);
	return (0);
}

char	*recreate_line(char *tmp_line, int i, t_env_str *env, char *line)
{
	tmp_line[i] = '\0';
	free(env->before_var);
	env->before_var = ft_strjoin(tmp_line, env->var);
	free(line);
	line = ft_strjoin(env->before_var, env->after_var);
	free_exp_var(env, tmp_line);
	return (line);
}

void	get_after_var(char *line, int i, t_env_str *env)
{
	if (line[i] >= '0' && line[i] <= '9')
	{
		i++;
		free(env->after_var);
		env->after_var = ft_strdup(&line[i]);
	}
	else if (!ft_isalpha(line[i]) && line[i] != '_')
	{
		free(env->after_var);
		env->after_var = ft_strdup(&line[i]);
	}
}

char	*manage_tild(char *line, t_env_str *env, int *i)
{
	char	*tmp_line;
	int		tmp_i;
	char	*tmp_var;

	if (*i > 0)
		if (line[*i - 1] != ' ')
			return (line);
	init_exp_var(env, &tmp_line, line);
	tmp_line[*i] = '\0';
	free(env->var);
	env->var = ft_strdup("$HOME");
	get_after_var(line, *i + 1, env);
	free(env->before_var);
	env->before_var = ft_strjoin(tmp_line, env->var);
	free(line);
	line = ft_strjoin(env->before_var, env->after_var);
	free_exp_var(env, tmp_line);
	*i = -1;
	env->quote = 0;
	return (line);
}

char	*manage_dollar(char *line, t_env_str *env, int *i, t_list *begin_list)
{
	char	*tmp_line;
	int		tmp_i;
	char	*tmp_var;

	init_exp_var(env, &tmp_line, line);
	tmp_i = *i;
	*i = go_to_end_var(line, *i, env->quote);
	tmp_line[*i] = '\0';
	get_exp_var(tmp_line, tmp_i, env, begin_list);
	get_after_var(line, *i, env);
	line = recreate_line(tmp_line, tmp_i, env, line);
	*i = -1;
	env->quote = 0;
	return (line);
}

char	*expansion(char *line, t_list *begin_list)
{
	int			i;
	t_env_str	env;
	char		*tmp_line;
	int			tmp_i;
	char		*tmp_var;

	i = 0;
	env.quote = 0;
	while (line[i])
	{
		if (line[i] == '\\')
			i++;
		else if (line[i] == '~'
			&& (line[i + 1] == '/' || line[i + 1] == ' ' || line[i + 1] == '\0')
			&& env.quote != 1)
			line = manage_tild(line, &env, &i);
		else if (line[i] == '$' && line[i + 1] != ' '
			&& line[i + 1] && env.quote != 1)
			line = manage_dollar(line, &env, &i, begin_list);
		else
			set_exp_quote(line[i], &env);
		i++;
	}
	return (line);
}
