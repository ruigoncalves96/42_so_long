CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
RM = rm -f

NAME = so_long 

LIBFT_PATH = ./Library
LIBFT = $(LIBFT_PATH)/libft.a

SRC = so_long.c
OBJ = so_long.o

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) -o $(NAME)

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
