# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azari <azari@student.1337.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 13:40:15 by azari             #+#    #+#              #
#    Updated: 2023/07/15 11:29:05 by azari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

USER 		=	azari

PURPLE 		= 	\033[0;35m

CC			= 	cc

CFLAGS		= 	-Wall -Wextra -Werror #-g -fsanitize=address

NAME 		= 	cub3d

LIBFT		= 	libft/libft.a

GNL			= 	get_next_line/lgnl.a

HEADERS		=	cub3d.h libft/libft.h get_next_line/get_next_line.h gc/gc.h

OFILES		= 	$(CFILES:.c=.o)

CFILES		= 	cub3d.c								\
				parsing/map_processing.c			\
				parsing/map_error.c					\
				parsing/ft_utils.c					\
				parsing/map_utils.c					\
				parsing/parse_token.c				\
				rendering/rendering.c				\
				rendering/player.c					\
				hooks/moves.c						\
				intersection/horizontal.c			\
				intersection/vertical.c				\
				gc/gc.c
				
all : $(NAME)

$(NAME) : $(OFILES)
	@make -C libft
	@make -C get_next_line
	@$(CC) $(CFLAGS) $(LIBFT) $(GNL)  libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" $(OFILES) -o $(NAME)
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