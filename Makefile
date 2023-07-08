# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azari <azari@student.1337.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 13:40:15 by azari             #+#    #+#              #
#    Updated: 2023/07/07 13:51:02 by azari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PURPLE 	= 	\033[0;35m

CC		= 	gcc

FLAGS	= 	-Wall -Wextra -Werror

NAME 	= 	cub3d

CFILES	= 	cub3d.c		\
			test.c

OFILES	= 	$(CFILES:.c=.o)

all : $(NAME)

$(NAME) : $(OFILES)
	@$(CC) -lmlx -framework OpenGL -framework AppKit $(OFILES) -o $(NAME)
	@echo "$(PURPLE) ✅ Philosophers "
	
%.o:%.c
	@echo "$(PURPLE) ⏳ Setup ongoing ⏳ ..."
	@$(CC) $(CFLAGS) -c $^ -o $@
	
clean	:
	@rm -rf $(OFILES)
	@echo  "$(PURPLE) ❌ OBJS deleted."

fclean	: clean
	@rm -rf $(NAME)
	@echo  "$(PURPLE) ❌ ALL deleted."

re		: fclean all

cl : all clean

.PHONY: clean fclean re all