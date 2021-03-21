/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:19:12 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/20 14:37:24 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	pwd(t_word *word)
{
	char	pwd[4096];

	errno = 0;
	getcwd(pwd, sizeof(pwd));
	if (errno != 0)
		printf("msh: %s\n", strerror(errno));
	ft_putstr(pwd);
	ft_putstr("\n");
	return (0);
}
