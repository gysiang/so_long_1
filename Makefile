# Compiler Flags
CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

LFLAGS 			=	-lft -lmlx -lmlx_Linux -lX11 -lXext -lm

# Directories
LIBFT_DIR		=	libft

# Source files
SRC_FILES		=	main.c		\
				  	check_map.c	\
				  	so_long_utils.c	\
					gnl/get_next_line.c	\

# Object files
OBJ_FILES		=  $(SRC_FILES:.c=.o)

LIBFT_NAME		=	libft.a

# Targets
$(NAME)			:	${CC} ${CFLAGS} ${LFLAGS} ${OBJ_FILES}

all             :   $(NAME) $(LIBFT_NAME) $(MLX_NAME)

$(LIBFT_NAME)	:	@make -C $(LIBFT_NAME)

$(MLX_NAME)		:	@make -C mlx

clean			:   rm -f $(OBJ_FILES)
					make -C ./libft clean

re				:	fclean all

.PHONY			:	all clean fclean re libft mlx
