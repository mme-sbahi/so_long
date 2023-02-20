# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 16:01:05 by mmesbahi          #+#    #+#              #
#    Updated: 2023/02/13 16:07:12 by mmesbahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = so_long

RM = rm -rf

SRC = check_map.c

OBJ = $(SRC:.c=.o)

all :$(NAME) 


$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c so_long.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

re: fclean all bonus 

clean:
		$(RM) $(OBJ)
fclean : clean
		$(RM) $(NAME)