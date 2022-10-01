# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 09:32:53 by marvin            #+#    #+#              #
#    Updated: 2022/05/27 22:37:09 by bmoll-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =		ft_atoi.c		ft_memmove.c	ft_strlcpy.c	\
			ft_bzero.c		ft_memset.c		ft_strlen.c		\
			ft_calloc.c		ft_putchar_fd.c	ft_strmapi.c	\
			ft_isalnum.c	ft_putendl_fd.c	ft_strncmp.c	\
			ft_isalpha.c	ft_putnbr_fd.c	ft_strnstr.c	\
			ft_isascii.c	ft_putstr_fd.c	ft_strrchr.c	\
			ft_isdigit.c	ft_split.c		ft_strrspn.c	\
			ft_isprint.c	ft_strchr.c		ft_strspn.c		\
			ft_itoa.c		ft_strdup.c		ft_strtrim.c	\
			ft_memchr.c		ft_striteri.c	ft_substr.c		\
			ft_memcmp.c		ft_strjoin.c	ft_tolower.c	\
			ft_memcpy.c		ft_strlcat.c	ft_toupper.c

BNS_SRCS =	ft_lstnew_bonus.c		ft_lstadd_front_bonus.c		\
			ft_lstsize_bonus.c		ft_lstlast_bonus.c			\
			ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c		\
			ft_lstclear_bonus.c		ft_lstiter_bonus.c			\
			ft_lstmap_bonus.c

OBJS =		$(SRCS:.c=.o)

BNS_OBJS =	$(BNS_SRCS:.c=.o)

FLAGS =		-Werror -Wextra -Wall -c

CC = 		gcc

LIBR = 		libft.h

all:		$(NAME)

%.o: %.c $(LIBR)
	$(CC) $(FLAGS) $< -o $@

# $(OBJS):		$(LIBR) $(SRCS)
#			$(CC) $(FLAGS) $(SRCS)

# $(BNS_OBJS):	$(LIBR) $(BNS_SRCS)
#			$(CC) $(FLAGS) $(BNS_SRCS)

$(NAME):	$(OBJS) $(LIBR)
			@ar -rcs $(NAME) $^

bonus:		$(OBJS) $(BNS_OBJS) $(LIBR)
			@ar -rcs	$(NAME) $^
			@touch		$@

clean:
			@rm -f	$(OBJS)
			@rm -f	$(BNS_OBJS)

fclean:		clean
			@rm -f	$(NAME)
			@rm -f	bonus

re:			fclean all

.PHONY: all clean fclean re
