/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:31:53 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/10 18:57:12 by gyong-si         ###   ########.fr       */
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
		return (NULL);
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

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_map(data);
	exit(0);
}
