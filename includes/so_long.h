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
# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
//# include "get_next_line.h"

# define TILE_SIZE			50
# define MAX_ROWS			10

# define BORDER_XPM			"assets/sprites/tree.xpm"
# define CHAR_XPM			"assets/sprites/front_character.xpm"
# define FLOOR_XPM			"assets/sprites/grass.xpm"
# define COIN_XPM			"assets/sprites/pokeball.xpm"
# define EXIT_XPM			"assets/sprites/door.xpm"

typedef	struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int	width;
	int	height;
	int	coins;
	int	exit_x;
	int	exit_y;
	int	player_x;
	int	player_y;
}		t_data;

int	ft_strcmp(const char *s1, const char *s2);
int	checkfiletype(const char *filename);
int	on_keypress(KeySym keysym, t_data *data);
int	on_destroy(t_data *data);
int	checkBorder(char **map);
int	checkRectangle(char **map);
int	checkValidMap(t_data *data);
void	open_map(const char *filename, char **array);
void	render_map(char **map, void *mlx_ptr, void *win_ptr);
void	*load_image(char c, void *mlx_ptr);
t_data	*init_t_data();

#endif
