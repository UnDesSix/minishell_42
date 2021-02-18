/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:00:43 by calide-n          #+#    #+#             */
/*   Updated: 2021/02/18 20:07:26 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int ft_redirections(t_input *input)
{
	int i = 0;

	input->fd = 1;
	while (input->args[i])
	{
		if (input->args[i + 1] && strcmp(input->args[i], ">") == 0)
		{
			input->fd = open(input->args[i + 1], O_RDWR | O_CREAT | O_TRUNC, 777);
			input->args[i] = NULL;
			input->args[i + 1] = NULL;
		}
		if (input->args[i + 1] && strcmp(input->args[i], ">>") == 0)
		{
			input->fd = open(input->args[i + 1], O_RDWR | O_CREAT | O_APPEND, 777);
			input->args[i] = NULL;
			input->args[i + 1] = NULL;
		}
		i++;
	}
	return (0);
}
