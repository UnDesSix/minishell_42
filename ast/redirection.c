/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:17:39 by mlarboul          #+#    #+#             */
/*   Updated: 2021/03/21 15:22:50 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		ft_simple_right(t_node *node, t_saver *saver)
{
	int fd;

	fd = open(node->file_name, O_RDWR | O_TRUNC | O_CREAT, 0664);
	if (fd < 0)
	{
		printf("Something wrong happened. Use ERRNO\n");
		return (-1);
	}
	node->redi_right_fd = fd;
	saver->redi_right = TRUE;
	saver->redi_right_fd = fd;
	return (0);
}

int		ft_double_right(t_node *node, t_saver *saver)
{
	int		fd;
	int		read_bytes;
	char	buffer[4096];

	fd = open(node->file_name, O_RDWR | O_CREAT, 0664);
	if (fd < 0)
	{
		printf("Something wrong happened while openning. Use ERRNO\n");
		return (-1);
	}
	read_bytes = read(fd, buffer, 4096);
	while (read_bytes != 0)
	{
		if (read_bytes < 0)
		{
			printf("Something wrong happened while reading. Use ERRNO\n");
			return (-1);
		}
		read_bytes = read(fd, buffer, 4096);
	}
	node->redi_right_fd = fd;
	saver->redi_right = TRUE;
	saver->redi_right_fd = fd;
	return (0);
}

int		ft_simple_left(t_node *node, t_saver *saver)
{
	int fd;

	fd = open(node->file_name, O_RDWR);
	if (fd < 0)
	{
		printf("Something wrong happened. Use ERRNO\n");
		return (-1);
	}
	node->redi_left_fd = fd;
	saver->redi_left = TRUE;
	saver->redi_left_fd = fd;
	return (0);
}

int		manage_redi(t_node *node, t_saver *saver)
{
	if (node->redi_type == SIMPLE_R)
		ft_simple_right(node, saver);
	else if (node->redi_type == DOUBLE_R)
		ft_double_right(node, saver);
	else if (node->redi_type == SIMPLE_L)
		ft_simple_left(node, saver);
	else
		return (-1);
	return (0);
}
