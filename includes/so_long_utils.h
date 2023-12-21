/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:39:37 by gyong-si          #+#    #+#             */
/*   Updated: 2023/12/20 17:54:47 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_UTILS_H
# define SO_LONG_UTILS_H

# include <unistd.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

# define TILE_SIZE			50

# define BORDER_XPM			"assets/sprites/tree.xpm"
# define CHAR_XPM			"assets/sprites/front_character.xpm"
# define FLOOR_XPM			"assets/sprites/grass.xpm"
# define COIN_XPM			"assets/sprites/pokeball.xpm"
# define EXIT_XPM			"assets/sprites/door.xpm"

void	open_map(const char *filename, char **array);
void	*load_image(char c, char *path, void *mlx_ptr);
int	checkfiletype(const char *filename);

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int	coins;
	int	player_x;
	int	player_y;
	int	exit_x;
	int	exit_y;
}	game_data;


#endif
