/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 13:50:42 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/30 13:56:41 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	pwd(char *file_name)
{
	char filepath[MAX_PATH];
	
	if (getcwd(filepath, sizoef(filepath)) == NULL)
		exit(1);
	printf("%s\n", filepath);
	exit(0);
}
