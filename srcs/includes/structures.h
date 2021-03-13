/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:42:02 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/11 20:11:08 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "header.h"

typedef struct  s_node
{
    struct s_node   *right;
    struct s_node   *left;
    int             type;
    char            *file_name;
    int             fd;
    int             pfd[2];
    int             redi_type;
    char            *cmd;
    char            **args;
}               t_node;

typedef struct  s_saver
{
    t_list  *envp_list;
    int     *past_pfd;
    int     *current_pfd;
}               t_saver;

typedef struct	s_env_str
{
	char	*var;
	char	*before_var;
	char	*after_var;
	int		quote;
}				t_env_str;

#endif
