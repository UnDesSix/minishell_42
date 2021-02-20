/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:31:01 by calide-n          #+#    #+#             */
/*   Updated: 2021/02/19 11:51:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libsh/libsh.h"
# include <signal.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct	s_input
{
	char 	*command;
	char 	**args;
	int		fd;
}				t_input;

int				get_next_line(int fd, char **line);
char			**ft_split(char *s, char c);
t_input			ft_selector(char **tabs);
int				ft_execute(t_input input, char **envp);
int				pwd(void);
int				echo(t_input input);
int				cd(t_input input);
int				ft_redirections(t_input * input);

#endif
