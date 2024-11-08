CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAG = -L. -lXext -L. -lX11
LIBC = ar rcs
MD = mkdir -p
RM = rm -f
RMDIR = rm -rf

NAME = so_long 

LIBFT_PATH = Library/
LIBFT = $(LIBFT_PATH)libft.a
MLX_PATH = minilibx/mlx_linux/
MLX = $(MLX_PATH)libmlx.a

SRC_PATH = ./src
OBJ_PATH = $(SRC_PATH)/obj

SRC = so_long.c check_file.c alloc_map.c map_parsing.c \
      utils.c parsing_utils.c \
      error_handling.c exit_handling.c\
      draw_map.c key_handler.c run_game_utils.c

OBJ = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

all: $(NAME)

$(OBJ_PATH):
	@$(MD) $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	@make -C $(MLX_PATH)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(MLXFLAG) -o $(NAME)

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX_PATH) clean
	@$(RM) $(OBJ)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@$(RMDIR) $(OBJ_PATH)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

#MLXFLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit
#MLX_PATH = mlx/
