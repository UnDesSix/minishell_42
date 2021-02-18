/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:13:11 by calide-n          #+#    #+#             */
/*   Updated: 2021/02/18 20:15:55 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	get_next_line(int fd, char **line);

int main(void)
{
	int ret;
	char *line;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		printf("[%d] %s\n", ret, line);
		free(line);
	}
	printf("[%d] %s\n", ret, line);
	free(line);
	return (0);
}
