# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/29 12:57:18 by mbompoil          #+#    #+#              #
#    Updated: 2016/09/30 16:20:11 by mbompoil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	wolf3d

CC		=	gcc
FLAGS	=	-Wall -Wextra

SRC_D	=	./src/
SRC		=	$(SRC_D)main.c \
			$(SRC_D)init.c \
			$(SRC_D)read.c \
			$(SRC_D)wolf3d.c \
			$(SRC_D)tools.c \
			$(SRC_D)hook.c \

OBJ_D	=	./.obj/
OBJ		=	$(SRC:$(SRC_D)%.c=$(OBJ_D)%.o)

LIBFT_D	=	./libft/
LIBFT	=	$(LIBFT_D)libft.a

MLX_D	=	./mlx/
MLX		=	$(MLX_D)libmlx.a

INC_D	=	./inc/

INC		=	-I$(INC_D) \
			-I$(LIBFT_D) \
			-I$(MLX_D)

LIB		=	$(LIBFT) $(MLX) -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(MLX) $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) $(LIB) -o $(NAME)
	@printf "\n\033[0;32m\033[1m%-24s..%s\n\n\033[0m" "$@" "is complete !"

$(MLX) :
	@make -C $(MLX_D)

$(LIBFT) :
	@make -C $(LIBFT_D)

$(OBJ_D)%.o : $(SRC_D)%.c
	@mkdir -p $(OBJ_D)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<
	@printf "\033[0m%-24s..\033[1m%s\n" "$<" "$@ !"

clean :
	@make -C $(LIBFT_D) clean
	@make -C $(MLX_D) clean
	@/bin/rm -rf $(OBJ_D);

fclean : clean
	@make -C $(LIBFT_D) fclean
	@make -C $(MLX_D) clean
	@/bin/rm -rf $(NAME);

re : fclean all
