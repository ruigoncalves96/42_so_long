CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBC = ar rcs
MD = mkdir -p
RM = rm -f
RMDIR = rm -rf

NAME = so_long 

LIBFT_PATH = ./Library
LIBFT = $(LIBFT_PATH)/libft.a

SRC_PATH = ./src
OBJ_PATH = $(SRC_PATH)/obj

SRC = so_long.c check_file.c alloc_map.c map_parsing.c \
      utils.c parsing_utils.c \
      error_handling.c

OBJ = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

all: $(NAME)

$(OBJ_PATH):
	@$(MD) $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c -Imlx $< -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	@make -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@$(RMDIR) $(OBJ_PATH)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
