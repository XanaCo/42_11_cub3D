# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 18:07:11 by ancolmen          #+#    #+#              #
#    Updated: 2023/10/15 16:00:56 by ancolmen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######	VARIABLES #######

NAME		= cub3D
NAME_BN		= cub3D_bonus

LIBFT		= libft.a
MLX			= libmlx.a

LFT_PATH	= ./libft/
MLX_PATH	= ./mlx/
SRC_PATH	= ./src/
SRC_BN_PATH	= ./src/
BIN_PATH 	= ./bin/

SRC			= md/main.c \
			md/par/parsing.c \
			md/par/map_checks.c \
			md/par/map_walls.c \
			md/par/search_stock_pl.c \
			md/start/start.c \
			md/start/init.c \
			md/events/events.c \
			md/events/v_operations_1.c \
			md/events/v_operations_2.c \
			md/gar/garbage.c \
			md/gar/garbage_utils.c \
			md/debug/print_checks.c \
			md/utils/exit.c \
			md/utils/print_utils.c \
			md/utils/parsing_utils.c \
			md/draw/display.c \
			md/draw/draw.c \
			md/draw/raycast.c \

SRC_BN			= bn/main_bonus.c \
			bn/par/parsing_bonus.c \
			bn/par/textures_1_bonus.c \
			bn/par/textures_2_bonus.c \
			bn/par/textures_3_bonus.c \
			bn/par/map_checks_bonus.c \
			bn/par/map_walls_bonus.c \
			bn/par/search_stock_pl_bonus.c \
			bn/par/search_stock_sprite_bonus.c \
			bn/start/init_bonus.c \
			bn/start/start_bonus.c \
			bn/start/moves_bonus.c \
			bn/start/screen_title_bonus.c \
			bn/events/events_keys_bonus.c \
			bn/events/events_mouse_bonus.c \
			bn/events/v_operations_1_bonus.c \
			bn/events/v_operations_2_bonus.c \
			bn/gar/garbage_bonus.c \
			bn/gar/garbage_utils_bonus.c \
			bn/debug/print_checks_bonus.c \
			bn/utils/exit_bonus.c \
			bn/utils/error_handling_bonus.c \
			bn/utils/print_utils_bonus.c \
			bn/utils/parsing_utils_bonus.c \
			bn/draw/display_bonus.c \
			bn/draw/background_bonus.c \
			bn/draw/draw_bonus.c \
			bn/draw/draw_weapon_bonus.c \
			bn/draw/draw_utils_bonus.c \
			bn/draw/raycast_bonus.c \
			bn/draw/raycast_utils_bonus.c \
			bn/doors/handle_door_bonus.c \
			bn/doors/final_door_bonus.c \
			bn/doors/door_utils_bonus.c \
			bn/minimap/minimap_bonus.c \
			bn/minimap/minimap_colors_bonus.c \
			bn/sprites/sprites_bonus.c \
			bn/sprites/move_danny_bonus.c \
			bn/start/twins_anim_bonus.c \

OBJ			= $(addprefix $(BIN_PATH), $(SRC:.c=.o))
OBJ_BN		= $(addprefix $(BIN_PATH), $(SRC_BN:.c=.o))

DEPS		= $(OBJ:.o=.d)
DEPS_BN		= $(OBJ_BN:.o=.d)

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -MMD -MP #-g3 -Ofast

LIBFT_CF 	= -L$(LFT_PATH)

MLX_CF 		= -L$(MLX_PATH)

CLIB_CF		= -lft -lm -lbsd -lmlx -lXext -lX11

RM			= rm -rf

LEAKS		= valgrind

LF			= --leak-check=full \
        	--show-leak-kinds=all \
    		--track-origins=yes \
			--track-fds=yes \

#######	RULES #######

all: $(NAME)

$(BIN_PATH)%.o: $(SRC_PATH)%.c
	@ mkdir -p $(dir $@)
	@ echo "\n\033[97;4m🚧 compiling $@ file 🚧\033[0m\n"
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ echo "\033[32;1m★ bin OK ★\033[0m\n"
	
$(LFT_PATH)$(LIBFT):
	@ echo "\n\033[97;4m🚧 creating libft 🚧\033[0m\n"
	@ make --no-print-directory -C $(LFT_PATH)
	@ echo "\033[32;1m\n★ LIBFT OK ★\033[0m\n"

$(MLX_PATH)$(MLX):
	@ echo "\n\033[97;4m🚧 creating minilibx 🚧\033[0m\n"
	@ make --no-print-directory -C $(MLX_PATH)
	@ echo "\033[32;1m\n★ MLX OK ★\033[0m\n"

$(NAME): $(OBJ) $(LFT_PATH)$(LIBFT) $(MLX_PATH)$(MLX)
	@ echo "\033[97;4m🚧 cub3D in progress 🚧\033[0m\n"
	@ $(CC) $(CFLAGS) $(OBJ) $(LIBFT_CF) $(MLX_CF) $(CLIB_CF) -o $(NAME)
	@ echo "\033[32;1m✅ CUB3D READY ✅\033[0m\n"

bonus: $(NAME_BN)

$(NAME_BN): $(OBJ_BN) $(LFT_PATH)$(LIBFT) $(MLX_PATH)$(MLX)
	@ echo "\033[97;4m🚧 cub3D_bonus in progress 🚧\033[0m\n"
	@ $(CC) $(CFLAGS) $(OBJ_BN) $(LIBFT_CF) $(MLX_CF) $(CLIB_CF) -o $(NAME_BN)
	@ echo "\033[32;1m✅ CUB3D BONUS READY ✅\033[0m\n"

$(BIN_PATH)%.o: $(SRC_BN_PATH)%.c
	@ mkdir -p $(dir $@)
	@ echo "\n\033[97;4m🚧 compiling $@ file 🚧\033[0m\n"
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ echo "\033[32;1m★ bin OK ★\033[0m\n"

clean:
	@ echo "\n\033[97;4m🚧 cleaning object files 🚧\033[0m\n"
	@ make clean --no-print-directory -C $(LFT_PATH)
	@ make clean --no-print-directory -C $(MLX_PATH)
	@ $(RM) $(BIN_PATH)
	@ echo "\033[32;1m★ objects cleaned ★\033[0m\n"
	

fclean: clean
	@ make fclean --no-print-directory -C $(LFT_PATH)
	@ $(RM) $(NAME) $(NAME_BN)

re: fclean all

rebonus: fclean bonus

# leaks: all
# 	$(LEAKS) ./$(NAME)

# leaksfull: all
# 	$(LEAKS) $(LF) ./$(NAME)

.PHONY: all clean fclean re bonus rebonus

-include $(DEPS)
-include $(DEPS_BN)
