/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnw_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:57:16 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/01 12:57:45 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int ft_manage_space(char *str, int *i, t_word *word)
{
    int     j;  
    int     k;  

    j = *i; 
    k = 0;
    if (str[*i] != '\'' && str[*i] != '"')
    {   
        while (str[j] && str[j] != ' ' && str[j] != '\''
                && str[j] != '"' && str[j] != '\'' && str[j] != ';' && str[j] != '=')
            j++;
        word->content = malloc(sizeof(char) * (j + 1));
        if (!word->content)
            return (-1);
        while (str[*i] && str[*i] != ' ' && str[*i] != '\''
                && str[*i] != '"' && str[*i] != '\'' && str[*i] != ';' && str[*i] != '=')
        {   
            word->content[k] = str[*i];
            *i += 1;
            k++;
        }   
        word->content[k] = '\0';
        if (str[*i] == ' ')
        {   
            word->space = 1;
            *i += 1;
        }   
        return (1);
    }   
    return (0);
}

