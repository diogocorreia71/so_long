# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 10:21:23 by diodos-s          #+#    #+#              #
#    Updated: 2023/09/20 10:58:55 by diodos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 

NAME = so_long

OBJS = ${SRC:.c=.o}

RM = rm -f

FLAGS = -Wall -Wextra -Werror -g

MAKE = make -C

LIBFT_PATH = lib/libft

MLX_PATH = lib/mlx

LIBFT = -L ${LIBFT_PATH} -lft

MLX = -L ${MLX_PATH} -lmlx -Ilmlx -lXext -lX11 -lm

all: ${NAME}

$(NAME): ${OBJS}
				${MAKE} ${LIBFT_PATH}
				${MAKE} ${MLX_PATH}
				cc ${FLAGS} ${OBJS} ${LIBFT} ${MLX} -o ${NAME}
				
clean:
				${MAKE} ${LIBFT_PATH} clean
				${MAKE} ${MLX_PATH} clean
				${RM} ${OBJS}

fclean: clean
				${MAKE} ${LIBFT_PATH} fclean
				${RM} ${NAME}

re: fclean all

