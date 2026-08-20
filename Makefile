CC = cc
CFLAGS = -Wall -Wextra -Werror
MD = mkdir -p
RM = rm -f
RMDIR = rm -rf

NAME = so_long

LIBFT_PATH = Library/
LIBFT = $(LIBFT_PATH)libft.a

# Platform selection.
# `make` picks the host automatically; `make mac` / `make linux` force one.
# PLATFORM also names the object directory, so the two builds never share
# object files (the keycodes and the MiniLibX headers differ between them).
ifeq ($(shell uname -s), Darwin)
 PLATFORM = mac
else
 PLATFORM = linux
endif

ifeq ($(PLATFORM), mac)
 MLX_PATH = minilibx/mlx/
 MLXFLAG = -framework OpenGL -framework AppKit
 PLATFORM_DEF = -D SO_LONG_MAC
else
 MLX_PATH = minilibx/mlx_linux/
 MLXFLAG = -lXext -lX11
 PLATFORM_DEF = -D SO_LONG_LINUX
endif

MLX = $(MLX_PATH)libmlx.a

SRC_PATH = ./src
OBJ_PATH = $(SRC_PATH)/obj/$(PLATFORM)

SRC = so_long.c check_file.c alloc_map.c map_parsing.c \
      utils.c parsing_utils.c \
      error_handling.c exit_handling.c\
      draw_map.c key_handler.c run_game_utils.c \
      mlx_compat.c

OBJ = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

all: $(NAME)

linux:
	@$(MAKE) PLATFORM=linux all

mac:
	@$(MAKE) PLATFORM=mac all

$(OBJ_PATH):
	@$(MD) $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(PLATFORM_DEF) -c $< -o $@

$(MLX):
	@$(MAKE) -C $(MLX_PATH)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(MLXFLAG) -o $(NAME)

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(MLX_PATH) clean
	@$(RMDIR) $(SRC_PATH)/obj

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all mac linux clean fclean re
