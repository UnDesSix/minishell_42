NAME		=	minishell

CC			=	clang -g -Wall -Werror -Wextra

RM			=	rm -rf

LIBSH		=	libsh/libsh.a

INCS		=	-I./includes

SRCS_NAME	=	main.c							\
				main/manage_line.c				\
				main/divide_lines.c				\
				signals/signals.c				\
				builtins/cd.c					\
				builtins/exit.c					\
				builtins/echo.c					\
				builtins/exec_builtins.c		\
				builtins/pwd.c					\
				ast/ast_exec.c					\
				ast/ast_clean.c					\
				ast/ast_count.c					\
				ast/pipe.c						\
				ast/ast_run.c					\
				ast/redirection.c				\
				ast/check_ast.c					\
				ast/ast_pipe.c					\
				ast/ast_redi.c					\
				ast/ast_args.c					\
				ast/ast_utils.c					\
				ast/define_std_inout.c			\
				ast/ast.c						\
				lexer/sort_words.c 				\
				lexer/sort_words_copy.c			\
				lexer/sort_words_utils.c		\
				lexer/get_nb_word.c				\
				lexer/lexer_quotes.c			\
				lexer/get_next_line.c 			\
				lexer/lexer_utils.c				\
				lexer/check_lexer.c				\
				lexer/lexer.c					\
				env/builtin_export.c			\
				env/export_variable.c			\
				env/ft_list_clear.c				\
				env/ft_list_foreach.c			\
				env/ft_list_remove_if.c			\
				env/print_tabs.c				\
				env/check_var_syntax.c			\
				env/free_tabs.c					\
				env/ft_list_duplicate.c			\
				env/ft_list_push_back.c			\
				env/ft_list_push_strs.c			\
				env/ft_list_sort.c				\
				env/sub_main.c					\
				env/create_var.c				\
				env/ft_create_elem.c			\
				env/ft_list_find.c				\
				env/list_to_tabs.c				\
				expansion/expansion.c			\
				expansion/expansion_utils.c		\
				expansion/expansion_utils2.c	\
				expansion/free_split.c			\
				parser/ft_identify.c

SRCS_PATH	= ./
OBJS_PATH	= ./objs/

SRCS	= $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS	= $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(INCS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C libsh/
	$(CC) $(OBJS) $(LIBSH) $(INCS) -o $(NAME)

clean:
	make clean -C libsh/
	$(RM) $(OBJS)
	$(RM) $(OBJS_PATH)

fclean: clean
	make fclean -C libsh/
	$(RM) $(NAME)

relib:
	make re -C libsh/

re: fclean relib all

norme: clean 
	norminette
