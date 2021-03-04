/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 20:19:11 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/04 21:21:06 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_LIST_H
# define FT_LIST_H

#include "header.h"

#define TRUE 1
#define FALSE 0

typedef int		t_bool;

typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;

typedef struct	s_var
{
	char	*name;
	char	*content;
	int		is_define;
}				t_var;

int		export_builtin(t_list *begin_list, t_word *word);
t_bool	var_is_well_syntaxed(char *str, char *builtin);
int		create_var(t_list **begin_list, char *name, char *content, int status);
int		export_variable(t_word *word, t_list **begin_list);
void	free_tabs(char **tabs);
void	free_var(void *data);

/*
** LIST PROTOYPES
*/
t_list	*ft_create_elem(void *data);
void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
int		ft_list_duplicate(t_list **dst_list, t_list *src_list);
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
void	ft_list_foreach(t_list *begin_list, char *(*f)(char *, char *));
void	ft_list_push_back(t_list **begin_list, void *data);
t_list	*ft_list_push_strs(int size, char **strs);
void	ft_list_remove_if(t_list **begin_list, void *data_ref,
								int (*cmp)(), void (*free_fct)(void *));
void	ft_list_sort(t_list **begin_list, int (*cmp)());
char	**list_to_tabs(t_list *begin_list, int type);
void	print_tabs(char **tabs);
//int		sub_main(t_block block, char **envp);

t_list  *tabs_to_list(char **envp);
int     env_builtin(t_list *begin_list, t_word *word);
int     unset_builtin(t_list **begin_list, t_word *word);

#endif
