/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 19:17:47 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/21 15:48:59 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

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

char	*manage_exit_status(char *line, t_env_str *env, int *real_i, t_list *begin_list)
{
//	char	*tmp_line;
//	int		i;
//	int		j;
//	char	*nbr;
//
//	i = *real_i;
//	j = *real_i;
//	while (line[i])
//		i++;
//	nbr = ft_itoa(g_proc.ret);
//	printf("[%s]\n", nbr);
//	tmp_line = malloc(sizeof(char) * (ft_strlen(nbr) + i - 1));
//	i = 0;
//	while (nbr[i])
//	{
//		tmp_line[i] = nbr[i];
//		i++;
//	}
//	while (line[j])
//		tmp_line[i++] = line[j++];
//	tmp_line[i] = '\0';
//	printf("[%s]\n", nbr);
//	*real_i = -1;
//	env->quote = 0;
	return (line);
}

char	*expansion(char *orline, t_list *begin_list)
{
	int			i;
	t_env_str	env;
	char		*tmp_line;
	int			tmp_i;
	char		*tmp_var;
	char		*line = ft_strdup(orline);

	i = 0;
	env.quote = 0;
	while (line[i])
	{
		if (line[i] == '\\')
			i++;
		else if (line[i] == '~' && (line[i + 1] == '/' ||
				line[i + 1] == ' ' || line[i + 1] == '\0')
				&& env.quote != 1)
			line = manage_tild(line, &env, &i);
		else if (line[i] == '$' && line[i + 1] == '?')
			manage_exit_status(line, &env, &i, begin_list);
		else if (line[i] == '$' && line[i + 1] != ' ' &&
			line[i + 1] && env.quote != 1)
			line = manage_dollar(line, &env, &i, begin_list);
		else
			set_exp_quote(line[i], &env);
		i++;
	}
	return (line);
}
