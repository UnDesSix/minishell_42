NAME	= minishell

CC		= clang #-Wall -Werror -Wextra

RM		= rm -rf

LIBSH	= libsh/libsh.a

INCS	= -I./includes

SRCS_NAME	= main.c			\
			  get_next_line.c 	\
			  separator.c		\
			  execute.c			\
			  pwd.c				\
			  echo.c			\
			  redirections.c	\

SRCS_PATH	= ./

OBJS_PATH	= ./objs/

SRCS	= $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS	= $(SRCS:.c=.o)


%.o: %.c
	$(CC) $(INCS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBSH) $(INCS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_PATH)

fclean: clean
	$(RM) $(NAME)

re: clean all

#norme: clean 
#	~/.norminette/norminette.rb ./includes/* ./srcs/*
