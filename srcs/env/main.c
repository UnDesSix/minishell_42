#include "ft_list.h"

/*
**	The function creat_list_with_envp converts envp (char **) into a
**	chained list. The function takes one parameter : envp.
**	It returns a pointer to the begenning of the list if everything went well.
**	Otherwise, it returns a NULL pointer (if malloc failed for instance).
*/
t_list	*create_list_with_envp(char **envp)
{
	t_list	*begin_list;
	int		env_size;
	
	env_size = 0;
	while (envp[env_size])
		env_size++;
	begin_list = ft_list_push_strs(env_size, envp);
	if (!begin_list)
		return (NULL);
	return (begin_list);
}

/*
**	The function env_builtin displays the environment.
**	The function takes two parameters, beginning of the list and argv.
**	It should be called alone without any arguments. If there are argument
**	it returns error 1 and display a error message.
**	Otherwise, it displays the list of environemental variables, with the last
**	variables at the end of the list and returns 0.
*/
int		env_builtin(t_list *begin_list, char **argv)
{
	t_list	*tmp;

	tmp = begin_list;
	if (!argv[2])
	{
		while (tmp)
		{
			printf("%s\n", tmp->data);										//USE FD_PUTSTR
			tmp = tmp->next;
		}
		return (0);
	}
	printf("env: env should be used without option or argument\n");			//USE FD_PUTSTR
	return (1);
}

/*
**	The function unset_builtin
**	The function takes two parameters, the address of the address of the beginning of list and argv.
**	It should be called alone with at least one arguments. If there are argument
**	it returns error 1 and display a error message.
**	Otherwise, it displays the list of environemental variables, with the last
**	variables at the end of the list and returns 0.
*/
int		unset_builtin(t_list **begin_list, char **argv)
{
	t_list	*tmp;
	int		i;
	char	*str;

	i = 2;
	while (argv[i])
	{
		if (!var_syntax_is_ok(argv[i]))
		{
			printf("unset: %s: invalid parameter name\n", argv[i]);	//USE FD_PUTSTR
			return (1);
		}
		str = ft_strjoin(argv[i], "=");
		ft_list_remove_if(begin_list, str, ft_strncmp, ft_strlen(str));
		free(str);
		i++;
	}
	/*
	** Only to check if everything is OK
	**	while (*begin_list)
	**	{
	**		printf("%s\n", (*begin_list)->data);
	**		*begin_list = (*begin_list)->next;
	**	}
	*/
	return (0);
}

int		main(int argc, char **argv, char **envp)
{
	t_list	*begin_list;
	t_list	*tmp;

	begin_list = create_list_with_envp(envp);
	if (ft_strcmp(argv[1], "env") == 0)
		env_builtin(begin_list, argv);
	else if (ft_strcmp(argv[1], "unset") == 0)
		unset_builtin(&begin_list, argv);
	else if (ft_strcmp(argv[1], "export") == 0 && !argv[2])
	{
		ft_list_sort(&begin_list, ft_strcmp);
		ft_list_foreach(begin_list, ft_strjoin);
		tmp = begin_list;
		while (tmp)
		{
			printf("%s\n", tmp->data);
			tmp = tmp->next;
		}
		ft_list_clear_data(begin_list, free);
		return (0);
	}
	ft_list_clear_data(begin_list, free);
	return (0);
}
