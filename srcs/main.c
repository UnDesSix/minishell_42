/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 13:36:56 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/30 13:41:59 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "../get_next_line/get_next_line.h"
#include <fcntl.h>

extern int errno;

int main(int argc, char **argv)
{
    char *line;
    char *name[] = {".", NULL};
    char *envp[] = {"some", "env", NULL};
    int status;
    pid_t pid;
    int fd = open("mshistory", O_RDWR);
	char prompt[] = "\e[32;40m minishell-1.0$";

    while (1) 
    {   
        write(1, prompt, strlen(prompt));
        if (get_next_line(0, &line) > 0)
        {   
            printf("[%s]\n", line);
            write(fd, line, strlen(line));
            write(fd, "\n", 1); 
            if (strcmp(line, "exit") == 0)
                exit(0);
            free(line);
        }   
        pid = fork();
//      write(1, "\n", 1);
        if (pid == 0)
        {   
            if (strcmp(line, "ls") == 0)
            {   
                if ((execve("/bin/ls", name, name) < 0)) 
                    (strerror(errno));
            }   
        }   
        else if (pid < 0)
        {   
            printf("Error creating child process, exiting...\n");
            exit(1);
        }   
        else
            waitpid(pid, &status, WUNTRACED);
        status = 1;

    }   
    return (0);
}
