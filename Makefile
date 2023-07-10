# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azari <azari@student.1337.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 13:40:15 by azari             #+#    #+#              #
#    Updated: 2023/07/10 09:35:58 by azari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PURPLE 		= 	\033[0;35m

CC			= 	gcc

FLAGS		= 	-Wall -Wextra -Werror -g -fsanitize=address

NAME 		= 	cub3d

LIBFT		= 	libft/libft.a

GNL			= 	get_next_line/lgnl.a

HEADERS		=	cub3d.h libft/libft.h get_next_line/get_next_line.h

OFILES		= 	$(CFILES:.c=.o)

CFILES		= 	cub3d.c								\
				parsing/map_processing.c			\
				parsing/map_error.c					\
				
all : $(NAME)

$(NAME) : $(OFILES)
	@make -C libft
	@make -C get_next_line
	@$(CC) $(LIBFT) $(GNL) -lmlx -framework OpenGL -framework AppKit $(OFILES) -o $(NAME)
	@echo "$(PURPLE) ✅ cub3D "
	
	
%.o:%.c	$(HEADERS)
	@echo "$(PURPLE) ⏳ Setup ongoing ⏳ ..."
	@$(CC) $(CFLAGS) -c $< -o $@

	
clean	:
	@make clean -C libft
	@make clean -C get_next_line
	@rm -rf $(OFILES)
	@echo  "$(PURPLE) ❌ OBJS deleted."

fclean	: clean
	@make fclean -C libft
	@make fclean -C get_next_line	
	@rm -rf $(NAME)
	@echo  "$(PURPLE) ❌ ALL deleted."

re		: fclean all

cl 		: all clean

.PHONY: clean fclean re all cl