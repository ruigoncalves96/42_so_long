CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
RM = rm -f

NAME = so_long 

LIBFT_PATH = ./Library
LIBFT = $(LIBFT_PATH)/libft.a

SRC = so_long.c
OBJ = so_long.o

# --- Basic compilation ---
#%.o: %.c
#	@$(CC) $(CFLAGS) -c $< -o $@
#
#$(NAME): $(LIBFT) $(OBJ)
#	@$(CC) $(OBJ) $(LIBFT) -o $(NAME)
# ---	---	---	---

# --- MAC compilation ---
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
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
