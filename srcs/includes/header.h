/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:31:01 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/13 13:20:00 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define CMD 0
# define SPEOP 1
# define ARG 2
# define PIPE 3
# define REDI 4
# define FD 5
# define TRUE 1
# define FALSE 0
# define SIMPLE_R 6
# define DOUBLE_R 7
# define SIMPLE_L 8
# define SPEOP_LST "=>|<;"
# define DQ_BS_SPECHAR "$`\\"
# define STOP_ENV_VAR_CHAR " \"'$|/	~;?*[#=%!-"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libsh/libsh.h"
# include <signal.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>

typedef struct s_lexer
{
	int		i;
	char	*line;
	int		x;
	int		begin;
}				t_lexer;

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
#include "structures.h"

/*
 *	AST CREATIOM
 */

int		ast(t_word *word, int i, t_node *node);
void	ft_free_ast(t_node *node);
void    fill_node(t_node *node, int type, char *cmd, char *file_name);
char    **ft_token_to_tab(t_word *word);
void    set_node(t_node *node);
int 	ft_while_pipe(t_word *word, int i, t_node *node, int index);
int 	ft_while_redi(t_word *word, int i, t_node *node, int index);
int		ft_while_args(t_word *word, int i, t_node *node, int index);
int		ft_manage_branch(t_word *word, t_node **node, int index);

/*
 *	EXPANSION
 */

char	*expansion(char *line, t_list *begin_list);
void	init_exp_var(t_env_str *env, char **tmp_line, char *line);
void	free_exp_var(t_env_str *env, char *tmp_line);
void	set_exp_quote(char c, t_env_str *env);
int		go_to_end_var(char *line, int i, int quote);

int		get_next_line(int fd, char **line);
int		get_next_word(char *str, t_word *word, int reset);
int		get_nb_word(char *str);
int		ft_is_special_operator(char c);
void	set_quote(int *b, int *quotes, int value, char *str);
void	ft_init_word(t_word *word);
char	*ft_strdup_with_limits(char *str, int b, int e);
void	set_word_sep(t_word *word, char c);
char	*ft_check_cmd(char *str);

void	btree_prefix_exec(t_node *root, t_saver *saver, int side);

t_word	*ft_lexer(char *line);
t_input	*ft_selector(char **tabs, int *nb_blocks);
int		pwd(void);
int		echo(t_input input);
int		cd(t_input input);
int		ft_redirections(t_input *input);
int		ft_identify_word(t_word *word);
char    **ft_split(char const *s, char c);
#endif
