/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:31:53 by gyong-si          #+#    #+#             */
/*   Updated: 2023/12/21 18:02:04 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long_utils.h"

void	*load_image(char c, void *mlx_ptr)
{
	char	*image_path;
	int		height;
	int		width;

	if (c == '0')
		image_path = FLOOR_XPM;
	if (c == '1')
		image_path = BORDER_XPM;
	if (c == 'C')
		image_path = COIN_XPM;
	if (c == 'E')
		image_path = EXIT_XPM;
	if (c == 'P')
		image_path = CHAR_XPM;
	return (mlx_xpm_file_to_image(mlx_ptr, image_path, &width, &height));
}

void	render_map(char **map, void *mlx_ptr, void *win_ptr)
{
	int	x;
	int	y = 0;
	void	*image;

	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\n')
		{
			image = load_image(map[y][x], mlx_ptr);
			if (image != NULL)
			{
				mlx_put_image_to_window(mlx_ptr, win_ptr, image, 
					x * TILE_SIZE, y * TILE_SIZE);
			}
			x++;
		}
		y++;
	}
}

int	on_keypress(KeySym keysym, t_data *data)
{
	char	*key;
	void	*image;
	void	*empty_tile;
	
	empty_tile = load_image(FLOOR_XPM, data->mlx_ptr);
	key = XKeysymToString(keysym);
	printf("Pressed key: %s\n", key);
	if (keysym == XK_Escape)
		on_destroy(data);
	else if (keysym == XK_Left)
	{
		image = load_image(CHAR_XPM, data->mlx_ptr);
		data->map[data->player_x][data->player_y] = '0';
		data->player_x--;
		data->map[data->player_x][data->player_y] = 'P';
	}
	else if (keysym == XK_Right)
	{
		image = load_image(CHAR_XPM, data->mlx_ptr);
		data->--player_x++;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, image,
				data->player_x, data->player_y);
	}
	else if (keysym == XK_Up)
	{
		image = load_image(CHAR_XPM, data->mlx_ptr);
		data->player_y++;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, image,
				data->player_x, data->player_y);
	}
	else if (keysym == XK_Down)
	{
		image = load_image(CHAR_XPM, data->mlx_ptr);
		data->player_y--;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, image
				data->player_x, data->player_y);
	}
	render_map(map, data->mlx_ptr, data->win_ptr);
	return (0);
}
