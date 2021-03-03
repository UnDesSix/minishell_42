/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:26:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/03 20:03:13 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int main(int argc, char **argv, char **envp)
{
	char	*line = argv[1];
	t_block	*block;
	int index;
	int windex = 0;

	index = 0;
	block = ft_get_blocks(line);
	sub_main(block[0], envp);
	// FREE
	while (block[index].stop)
	{
		for (int i = 0; block[index].word[i].content; i++)
			free(block[index].word[i].content);
		free(block[index].word);
		index++;
	}
	free(block);
	return (0);
}
