NAME = libsh.a

# Path

OBJ_PATH = ./objs/
OBJ_BONUS_PATH = ./objs_bonus/

# Name

SRC_NAME    = 	ft_memset.c			\
		  		ft_bzero.c			\
		  		ft_memcpy.c			\
		  		ft_memccpy.c		\
		  		ft_memmove.c		\
		  		ft_memchr.c			\
		  		ft_memcmp.c			\
		  		ft_isalnum.c		\
		  		ft_isalpha.c		\
		  		ft_isascii.c		\
		  		ft_isdigit.c		\
		  		ft_isprint.c		\
		  		ft_strlcpy.c		\
		  		ft_strlen.c			\
		  		ft_strncmp.c		\
		  		ft_tolower.c		\
		  		ft_toupper.c		\
		  		ft_strlcat.c		\
		  		ft_strnstr.c		\
		  		ft_atoi.c			\
		  		ft_calloc.c			\
		  		ft_strdup.c			\
		  		ft_substr.c			\
		  		ft_strjoin.c		\
		  		ft_strtrim.c		\
		  		ft_split.c			\
		  		ft_itoa.c			\
		  		ft_strmapi.c		\
		  		ft_putchar_fd.c		\
				ft_putstr_fd.c		\
				ft_putstr.c			\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_strcmp.c

OBJ_NAME = $(SRC_NAME:.c=.o)

# Files

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# Flags

CC = clang $(CFLAGS)

CFLAGS = -Wall -Wextra -Werror

# Rules

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: %.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) -o $@ -c $<

bonus: $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
