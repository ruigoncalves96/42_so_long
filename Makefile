CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
RM = rm -f

NAME = so_long 

LIBFT_PATH = ./Library
LIBFT = $(LIBFT_PATH)/libft.a

SRC_PATH = ./src
OBJ_PATH = $(SRC_PATH)/obj

SRC = $(addprefix $(SRC_PATH)/, so_long.c, check_file.c, alloc_map.c, map_parsing.c, utils.c)
OBJ = $(addprefix $(SRC_PATH)/, $(SRC:.c=.o))

# --- Basic compilation ---

all: $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) -o $(NAME)
# ---	---	---	---

# --- MAC compilation ---
#%.o: %.c
#	$(CC) $(CFLAGS) -Imlx -c $< -o $@
#
#all: $(NAME)
#
#$(NAME): $(OBJ)
#	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
# ---	---	---	---

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	@make -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
