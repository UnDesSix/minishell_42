/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:26:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/02 12:08:30 by calide-n         ###   ########.fr       */
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

	// FREE
	while (block[index].stop)
	{
		free(block[index].word);
		index++;
	}
	free(block);
	return (0);
}
