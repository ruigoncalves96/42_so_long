CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
RM = rm -f

NAME = so_long 

LIBFT_PATH = ./Library
LIBFT = $(LIBFT_PATH)/libft.a

SRC_PATH = ./src

SRC = $(SRC_PATH)/so_long.c $(SRC_PATH)/check_file.c $(SRC_PATH)/map_parsing.c
OBJ = $(SRC_PATH)/so_long.o $(SRC_PATH)/check_file.o $(SRC_PATH)/map_parsing.o

# --- Basic compilation ---
%.o: %.c
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
