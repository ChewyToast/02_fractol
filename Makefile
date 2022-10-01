NAME		=	fractol
CC			=	gcc
FLAGS		=	-g -Wall -Wextra -Werror
MLX			=	inc/mlx/Makefile.gen
INC			=	-I ./inc/mlx
LIB			=	-L ./inc/mlx -lmlx -lXext -lX11 -lm -lbsd
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	inc/libft/ft_atoi.c			inc/libft/ft_memmove.c		inc/libft/ft_strlcpy.c	\
				inc/libft/ft_bzero.c		inc/libft/ft_memset.c		inc/libft/ft_strlen.c	\
				inc/libft/ft_calloc.c		inc/libft/ft_putchar_fd.c	inc/libft/ft_strmapi.c	\
				inc/libft/ft_isalnum.c		inc/libft/ft_putendl_fd.c	inc/libft/ft_strncmp.c	\
				inc/libft/ft_isalpha.c		inc/libft/ft_putnbr_fd.c	inc/libft/ft_strnstr.c	\
				inc/libft/ft_isascii.c		inc/libft/ft_putstr_fd.c	inc/libft/ft_strrchr.c	\
				inc/libft/ft_isdigit.c		inc/libft/ft_split.c		inc/libft/ft_strrspn.c	\
				inc/libft/ft_isprint.c		inc/libft/ft_strchr.c		inc/libft/ft_strspn.c	\
				inc/libft/ft_itoa.c			inc/libft/ft_strdup.c		inc/libft/ft_strtrim.c	\
				inc/libft/ft_memchr.c		inc/libft/ft_striteri.c		inc/libft/ft_substr.c	\
				inc/libft/ft_memcmp.c		inc/libft/ft_strjoin.c		inc/libft/ft_tolower.c	\
				inc/libft/ft_memcpy.c		inc/libft/ft_strlcat.c		inc/libft/ft_toupper.c	\
				src/double_atoi.c			src/fdrawers.c				src/main.c				\
				src/window.c				src/initialize.c			src/startup_utilities.c	\

all:		$(MLX) obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -fsanitize=address -o $@ $^ $(LIB)

$(MLX):
			@echo " [ .. ] | Compiling minilibx.."
			@make -s -C mlx
			@echo " [ OK ] | Minilibx ready!"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@rm -rf $(OBJ) obj
			@echo "object files removed."

fclean:		clean
			@rm -rf $(NAME)
			@echo "binary file removed."

re:			fclean all

.PHONY:		all clean fclean re
