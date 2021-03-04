/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:31:01 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/04 21:20:41 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define CMD 0
# define SPEOP 1
# define ARG 2
# define TRUE 1
# define FALSE 0
# define SPEOP_LST "=>|<;"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libsh/libsh.h"
# include <signal.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>


typedef struct s_input
{
	char	*command;
	char	**args;
	int		fd;
}				t_input;

typedef struct s_word
{
	char	*content;
	int		sep;
	int		space;
	int		type;
	int		builtin;
}				t_word;

typedef struct s_block
{
	t_word	*word;
	int		stop;
}				t_block;

#include "env.h"

int		get_next_line(int fd, char **line);
int		get_next_word(char *str, t_word *word, int reset);
int		get_nb_word(char *str, int reset);
int		ft_check_next_quote(char *str, int i, char c);
int		ft_count_quote(char *str, int *i, char *stop);
int		ft_count_special_operator(char *str, int *i, char stop);
int		ft_is_special_operator(char c);
t_word	*ft_lexer(char *line);
t_input	*ft_selector(char **tabs, int *nb_blocks);
int		pwd(void);
int		echo(t_input input);
int		cd(t_input input);
int		ft_redirections(t_input *input);
int		ft_identify_word(t_word *word);
#endif
