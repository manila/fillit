# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnila <mnila@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/24 19:30:15 by mnila             #+#    #+#              #
#    Updated: 2019/12/24 19:44:23 by mnila            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Werror -Wextra
NAME = fillit
INC = ./libft/includes/
LIBDIR = ./libft/
LIB = ft

SRCS = fillit.c solve.c board.c parse.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft
	$(CC) $(CFLAGS) -I $(INC) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS) -I $(INC) -L $(LIBDIR) -l$(LIB)

clean:
	make -C libft/ clean
	rm -f $(OBJS);

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
