# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmoll-pe <bmoll-pe@student.42bcn>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 04:23:57 by bmoll-pe          #+#    #+#              #
#    Updated: 2022/10/10 04:24:02 by bmoll-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	----------------------------------------	NAMES

# Name value
NAME =			fractol

#	----------------------------------------	FILES

# All the source of drawers
SRC_DRW =		src/drawers/fdrawers.c

# All the source of mlx_window
SRC_MLXW = 		src/mlx_window/window.c

# All the source of startup
SRC_STRT = 		src/startup/startup_utilities.c	\
				src/startup/initialize.c		\
				src/startup/main.c

# All the source of utils
SRC_UTIL = 		src/utils/double_atoi.c			\
				src/utils/get_colors.c

#	----------------------------------------	SRC DIR

# Drawers dir
DRW_DIR =		src/drawers/

# Mlx_window dir
MLXW_DRI =		src/mlx_window/

# Startup dir
STRT_DIR =		src/startup/

# Utils dir
UTIL_DIR =		src/utils/

#	----------------------------------------	FRACTOL HEADERS

# Header of fractol.h (funcitons)
HEADER_FRAC =		inc/headers/fractol.h

# Header of mlx_and_struct.h (structs)
HEADER_MLXS =		inc/headers/mlx_and_struct.h

#	----------------------------------------	ALL HEADERS DIR

# Header of bmlib
DIR_BMLIB =		inc/bmlib

# Headers of mlx
DIR_MLX =		inc/mlx

# Headers of fractol
DIR_HEDS =		inc/headers

#	----------------------------------------	OBJECTS

# All the objects of drawers
OBJ_DRW =		$(SRC_DRW:.c=.o)

# All the objects of mlx_window
OBJ_MLXW =		$(SRC_MLXW:.c=.o)

# All the objects of startup
OBJ_STRT =		$(SRC_STRT:.c=.o)

# All the objects of utils
OBJ_UTIL =		$(SRC_UTIL:.c=.o)

#	----------------------------------------	LIBRARIES

# Bmlib libraries
BMLIB =			inc/bmlib/bmlib.a

# Makefile bmlib
MAKE_BM =		inc/bmlib

# Mlx libraries
MLX =			inc/mlx/libmlx.a

# Makefile mlx
MAKE_MLX =		inc/mlx

#	----------------------------------------	COMPILATION

# Variable to compile .c files
GCC =			gcc

# Flags for the gcc compilation
FLAGS =			-Wall -Werror -Wextra

MLX_FLAGS = 	-L. -lft -lmlx -lftprintf

OGL_FLAGS =		-framework OpenGL -framework AppKit

MINILIBXCC :=	-I mlx -L $(DIR_MLX) -lmlx

OPENGL			:= -framework OpenGL -framework AppKit

#	----------------------------------------	COLORS

# Colors
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;5;94m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;5;64m
DARK_YELLOW =	\033[38;5;143m


#	----------------------------------------	ACTIONS

all:
					@$(MAKE) -C $(MAKE_BM)
					@$(MAKE) -C $(MAKE_MLX)
					@echo "make $(NAME)"
					@$(MAKE) $(NAME)

clean:
					@rm -f $(OBJ_DRW) $(OBJ_MLXW) $(OBJ_STRT) $(OBJ_UTIL)

fclean:
					@$(MAKE) clean
					@rm -f $(NAME)

re:
					@$(MAKE) fclean
					@$(MAKE) all

$(NAME) :			$(OBJ_DRW) $(OBJ_MLXW) $(OBJ_STRT) $(OBJ_UTIL)
					@$(GCC) $(FLAGS) $^ $(BMLIB) $(MINILIBXCC) $(OPENGL) -o $@


$(DRW_DIR)%.o :		$(DRW_DIR)%.c
					@echo "$(GCC) $(FLAGS) -c $< -o $@"
					@$(GCC) $(FLAGS) -I$(DIR_HEDS) -c $< -o $@

$(MLXW_DIR)%.o :	$(MLXW_DIR)%.c
					@echo "$(GCC) $(FLAGS) -c $< -o $@"
					@$(GCC) $(FLAGS) -I$(DIR_HEDS) -c $< -o $@

$(STRT_DIR)%.o :	$(STRT_DIR)%.c
					@echo "$(GCC) $(FLAGS) -c $< -o $@"
					@$(GCC) $(FLAGS) -I$(DIR_HEDS) -c $< -o $@

$(UTIL_DIR)%.o :	$(UTIL_DIR)%.c
					@echo "$(GCC) $(FLAGS) -c $< -o $@"
					@$(GCC) $(FLAGS) -I$(DIR_HEDS) -c $< -o $@

.PHONY:			all clean fclean re

































