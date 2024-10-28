CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
RM = rm -f
RMDIR = rm -rf

NAME = so_long 

LIBFT_PATH = ./Library
LIBFT = $(LIBFT_PATH)/libft.a

SRC_PATH = ./src
OBJ_PATH = $(SRC_PATH)/obj

SRC_UTILS_PATH = $(SRC_PATH)/utils

SRC = $(addprefix $(SRC_PATH)/, so_long.c check_file.c alloc_map.c map_parsing.c)
SRC_UTILS = $(addprefix $(SRC_UTILS_PATH)/, utils.c parsing_utils.c)

OBJ = $(addprefix $(OBJ_PATH)/, $(notdir $(SRC:.c=.o)) $(notdir $(SRC_UTILS:.c=.o)))

# --- Basic compilation ---

all: $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/%.o: $(SRC_UTILS_PATH)/%.c | $(OBJ_PATH)
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
	@$(RMDIR) $(OBJ_PATH)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
