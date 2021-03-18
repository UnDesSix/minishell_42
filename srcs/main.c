/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:26:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/18 10:58:30 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"
#define COUNT 5

void	ft_free_words(t_word *word)
{
	int	x;

	x = 0;
	while (word[x].content)
	{
//		print_word(word[x]);
		free(word[x].content);
		x++;
	}
	ft_putstr("\n");
	free(word);
}

int	ft_manage_line(char *orline, t_list *begin_list)
{
	t_word	*word;
	t_node *root;
	t_saver *saver;
	t_ast_var	ast_var;
	char	*tmp;
	char	*line;

	line = expansion(orline, begin_list);
	word = ft_lexer(line);
	free(line);
	if (!word)
		return (0);
	word = sort_words(word);
	if (!word)
		return (0);
	if (word[0].content)
	{
		char *tab[] = {word[0].content, word[1].content, NULL};
		if (ft_strcmp(word[0].content, "exit") == 0)
		{
			ft_free_words(word);
			return (0);
		}
		if (ft_strcmp(word[0].content, "cd") == 0)
			if (cd(word, begin_list) < 0)
				return (1);
		if (ft_strcmp(word[0].content, "echo") == 0)
			if (echo(word) < 0)
				return (1);
		if (ft_strcmp(word[0].content, "pwd") == 0)
			if (pwd(word) < 0)
				return (1);
	}
	root = (t_node *)malloc(sizeof(t_node));
	ast_var.index = 0;
	ast_var.i = 0;
	ast(word, ast_var, root, begin_list);
	if (check_ast(root) == -1)
	{
		ft_free_words(word);
		return (1);
	}
	print2DUtil(root, 0);
	ft_free_words(word);
	ft_free_ast(root);
	free(saver);
	return (1);
}

void sig_handler(int ok){

	//Return type of the handler function should be void
	printf("Inside handler function\n");
	return ;
}

int	divide_lines(char *line, t_list *begin_list)
{
	int	i;
	int	tmp_i;
	int	begin;
	char	stop;
	char	*lol = line;

	i = 0;
	begin = 0;
	stop = ' ';
	while (lol[i])
	{
		if (lol[i] == '\\')
			i++;
		else if (lol[i] == '"' && stop == ' ')
			stop = lol[i];
		else if (lol[i] == '\'' && stop == ' ')
			stop = lol[i];
		else if ((lol[i] == '"' || lol[i] == ' ') && stop == lol[i])
			stop = ' ';
		else if (lol[i] == ';' && stop == ' ')
		{
			if (lol[i + 1] == ';')
			{
				printf("msh: syntax error near unexpected token `;;'\n");
				return (1);
			}
			tmp_i = i;
			while (lol[tmp_i] == ' ')
				tmp_i++;
			if (lol[tmp_i] == '\0')
				break ;
			lol[i] = '\0';
			if (ft_manage_line(&line[begin], begin_list) == 0)
				return (0);
			begin = i + 1;
		}
		i++;
	}
	i--;
	while (lol[i] == ' ')
		i--;
	if (begin < i)
		if (ft_manage_line(&line[begin], begin_list) == 0)
			return (0);
	return (1);
}


int	get_input(t_list *begin_list)
{
	char	*line;
	int		ret;

	ret = 0;
	line = NULL;
	ft_putstr_fd("➜ msh ", 1);
	signal(SIGINT,sig_handler);
	while (42)
	{
		ret = get_next_line(0, &line);
		if (line)
		{
			if (ret == 0)
				break ;
			ret = divide_lines(line, begin_list);
			if (ret == 0)
				break;
			free(line);
		}
		ft_putstr_fd("➜ msh ", 1);
	}
	free(line);
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	t_list	*begin_list;

	begin_list = tabs_to_list(envp);
	get_input(begin_list);
	ft_list_clear(begin_list, free_var);
	return (0);
}
