/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:31:01 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/21 18:37:55 by calide-n         ###   ########.fr       */
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
# define DQ_BS_SPECHAR "\"$`\\"
# define STOP_ENV_VAR_CHAR " \"'$?|/	~;*[#=%!-"
# define STDOUT 0
# define STDIN 1
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libsh/libsh.h"
# include <signal.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include "structures.h"
# include <sys/errno.h>

t_process	g_proc;

/*
**	AST CREATIOM
*/

int			ast(t_word *word, t_ast_var ast_var, t_node *node,
			t_list *begin_list);
void		ft_free_ast(t_node *node);
void		fill_node(t_node *node, int type, char *cmd, char *file_name);
char		**ft_token_to_tab(t_word *word);
void		set_node(t_node *node);
int			ft_while_pipe(t_word *word, t_ast_var ast_var, t_node *node, t_list
			*begin_list);
int			ft_while_redi(t_word *word, t_ast_var ast_var, t_node *node, t_list
			*begin_list);
int			ft_while_args(t_word *word, t_ast_var ast_var, t_node *node, t_list
			*begin_list);
int			ft_manage_branch(t_word *word, t_node **node, t_ast_var ast_var,
			t_list *begin_list);
int			check_ast(t_node *ast);

/*
**	AST EXECUTION
*/
void		btree_prefix_count(t_node *node, int *count);
int			ast_run(t_node *root, t_list *begin_list);
void		btree_prefix_pipe(t_node *node, t_saver *saver);
int			btree_prefix_exec(t_node *node, t_saver *saver);
void		btree_prefix_clean(t_node *node);
int			manage_redi(t_node *node, t_saver *saver);
int			define_std_inout(t_node *node, t_saver *saver);

/*
**	EXPANSION
*/

char		*expansion(char *line, t_list *begin_list);
void		init_exp_var(t_env_str *env, char **tmp_line, char *line);
void		free_exp_var(t_env_str *env, char *tmp_line);
void		set_exp_quote(char c, t_env_str *env);
int			go_to_end_var(char *line, int i);
char		*add_quote_word(char *str);
char		*add_quotes(char *str);
char		*replace_var(char *str, t_list *begin_list);
int			get_exp_var(char *tmp_line, int tmp_i, t_env_str *env,
			t_list *begin_list);

/*
**	LEXER / PARSER
*/

int			ft_check_lexer(t_word *word);
t_word		*sort_word(t_word *word);
int			word_is_redi(char *str);
t_word		*ft_lexer(char *line);
int			get_next_line(int fd, char **line);
int			get_next_word(char *str, t_word *word, int reset);
int			get_nb_word(char *str);
int			ft_is_special_operator(char c);
void		set_quote(int *b, int *quotes, int value, char *str);
void		ft_init_word(t_word *word);
char		*ft_strdup_with_limits(char *str, int b, int e);
char		*ft_check_cmd(char *str, t_list *begin_list);
int			handle_quotes(char *line, t_lexer *lex, t_word *word);
void		incre_word(char *line, t_lexer *lex, t_word *word);
int			ft_is_builtin(char *arg);
t_word		*ft_wordup(t_word *word);
t_word		*ft_wordjoin(t_word *w1, t_word *w2);

/*
**	BUILTINS
*/

int			pwd(void);
int			echo(t_word *word);
int			cd(t_word *word, t_list *begin_list);
int			ft_exit(t_word *word);
int			exec_builtins(t_word *word, t_list *begin_list);
int			export_builtin(t_list *begin_list, t_word *word);
t_bool		var_is_well_syntaxed(char *str, char *builtin);
int			create_var(t_list **begin_list, char *name, char *content,
			int status);
int			export_variable(t_word *word, t_list **begin_list);
void		free_tabs(char **tabs);
void		free_var(void *data);

/*
** LIST PROTOYPES
*/

t_list		*ft_create_elem(void *data);
void		ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
int			ft_list_duplicate(t_list **dst_list, t_list *src_list);
t_list		*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
void		ft_list_foreach(t_list *begin_list, char *(*f)(char *, char *));
void		ft_list_push_back(t_list **begin_list, void *data);
t_list		*ft_list_push_strs(int size, char **strs);
void		ft_list_remove_if(t_list **begin_list, void *data_ref,
			int (*cmp)(), void (*free_fct)(void *));
void		ft_list_sort(t_list **begin_list, int (*cmp)());
char		**list_to_tabs(t_list *begin_list, int type);
void		print_tabs(char **tabs);
t_list		*tabs_to_list(char **envp);
int			env_builtin(t_list *begin_list, t_word *word);
int			unset_builtin(t_list **begin_list, t_word *word);

/*
**	DEBUG
*/

void		print_word(t_word word);
void		print2DUtil(t_node *root, int space);

/*
**	SIGNALS
*/

void		signals();

#endif
