CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -Lmlx -lmlx -lXext -lX11 -lm

SRC = so_long.c map_parsing.c map_parsing2.c \
      ft_helpers.c ft_helpers2.c ft_helpers3.c check_walls.c \
      init_window.c player.c ft_free.c flood_fill.c \
      init_helper.c init_helper2.c

GNL_FILES = GNL/get_next_line.c GNL/get_next_line_utils.c
HEADER = so_long.h

OBJ = $(SRC:.c=.o) $(GNL_FILES:.c=.o)

NAME = so_long

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
