LIBFT_PATH		= libft
LIBFT			= $(LIBFT_PATH)/libft.a

MLX_PATH		= mlx
MLX				= $(MLX_PATH)/libmlx.a

PRINTF_PATH		= printf
PRINTF			= $(PRINTF_PATH)/libftprintf.a

# Compiler and flags
CC			= gcc
CFLAGS 			= -Wall -Wextra -Werror
MLXFLAGS		= -L$(MLX_PATH) -lmlx -lXext -lX11 -lbsd -lm

# Directories
INCLUDES_DIR	= includes
BUILD_DIR 		= build
GNL_DIR			= gnl
SRC_DIR			= srcs
HEADER			= $(INCLUDES_DIR)/so_long.h

# Library files

LIBS			= -L$(LIBFT_PATH) -lft \
				-L$(PRINTF_PATH) -lftprintf \
				-L$(MLX_PATH)	\
				$(MLXFLAGS)	\
				-L/usr/lib

# Source files
SRC_FILES 		= $(addprefix $(SRC_DIR)/, \
    				main.c \
					checks.c  \
    				map_utils.c \
    				load_images.c \
    				so_long.c \
					test_movement.c \
					movement.c	\
					errors.c \
					free.c \
    				gnl/get_next_line.c)

NAME			= so_long

$(LIBFT):
	@echo "Building libft..."
	@make -C $(LIBFT_PATH)

$(PRINTF):
	@echo "Building ft_printf.."
	@make -C $(PRINTF_PATH)

$(MLX):
	@echo "Building mlx.."
	@make -C $(MLX_PATH)

OBJECTS			= $(SRC_FILES:.c=.o)

# Targets
all: 		$(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(MLX) $(INCLUDES) $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) $(LIBS) -o $(NAME)

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(PRINTF_PATH) clean
	make -C $(MLX_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	make -C $(PRINTF_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

