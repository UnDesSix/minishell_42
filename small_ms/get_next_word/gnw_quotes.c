/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnw_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:52:42 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/02 15:38:55 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int ft_check_next_quote(char *str, int i, char c)
{   
    while (str[i] != c) 
        if (str[i++] == '\0')
            return (0);
    return (1);
}

int ft_manage_all_quotes(char *str, t_word *word, int *i)
{   
    if (str[*i] == '\'')
    {   
        if (!ft_check_next_quote(str, *i, str[*i]))
        {   
            printf("Error quote\n");
            word->content = NULL;
            return (1);
        }
        if (!ft_manage_quote(str, i, '\'', word))
            return (-1);
        word->sep = 1;
        return (1);
    }
    else if (str[*i] == '"')
    {   
        if (!ft_check_next_quote(str, *i, str[*i]))
        {   
            printf("Error quote\n");
            word->content = NULL;
            return (0);
        }
        if (!ft_manage_quote(str, i, '"', word))
            return (-1);
        word->sep = 2;
        return (1);
    }
    return (0);
}

int ft_manage_quote(char *str, int *i, char c, t_word *word)
{
    int     j;
    int     k;

    k = 0;
    *i += 1;
    j = *i;
    word->space = 0;
    while (str[j] && str[j] != c && str[j] != ';' && str[j] != '|')
        j++;
    word->content = malloc(sizeof(char) * (j + 1));
    if (!word->content)
        return (0);
    while (str[*i] && str[*i] != c && str[j] != ';' && str[j] != '|')
    {
        word->content[k] = str[*i];
        *i += 1;
        k++;
    }
    word->content[k] = '\0';
    *i += 1;
    if (str[*i] == ' ' || str[*i - 2])
        word->space = 1;
    return (1);
}
