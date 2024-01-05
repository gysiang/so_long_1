# Compiler and flags
CC			= gcc
CFLAGS 			= -Wall -Wextra -Werror
MLX_FLAG		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lbsd -lm

# Directories
LIBFT_DIR		= libft
PRINTF_DIR		= printf
MLX_DIR			= mlx
INCLUDES_DIR 		= includes
BUILD_DIR 		= build
GNL_DIR			= gnl
SRC_DIR			= srcs

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
				--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

INCLUDES 		= -I$(INCLUDES_DIR) \
          			-I$(LIBFT_DIR) \
           			-I$(PRINTF_DIR) \
          			-I$(MLX_DIR) \
         			-I$(SRC_DIR)/$(GNL_DIR)
# Library files

LIBS			= -L$(LIBFT_DIR) -lft \
				-L$(PRINTF_DIR) -lftprintf \
				-L$(MLX_DIR)	\
				$(MLX_FLAG)	\
				-L/usr/lib

# Source files
SRC_FILES 		= $(addprefix $(SRC_DIR)/, \
    				main.c \
    				map_utils.c \
    				load_images.c \
    				so_long.c \
					test_movement.c \
					movement.c	\
    				gnl/get_next_line.c)

# Object files
OBJS			= $(SRC_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

NAME			= so_long

# Targets
all: 		$(NAME)

$(NAME):	$(OBJS) libs
			$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJS): 	$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	 	@mkdir -p $(@D)
	 	@$(CC) -g $(CFLAGS) $(INCLUDES) -c $< -o $@

libs: 			$(LIBFT_TARGET) $(PRINTF_TARGET) $(MLX_TARGET)

$(LIBFT_TARGET):	make -C $(LIBFT_DIR)

$(PRINTF_TARGET):	make -C $(PRINTF_DIR)

$(MLX_TARGET):		make -C $(MLX_DIR)

clean:
	rm -f $(OBJ_FILES)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	make -C $(MLX_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

