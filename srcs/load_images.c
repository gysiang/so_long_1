/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:31:53 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/05 12:39:57 by gyong-si         ###   ########.fr       */
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

void	ft_render_map_after_move(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	render_map(data);
}

int	on_keypress(KeySym keysym, t_data *data)
{
	char	*key;

	key = XKeysymToString(keysym);
	ft_printf("Pressed key: %s\n", key);
	if (keysym == XK_Escape)
		on_destroy(data);
	if (keysym == XK_Up)
	{
		ft_printf("curr_x: %d\n", data->curr_x);
		ft_printf("curr_y: %d\n", data->curr_y);
		ft_printf("moves: %d\n", data->move_count);
	}
	return (0);
}

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}
