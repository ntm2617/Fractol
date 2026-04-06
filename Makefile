NAME = fractol

SRC = main.c main_helper.c scale_adjust.c mandelbrot.c \
		zoom_slide.c main_lib.c julia.c

OBJ = $(SRC:.c=.o)

MLX_DIR = ./minilibx-linux

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

CC = cc

FLAG = -Wall -Wextra -Werror -o3

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) $(OBJ) $(MLX_FLAGS) -o $(NAME)

%.o: %.c Makefile
	@$(CC) $(FLAG) -I. -I$(MLX_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all