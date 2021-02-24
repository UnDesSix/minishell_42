#include "ft_list.h"

char	*extract_var_name(char *str)
{
	int		i;
	int		len;
	char	*name;

	i = 0;
	while (str[i] != '=')
		i++;
	len = i;
	name = malloc(sizeof(char) * (len + 1));
	if (!name)
		return (NULL);
	i = 0;
	while (i < len)
	{
		name[i] = str[i];
		i++;
	}
	name[i] = '\0';
//	printf("name root : %s\n", name);
	return (name);
}

char	*extract_var_content(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*content;

	i = 0;
	while (str[i] != '=')
		i++;
	i++;
	len = ft_strlen(str) - i;
	content = malloc(sizeof(char) * (len + 1));
	if (!content)
		return (NULL);
	j = 0;
	while (str[i])
	{
		content[j++] = str[i];
		i++;
	}
	content[j] = '\0';
	return (content);
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_var	*var;
	char	*tmp;
	t_list	*elem;

	i = 0;
	elem = NULL;
	if (!strs)
		return (0);
	while (i < size)
	{
		tmp = ft_strdup(strs[i]);
		var = malloc(sizeof(t_var));
		var->name = extract_var_name(tmp);
		var->content = extract_var_content(tmp);
		var->is_define = 1;
		free(tmp);
		ft_list_push_back(&elem, var);
		i++;
	}
	return (elem);
}
