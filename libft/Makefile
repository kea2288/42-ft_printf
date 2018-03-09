#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: ekulyyev <ekulyyev@student.42.us.org>      +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/09/21 14:43:51 by ekulyyev          #+#    #+#             *#
#*   Updated: 2018/03/09 11:59:35 by ekulyyev         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = libft.a
SRCS_DIR = *.c
HEADERS_DIR = libft.h
FUNCTIONS = *.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRCS_DIR) -I$(HEADERS_DIR)
	ar rc $(NAME) $(FUNCTIONS)
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
