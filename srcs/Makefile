NAME	= minishell

CC		= clang #-Wall -Werror -Wextra

RM		= rm -rf

LIBSH	= libsh/libsh.a

INCS	= -I./includes

SRCS_NAME	= main.c				\
			  get_next_line.c 		\
			  get_next_word.c		\
			  get_next_word_utils.c	\
			  get_nb_word.c			\
			  ft_get_blocks.c		\
			  ft_identify.c

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
