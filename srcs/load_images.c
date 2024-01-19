/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:31:53 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/19 15:11:08 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*load_image(char c, void *mlx_ptr)
{
	char	*image_path;
	void	*image;
	int		height;
	int		width;

	if (c == '0')
		image_path = FLOOR_XPM;
	else if (c == '1')
		image_path = BORDER_XPM;
	else if (c == 'C')
		image_path = COIN_XPM;
	else if (c == 'E')
		image_path = EXIT_XPM;
	else if (c == 'P')
		image_path = CHAR_XPM;
	image = mlx_xpm_file_to_image(mlx_ptr, image_path, &width, &height);
	return (image);
}

void	ft_render_map_after_move(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	render_map(data);
	shows_moves(data);
}

int	on_keypress(KeySym keysym, t_data *data)
{
	char	*key;

	key = XKeysymToString(keysym);
	ft_printf("Pressed key: %s\n", key);
	if (keysym == XK_Escape)
		on_destroy(data);
	if (keysym == XK_Up)
		if (moveup_test(data) == 0)
			move_up(data);
	if (keysym == XK_Down)
		if (movedown_test(data) == 0)
			move_down(data);
	if (keysym == XK_Left)
		if (moveleft_test(data) == 0)
			move_left(data);
	if (keysym == XK_Right)
		if (moveright_test(data) == 0)
			move_right(data);
	return (0);
}

void	init_image(t_data *data)
{
	data->char_image = load_image('P', data->mlx_ptr);
	data->coin_image = load_image('C', data->mlx_ptr);
	data->floor_image = load_image('0', data->mlx_ptr);
	data->exit_image = load_image('E', data->mlx_ptr);
	data->border_image = load_image('1', data->mlx_ptr);
}

int	on_destroy(t_data *data)
{
	free_map(data->map);
	free_img(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	exit(0);
	return (0);
}
