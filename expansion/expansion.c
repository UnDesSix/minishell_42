/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 19:17:47 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/22 18:25:59 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

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

	init_exp_var(env, &tmp_line, line);
	tmp_i = *i;
	*i = go_to_end_var(line, *i);
	tmp_line[*i] = '\0';
	get_exp_var(tmp_line, tmp_i, env, begin_list);
	get_after_var(line, *i, env);
	line = recreate_line(tmp_line, tmp_i, env, line);
	*i = -1;
	env->quote = 0;
	return (line);
}

char	*manage_exit_status(char *line, t_env_str *env, int *real_i)
{
	char	*tmp_line;
	char	*tmp;
	int		i;
	int		j;
	char	*nbr;

	i = *real_i;
	j = *real_i + 2;
	while (line[i])
		i++;
	nbr = ft_itoa(g_proc.ret);
	tmp_line = malloc(sizeof(char) * (ft_strlen(nbr) + i - 1));
	i = -1;
	while (nbr[++i])
		tmp_line[i] = nbr[i];
	while (line[j])
		tmp_line[i++] = line[j++];
	tmp_line[i] = '\0';
	tmp = ft_strdup(line);
	free(line);
	tmp[*real_i] = '\0';
	line = ft_strjoin(tmp, tmp_line);
	free_exit_status(tmp, nbr, tmp_line);
	(void)env;
	return (line);
}

char	*expansion(char *orline, t_list *begin_list)
{
	int			i;
	t_env_str	env;
	char		*line;

	line = ft_strdup(orline);
	i = 0;
	env.quote = 0;
	while (line[i])
	{
		set_exp_quote(line[i], &env);
		if (line[i] == '\\')
			i++;
		else if (line[i] == '~' && (line[i + 1] == '/' ||
				line[i + 1] == ' ' || line[i + 1] == '\0')
				&& env.quote != 1)
			line = manage_tild(line, &env, &i);
		else if (line[i] == '$' && line[i + 1] == '?' && env.quote != 1)
			line = manage_exit_status(line, &env, &i);
		else if (line[i] == '$' && line[i + 1] != ' ' &&
			line[i + 1] && env.quote != 1)
			line = manage_dollar(line, &env, &i, begin_list);
		i++;
	}
	return (line);
}
