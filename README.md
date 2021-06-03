### Description
May it be a file, stdin, or even later a network connection, I will always need a way to read content line by line

***
### Function

| Function name  | minishell |
| ------------- | ------------- |
| External functs.  | printf, malloc, free, write, open, read, close, fork, wait, waitpid, wait3, wait4, signal, kill, exit, getcwd, chdir, stat, lstat, fstat, execve, dup, dup2, pipe, opendir, readdir, closedir, strerror, errno, isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs  |


***
### Mandatory part
- Not use more than one global variable
- Show a prompt when waiting for a new command
- Search and launch the right executable (based on the PATH variable or by usingrelative or absolute path) like in bash
- It must implement the builtins like in bash:
    - echo with option ’-n’
    - cd with only a relative or absolute path-
    - pwd without any options
    - export without any options
    - unset without any options
    - env without any options and any arguments
    - exit without any options
- `;` in the command should separate commands like in bash
- `'` and `"` should work like in bash except for multiline commands
- Redirections `<`, `>` and `>>` should work like in bash except for file descriptor aggregation
- Pipes `|` should work like in bash except for multiline commands
- Environment variables ($followed by characters) should work like in bash
- `$?` should work like in bash
- `ctrl-C`,`ctrl-D` and `ctrl-\` should have the same result as in bash

***
### Ressources
- [Making your own Linux Shell in C](https://www.geeksforgeeks.org/making-linux-shell-c/)
- [[C] Programmation systeme: execve(), fork() et pipe()](https://n-pn.fr/t/2318-c--programmation-systeme-execve-fork-et-pipe)
- [Write a shell in C](https://danishpraka.sh/2018/01/15/write-a-shell.html)
- [Get the current directory in C program](https://stackoverflow.com/questions/298510/how-to-get-the-current-directory-in-a-c-program)
- [The Bourne-Again Shell](https://www.aosabook.org/en/bash.html)
- [The Bash Parser](https://mywiki.wooledge.org/BashParser)
