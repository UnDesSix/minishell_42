/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:42:02 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/18 10:57:06 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "header.h"

// KEEP THIS STRUC
typedef struct  s_node
{
	struct s_node   *right;
	struct s_node   *left;
	pid_t			child_pid;
	int				type;
	int				arg_id;
	char			*file_name;
	int				fd;
	int				*pfd;
	int				redi_type;
	int				pfd_input;
	int				pfd_output;
	char			*cmd;
	char			**args;
	char			**envp;
}               t_node;

// KEEP THIS STRUC
typedef struct  s_saver
{
	t_list  *envp_list;
	int		arg_nb;
	int		redi_on;
	int		*past_pfd;
	int		*curr_pfd;
}               t_saver;

typedef struct	s_env_str
{
	char	*var;
	char	*before_var;
	char	*after_var;
	int		quote;
}				t_env_str;

typedef struct	s_ast_var
{
	int	i;
	int	index;
}				t_ast_var;

#endif
