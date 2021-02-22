#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

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

t_list	*ft_create_elem(void *data);
void	ft_list_push_back(t_list **begin_list, void *data);
t_list	*ft_list_push_strs(int size, char **strs);
void	ft_list_remove_if(t_list **begin_list, void *data_ref,
							int (*cmp)(), void (*free_fct)(void *));
int		ft_strcmp(char const *s1, char const *s2);
void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
int		var_syntax_is_ok(char *str);
void	free_var(void *var);

char	*ft_strdup(const char *str);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif
