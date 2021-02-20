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

t_list	*ft_create_elem(void *data);
void	ft_list_push_back(t_list **begin_list, void *data);
t_list	*ft_list_push_strs(int size, char **strs);
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), int len);
void	ft_list_sort(t_list **begin_list, int (*cmp)());
int		ft_strcmp(char const *s1, char const *s2);
char	*ft_strjoin(char *s1, char *s2);
void	ft_list_foreach(t_list *begin_list, char *(*f)(char *, char *));
void	ft_list_clear_data(t_list *begin_list, void (*f)(void *));
int		ft_strncmp(char const *s1, char const *s2, size_t n);
int		var_syntax_is_ok(char *str);
char	*ft_strdup(const char *str);
int		ft_strlen(const char *str);

#endif
