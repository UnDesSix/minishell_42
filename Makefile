NAME	= minishell

CC		= clang #-Wall -Werror -Wextra

RM		= rm -rf

LIBSH	= srcs/libsh/libsh.a

INCS	= -Iincludes

SRCS_NAME	= main.c	\
			  builtins/echo.c \
			  builtins/pwd.c

SRCS_PATH	= ./srcs/

OBJS_PATH	= ./objs/

SRCS	= $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS	= $(SRCS:.c=.o)


%.o: %.c
	$(CC) $(INCS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBSH) $(INC) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_PATH)

fclean: clean
	$(RM) $(NAME)

re: clean all

#norme: clean 
#	~/.norminette/norminette.rb ./includes/* ./srcs/*
