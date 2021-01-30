/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:42:45 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/30 14:00:18 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define RED "\033[0;31m"
# define RESET "\e[0m"
# define TRUE 1
# define FALSE 0 

# include "structures.h"
# include "functions.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

void    echo(char *str, int flag, int fd);
void	pwd(char *file_name);

#endif
