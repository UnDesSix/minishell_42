NAME	= minishell

CC		= clang -g #-Wall -Werror -Wextra

RM		= rm -rf

LIBSH	= libsh/libsh.a

INCS	= -I./includes

SRCS_NAME	= main.c							\
			  get_next_line.c 					\
			  get_next_word/get_next_word.c		\
			  get_next_word/gnw_quotes.c		\
			  get_next_word/gnw_space.c			\
			  get_next_word/gnw_null.c			\
			  get_next_word/gnw_speop.c			\
			  get_next_word/gnw_semicolon.c		\
			  get_nb_word.c						\
			  ft_get_blocks.c					\
			  ft_execute_block.c				\
			  ft_identify.c						\
			  env/builtin_export.c				\
			  env/export_variable.c				\
			  env/ft_list_clear.c				\
			  env/ft_list_foreach.c				\
			  env/ft_list_remove_if.c			\
			  env/print_tabs.c					\
			  env/check_var_syntax.c			\
			  env/free_tabs.c					\
			  env/ft_list_duplicate.c			\
			  env/ft_list_push_back.c			\
			  env/ft_list_push_strs.c			\
			  env/ft_list_sort.c				\
			  env/sub_main.c					\
			  env/create_var.c					\
			  env/ft_create_elem.c				\
			  env/ft_list_find.c				\
			  env/list_to_tabs.c

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
