# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 12:47:26 by wcollen           #+#    #+#              #
#    Updated: 2022/11/10 12:03:01 by wcollen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME				=	cub3D

GNL_DIR				=	./get_next_line

GNL_SOURCE			=	$(GNL_DIR)/get_next_line.c	\
						$(GNL_DIR)/get_next_line_utils.c

SOURCES_FILES		=	check_map1.c\
						check_map2.c\
						cub3d.c\
						draw_game.c\
						events_moving.c\
						events.c\
						free.c\
						init_color.c\
						init_file_data_arrays.c\
						init_map.c\
						init_texture.c\
						map_utils.c\
						minimap.c\
						mlx_funcs.c\
						rays.c\
						set_position.c\
						textures.c\
						utilites.c\
						validate_file.c\
						wall_collision_x.c\
						wall_collision_y.c\
						wall.c
						  
SOURCES_DIR			=	sources

LMXDIR				=	./minilibx_opengl_20191021
CFLAGS				=	-Wall -Werror -Wextra -g

HEADER  			= 	$(SOURCES_DIR)/cub3d.h

SOURCES				=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

GNL_HEADER			= 	$(GNL_DIR)/get_next_line.h

OBJ					= 	$(SOURCES:%.c=%.o)
OBJ_GNL				=	$(GNL_SOURCE:%.c=%.o)

CC					= 	gcc

LIBFTDIR  			= 	libft/
LIBFT				=	$(addprefix $(LIBFTDIR), libft.a)

.PHONY : 			all clean fclean re re_libft

all :				$(NAME)

$(NAME) :  			$(OBJ) $(HEADER) $(OBJ_GNL) $(GNL_HEADER)
					make -C $(LIBFTDIR)
					$(CC) $(CFLAGS) -I ${LMXDIR} $(SOURCES) $(GNL_SOURCE) -L ${LMXDIR} -lmlx   -framework OpenGL -framework AppKit  -L $(LIBFTDIR) -lft   -o $(NAME)

%.o : 				%.c $(HEADER) $(GNL_HEADER)
					$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean :
					@rm -f $(OBJ) $(OBJ_B) $(OBJ_GNL) 
					@make clean -C $(LIBFTDIR)

fclean : 			clean
					@rm -f $(NAME)
					@make fclean -C $(LIBFTDIR)

re_libft :
					@make re -C $(LIBFTDIR)

re :				fclean re_libft all