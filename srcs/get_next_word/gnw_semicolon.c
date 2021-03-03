/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnw_semicolon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:56:02 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/02 13:47:56 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int ft_manage_semicolon(char c, t_word *word, int *i)
{
    if (c == ';')
    {
        word->content = ft_strdup(";");
        word->sep = 0;
        *i += 1;
        return (1);
    }
    if (c == '|')
    {
        word->content = ft_strdup("|");
        word->sep = 0;
        *i += 1;
        return (1);
    }
    return (0);
}
