NAME	= minishell

CC		= clang -g #-fsanitize=address #-Wall -Werror -Wextra

RM		= rm -rf

LIBSH	= libsh/libsh.a

INCS	= -I./includes

SRCS_NAME	= main.c							\
			  debug.c							\
			  builtins/cd.c						\
			  builtins/exit.c					\
			  builtins/pwd.c					\
			  builtins/echo.c					\
			  expansion/expansion.c				\
			  expansion/expansion_utils.c		\
			  ast/ast_exec.c					\
			  ast/ast.c							\
			  ast/check_ast.c					\
			  ast/ast_pipe.c					\
			  ast/ast_redi.c					\
			  ast/ast_args.c					\
			  ast/ast_utils.c					\
			  lexer/get_next_line.c 			\
			  lexer/get_nb_word.c				\
			  lexer/lexer_utils.c				\
			  lexer/lexer.c						\
			  parser/ft_identify.c				\
              env/builtin_export.c              \
              env/export_variable.c             \
              env/ft_list_clear.c               \
              env/ft_list_foreach.c             \
              env/ft_list_remove_if.c           \
              env/print_tabs.c                  \
              env/check_var_syntax.c            \
              env/free_tabs.c                   \
              env/ft_list_duplicate.c           \
              env/ft_list_push_back.c           \
              env/ft_list_push_strs.c           \
              env/ft_list_sort.c                \
              env/sub_main.c                    \
              env/create_var.c                  \
              env/ft_create_elem.c              \
              env/ft_list_find.c                \
              env/list_to_tabs.c				\
			  update_env/update_env.c			


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

relib:
	make re -C libsh/

re: fclean relib all

norme: clean 
	norminette
