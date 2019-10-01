# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 15:38:04 by lcassaun          #+#    #+#              #
#    Updated: 2019/09/05 15:41:11 by lcassaun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRCS = srcs/main.c

all:
	gcc -Wall -Wextra -Werror $(SRCS) -o $(NAME)

clean:
	rm -Rf *.o

fclean: clean
	rm -Rf $(NAME)

re: fclean all
