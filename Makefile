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

# ----------------------------- VAR DECLARATION ------------------------------ #

# Name value
NAME =			fractol

#	----------------------------------------	FILES

# All the source of drawers
SRC_DRW =		src/drawers/fdrawers.c

# All the source of mlx_window
SRC_MLXW = 		src/mlx_window/window.c

# All the source of startup
SRC_STRT = 		src/startup/startup_utilites.c	\
				src/startup/initialize.c		\
				src/startup/main.c

# All the source of utils
SRC_UTIL = 		src/utils/doubleatoi.c			\
				src/utils/get_colors.c

#	----------------------------------------	HEADERS

# Header of bmlib
HEAD_BMLIB =	bmlib.h

# Header of fractol.h (funcitons)
HEAD_FRAC =		inc/headers/fractol.h

# Header of mlx_and_structs.h (structs)
HEAD_MLX_STR =	inc/headers/mlx_and_structs.h

#	----------------------------------------	OBJECTS

# All the objects of drawers
OBJ_DRW =		$(SRC_DRW%.c=%.o)

# All the objects of mlx_window
OBJ_MLXW =		$(SRC_MLXW%.c=%.o)

# All the objects of startup
OBJ_STRT =		$(SRC_STRT%.c=%.o)

# All the objects of utils
OBJ_UTIL =		$(SRC_UTIL%.c=%.o)

#	----------------------------------------	LIBRARIES



