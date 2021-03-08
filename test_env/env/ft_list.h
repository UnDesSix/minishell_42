/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 20:19:11 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/03 15:04:45 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

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

// FUNCTION IN LIB
char	*ft_strdup(const char *str);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strcmp(char const *s1, char const *s2);

// FUNCTION PROBABLY IN LIB
t_list	*ft_create_elem(void *data);
void	ft_list_push_back(t_list **begin_list, void *data);
void	ft_list_remove_if(t_list **begin_list, void *data_ref,
							int (*cmp)(), void (*free_fct)(void *));
void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());


// FUNCTION I CREATED
t_list	*ft_list_push_strs(int size, char **strs);
char	*extract_var_content(char *str);
char	*extract_var_name(char *str);
t_bool	var_syntax_is_ok(char *str, char *builtin);
int	create_var(t_list **begin_list, char *name, char *content, int status);
void	free_var(void *var);
void	free_tabs(char **tabs);
char	**list_to_tabs(t_list *begin_list, int type);
void	ft_sort_string_tab(char **tabs);
void	print_tabs(char **tabs);
void	ft_list_sort(t_list **begin_list, int (*cmp)());
void	ft_list_duplicate(t_list **new_list, t_list *begin_list);
int		export_builtin(t_list *begin_list, t_block block);
int		export_variable(t_block *block, t_list **begin_list);

// FUCNTION OK
// check_syntax.c (TODO : deleter ft_isalpha et ft_isalphanum)
t_bool	var_is_well_syntaxed(char *str, char *builtin);



#endif
