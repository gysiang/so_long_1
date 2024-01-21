/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:05:43 by gyong-si          #+#    #+#             */
/*   Updated: 2023/12/19 14:10:44 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../mlx/mlx.h"
# include "../srcs/gnl/get_next_line.h"

# define TILE_SIZE			50
# define MAX_ROWS			15
# define MAX_COLS			15

# define BORDER_XPM			"assets/sprites/tree.xpm"
# define CHAR_XPM			"assets/sprites/front_character.xpm"
# define FLOOR_XPM			"assets/sprites/grass.xpm"
# define COIN_XPM			"assets/sprites/pokeball.xpm"
# define EXIT_XPM			"assets/sprites/door.xpm"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*char_image;
	void	*exit_image;
	void	*border_image;
	void	*coin_image;
	void	*floor_image;
	char	**map;
	int		map_width;
	int		map_height;
	int		total_coins;
	int		coins_collected;
	int		move_count;
	int		exit_count;
	int		player_count;
	int		exit_x;
	int		exit_y;
	int		curr_x;
	int		curr_y;
	int		tr;
	int		td;
}		t_data;

int		ft_strcmp(const char *s1, const char *s2);
int		checkfiletype(const char *filename);
int		on_keypress(KeySym keysym, t_data *data);
int		on_destroy(t_data *data);
int		checkborder(char **map);
int		checkrectangle(char **map);
int		checkvalidmap(t_data *data);
int		check_allcoinscollected(t_data *data);
int		moveup_test(t_data *data);
int		movedown_test(t_data *data);
int		moveright_test(t_data *data);
int		moveleft_test(t_data *data);
int		is_validated(char **map);
int		valid_path(t_data *data);
int		validmove(t_data *data, char **array, int row, int col);
char	**create_array(int rows, int cols);
char	**allocate_map(char *filename);
void	allocate_gamevalues(t_data *data);
void	allocate_mapvalues(t_data *data);
void	allocate_exitvalues(t_data *data);
void	shows_moves(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
void	ft_render_map_after_move(t_data *data);
void	*load_image(char c, void *mlx_ptr);
void	free_img(t_data *data);
void	free_array(char **array, int rows);
void	free_map(char **map);
void	init_image(t_data *data);
void	render_map(t_data *data);
void	init_t_data(t_data *data);
void	error_type(int c);
void	img_draw(t_data *data, void *image, int x, int y);
void	print_map(char **map);
void	floodfill(t_data *data, int row, int col, char **array);

#endif
