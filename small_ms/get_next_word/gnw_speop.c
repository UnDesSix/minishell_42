/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnw_speop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:56:33 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/01 12:56:53 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int ft_manage_speop(char *str, t_word *word, int *i) 
{
    if (str[*i] == '=' || str[*i] == '|' || str[*i] == '<' || str[*i] == '>')
    {   
        if (str[*i + 1] == '>')
        {   
            word->content = ft_strdup(">>");
            *i += 1;
        }   
        else
        {   
            word->content = (char *)malloc(sizeof(char) * 2); 
            if (!word->content)
                return (-1);
            word->content[0] = str[*i];
            word->content[1] = '\0';
        }
        *i += 1;
        if (str[*i] == ' ')
            word->space = 1;
        return (1);
    }
    return (0);
}

