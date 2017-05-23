# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afanneau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/19 12:31:08 by afanneau          #+#    #+#              #
#    Updated: 2016/11/19 13:19:38 by afanneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS_PATH = srcs
CPPFLAGS = -Iincludes
CC = gcc
CFLAGS = -Werror -Wall -Wextra -o
OBJECTS_PATH = $(SRCS_PATH)
LIB_PATH = libft
SRCS_NAME = main.c \
			ft_divers.c \
			ft_free.c \
			grid.c \
			read.c \
			solve.c \
			tetri.c
OBJECTS_NAME = $(SRC_NAME : .c = .o)
LIB_NAME = libft.a
INCLUDES = includes

SRCS = $(addprefix $(SRCS_PATH)/,$(SRCS_NAME))
OBJECTS = $(addprefix $(OBJECTS_PATH)/,$(OBJECTS_NAME))
LIB = $(addprefix $(LIB_PATH)/,$(LIB_NAME))

all : $(NAME)

$(NAME) :
	cd libft && make && cd ..
	$(CC) $(CFLAGS) $(NAME) $(CPPFLAGS) $(SRCS) $(LIB)

clean :
	rm -rf $(OBJECTS)
	cd libft && make clean && cd ..

fclean : clean
	rm -rf $(NAME)
	cd libft && make fclean && cd ..

re : fclean all

norme:
	norminette $(SRC) | grep "Error"
	norminette $(INCLUDES) | grep "Error"
