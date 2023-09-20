# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 13:15:35 by diodos-s          #+#    #+#              #
#    Updated: 2023/09/20 09:38:17 by diodos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c\
      ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c\
      ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c\
      ft_strdup.c ft_substr.c ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
      ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_split.c ft_printstd.c ft_printptr.c\
	  ft_printuns.c ft_printf.c ft_printhex.c get_next_line.c get_next_line_utils.c
SRCB = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
       ft_lstclear.c ft_lstiter.c ft_lstmap.c 
OBJS = ${SRC:.c=.o}
OBJSB = ${SRCB:.c=.o}
HEADER = libft.h
INCLUDE = -I include
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
.c.o:
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
		ar rcs ${NAME} ${OBJS} ${HEADER}

all:	${NAME}

clean:
	${RM} ${OBJS}
	${RM} ${OBJSB}

fclean: clean
	${RM} ${NAME}

re:	fclean all

bonus:	${OBJS} ${OBJSB}
	ar rcs ${NAME} ${OBJS} ${OBJSB} ${HEADER}

.PHONY: all clean fclean re bonus
