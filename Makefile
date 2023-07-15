# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azari <azari@student.1337.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 13:40:15 by azari             #+#    #+#              #
#    Updated: 2023/07/15 14:15:38 by azari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

USER 		=	azari

PURPLE 		= 	\033[0;35m

CC			= 	cc

CFLAGS		= 	-Wall -Wextra -Werror #-g -fsanitize=address

NAME 		= 	cub3d

LIBFTF	 	= 	libs/libft

GNLF	 	= 	libs/get_next_line

LIBFT		= 	libs/libft/libft.a

GNL			= 	libs/get_next_line/lgnl.a

HEADERS		=	cub3d.h

OFILES		= 	$(CFILES:.c=.o)

CFILES		= 	cub3d.c									\
				src/parsing/map_processing.c			\
				src/parsing/map_error.c					\
				src/parsing/ft_utils.c					\
				src/parsing/ft_map_utils.c					\
				src/parsing/parse_token.c				\
				src/rendering/rendering.c				\
				src/rendering/player.c					\
				src/hooks/moves.c						\
				src/hooks/moves2.c						\
				src/intersection/horizontal.c			\
				src/intersection/vertical.c				\
				libs/gc/gc.c
				
all : $(NAME)

$(NAME) : $(OFILES)
	@make -C $(LIBFTF)
	@make -C $(GNLF)
	@$(CC) $(CFLAGS) $(LIBFT) $(GNL)  libs/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" $(OFILES) -o $(NAME)
	@echo "$(PURPLE) ✅ cub3D "
	
libs/gc/%.o: libs/gc/%.c libs/gc/gc.h
	@echo "$(PURPLE) ⏳ Setup ongoing ⏳ ..."
	@$(CC) $(CFLAGS) -c $< -o $@
	
%.o:%.c	
	@echo "$(PURPLE) ⏳ Setup ongoing ⏳ ..."
	@$(CC) $(CFLAGS) -c $< -o $@

	
clean	:
	@make clean -C $(LIBFTF)
	@make clean -C $(GNLF)
	@rm -rf $(OFILES)
	@echo  "$(PURPLE) ❌ OBJS deleted."

fclean	: clean
	@make fclean -C $(LIBFTF)
	@make fclean -C $(GNLF)	
	@rm -rf $(NAME)
	@echo  "$(PURPLE) ❌ ALL deleted."

re		: fclean all

cl 		: all clean

.PHONY: clean fclean re all cl