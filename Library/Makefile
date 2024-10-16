CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
RM = rm -f
RMDIR = rm -rf

NAME = libft.a

DIR_LIBFT = ./libft
DIR_PRINTF = ./ft_printf

OBJ_DIR_LIBFT = $(DIR_LIBFT)/obj
OBJ_DIR_PRINTF = $(DIR_PRINTF)/obj
OBJ_DIR = $(OBJ_DIR_LIBFT) $(OBJ_DIR_PRINTF)

SRC_LIBFT = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
      ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
      ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
      ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
      ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
      ft_tolower.c ft_toupper.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
      ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
      ft_nbrlen.c ft_strsjoin.c

SRC_PRINTF = ft_printf.c ft_putf.c

SRC = $(addprefix $(DIR_LIBFT)/, $(SRC_LIBFT)) $(addprefix $(DIR_PRINTF)/, $(SRC_PRINTF))

OBJ_LIBFT = $(addprefix $(OBJ_DIR_LIBFT)/, $(SRC_LIBFT:.c=.o))
OBJ_PRINTF = $(addprefix $(OBJ_DIR_PRINTF)/, $(SRC_PRINTF:.c=.o))
OBJ = $(OBJ_LIBFT) $(OBJ_PRINTF)


all: $(OBJ_DIR) $(NAME)
	@echo "*** Libft created ***\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	@$(LIBC) $(NAME) $(OBJ)

$(OBJ_DIR_LIBFT)/%.o: $(DIR_LIBFT)/%.c | $(OBJ_DIR_LIBFT)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_PRINTF)/%.o: $(DIR_PRINTF)/%.c | $(OBJ_DIR_PRINTF)
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@$(RM) $(OBJ)
	@echo "*** Libft Objects cleaned ***"

fclean: clean
	@$(RMDIR) $(OBJ_DIR)
	@$(RM) $(NAME)
	@echo "*** Libft Full Cleaned ***"


re: fclean all

.PHONY: all clean fclean re
