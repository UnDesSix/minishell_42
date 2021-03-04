NAME	= minishell

CC		= clang -g #-fsanitize=address #-Wall -Werror -Wextra

RM		= rm -rf

LIBSH	= libsh/libsh.a

INCS	= -I./includes

SRCS_NAME	= main.c							\
			  lexer/get_next_line.c 			\
			  lexer/get_next_word.c				\
			  lexer/get_nb_word.c				\
			  lexer/lexer_utils.c				\
			  lexer/lexer.c						\
			  parser/ft_identify.c

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

norme: clean 
	norminette
