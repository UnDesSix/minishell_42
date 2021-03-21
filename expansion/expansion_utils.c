/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:42:45 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/21 18:37:30 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	init_exp_var(t_env_str *env, char **tmp_line, char *line)
{
	env->after_var = ft_strdup("");
	env->before_var = ft_strdup("");
	env->var = ft_strdup("");
	*tmp_line = ft_strdup(line);
}

void	free_exp_var(t_env_str *env, char *tmp_line)
{
	free(env->before_var);
	free(env->after_var);
	free(env->var);
	free(tmp_line);
}

void	set_exp_quote(char c, t_env_str *env)
{
	if (c == '\'' && env->quote == 1)
		env->quote = 0;
	else if (c == '\'' && env->quote == 0)
		env->quote = 1;
	else if (c == '"' && env->quote == 2)
		env->quote = 0;
	else if (c == '"' && env->quote == 0)
		env->quote = 2;
}

int		go_to_end_var(char *line, int i)
{
	i++;
	if (ft_isdigit(line[i]))
		return (i);
	while (ft_isalnum(line[i]) || line[i] == '_')
		i++;
	return (i);
}
