# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azari <azari@student.1337.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/08 16:41:41 by azari             #+#    #+#              #
#    Updated: 2023/07/08 16:47:46 by azari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	lgnl.a

CC 			= 	cc

FLAGS 		=  	-Wall -Werror -Wextra

CFILES 		= 	get_next_line.c			\
				get_next_line_utils.c	\

OFILES 		= ${CFILES:.c=.o}

all : ${NAME}

${NAME} : ${OFILES}
	@ar -crs ${NAME} ${OFILES}
	
%.o:%.c get_next_line.h
	@${CC} -c ${FLAGS} $<

clean :
	@rm -f ${OFILES}

fclean : clean
	@rm -f ${NAME}

re : fclean all

.PHONY: clean fclean re all