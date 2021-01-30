NAME	= minishellv1

CC		= gcc -Wall -Werror -Wextra

RM		= rm -rf

INCS	= -I./includes/

SRCS_NAME	= main.c	\

SRCS_PATH	= ./srcs/

OBJS_NAME	= $(SRCS_NAME:.c=.o)

OBJS_PATH	= ./objs/

SRCS	= $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS	= $(addprefix $(OBJS_PATH), $(OBJS_NAME))

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir objs 2> /dev/null
	echo -n '>'
	$(CC) $(INCS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(INCS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_PATH)

fclean: clean
	$(RM) $(NAME)

re: clean all

#norme: clean 
#	~/.norminette/norminette.rb ./includes/* ./srcs/*
