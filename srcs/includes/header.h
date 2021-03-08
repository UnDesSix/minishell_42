/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:31:01 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/03 18:43:41 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define CMD 0
# define SPEOP 1
# define ARG 2
# define TRUE 1
# define FALSE 0
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

# include "env.h"

int		get_next_line(int fd, char **line);
int		get_next_word(char *str, int on, t_word *word);
int		get_nb_word(char *str, int on);
t_block	*ft_get_blocks(char *line);
char	**ft_split(char *s, char c);
t_input	*ft_selector(char **tabs, int *nb_blocks);
int		ft_execute(t_input *input, int nb_block);
int		pwd(void);
int		echo(t_input input);
int		ft_manage_quote(char *str, int *i, char c, t_word *word);
int		ft_manage_space(char *str, int *i, t_word *word);
int		ft_manage_speop(char *str, t_word *word, int *i);
int		ft_manage_semicolon(char c, t_word *word, int *i);
int		ft_manage_all_quotes(char *str, t_word *word, int *i);
int		ft_manage_null(char c, t_word *word);
int		cd(t_input input);
int		ft_redirections(t_input *input);
int		ft_identify_word(t_word *word);
int 	ft_execute_block(t_block block);
#endif
