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

#include "so_long.h"

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

void	redraw_character(t_data *data, int new_x, int new_y) 
{
    // Assuming you have an image pointer for the character loaded using mlx_xpm_file_to_image
    void *character_image;
    int	width;
    int	height;
    
    character_image = mlx_xpm_file_to_image(data->mlx_ptr, CHAR_XPM, &width, &height);
    // Clear the previous position of the character
    if (data->char_image != NULL) 
        mlx_destroy_image(data->mlx_ptr, data->char_image);
    // Draw the character at the new position
    /**
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, character_image, 
    	new_x * TILE_SIZE, new_y * TILE_SIZE);
    **/
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, character_image, 
    	(new_x * TILE_SIZE), (new_y * TILE_SIZE));
    // Store the new character image pointer for future destruction
    data->char_image = character_image;
}


int	on_keypress(KeySym keysym, t_data *data)
{
	char	*key;

	key = XKeysymToString(keysym);
	printf("Pressed key: %s\n", key);
	if (keysym == XK_Escape)
		on_destroy(data);
	/**
	else if (keysym == XK_Left)
	{
		data->player_x -= 1;
		redraw_character(data, data->player_x, data->player_y);
	}
	else if (keysym == XK_Right)
	{
		data->player_x += 1;
		redraw_character(data, data->player_x, data->player_y);
	}
	**/
	else if (keysym == XK_Up)
	{
		data->player_y += 1;
		redraw_character(data, data->player_x, data->player_y);
	}
	else if (keysym == XK_Down)
	{
		data->player_y -= 1;
		redraw_character(data, data->player_x, data->player_y);
	}
	return (0);
}

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}
