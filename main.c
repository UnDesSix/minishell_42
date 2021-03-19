/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:26:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/19 17:47:42 by mlarboul         ###   ########.fr       */
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
	//	ft_putstr("\n");
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
	//printf("[%s]\n", line);
	word = ft_lexer(line);
	if (!word)
		return (1);
	word = sort_word(word);
	if (!word)
		return (1);
//	if (!ft_check_lexer(word))
//		return (1);
//	for (int z = 0; word[z].content; z++)
//		printf("[%s]", word[z].content);
//	printf("\n");
	free(line);
	if (word[0].content)
	{
		if (ft_strcmp(word[0].content, "exit") == 0)
		{
			ft_free_words(word);
			return (0);
		}
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
	ast_run(root, begin_list);
	free(g_proc.pid);
//	print2DUtil(root, 0);
	ft_free_words(word);
	ft_free_ast(root);
	return (1);
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
			if (lol[i + 1] == ';' || i == 0)
			{
				printf("msh: syntax error near unexpected token `;'\n");
				g_proc.ret = 258;
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
	//	printf("%d\n", g_proc.ret);
	return (1);
}


int	get_input(t_list *begin_list)
{
	char	*line;
	int		ret;

	ret = 0;
	line = NULL;
	ft_putstr_fd("\033[1m\033[32m➜\033[0m msh ", 1);
	signals();
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
		if (g_proc.ret == 0)
			ft_putstr_fd("\033[1m\033[32m➜\033[0m msh ", 1);
		else
			ft_putstr_fd("\033[1m\033[31m➜\033[0m msh ", 1);
	}
	free(line);
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	t_list	*begin_list;

	g_proc.ret = 0;
	begin_list = tabs_to_list(envp);
	get_input(begin_list);
	ft_list_clear(begin_list, free_var);
	return (0);
}
