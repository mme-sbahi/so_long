# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 16:01:05 by mmesbahi          #+#    #+#              #
#    Updated: 2023/02/22 21:59:19 by mmesbahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = so_long

RM = rm -rf

SRC = check_map.c draw.c ft_putnbr_fd.c ft_split.c \
		get_next_line.c get_next_line_utils.c \
		moves.c utils.c valid_path.c so_long.c \
		utils_2.c

OBJ = $(SRC:.c=.o)

all :$(NAME) 


$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c so_long.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

re: fclean all bonus 

clean:
		$(RM) $(OBJ)
fclean : clean
		$(RM) $(NAME)