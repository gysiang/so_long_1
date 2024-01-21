/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:37:08 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/21 23:00:08 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map_width,
			data->map_height, "So Long - 42 Game");
	init_image(data);
	render_map(data);
	shows_moves(data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, on_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask,
		on_destroy, data);
	mlx_loop(data->mlx_ptr);
}

void	print_map(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			ft_putchar(map[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		data = malloc(sizeof(*data));
		if (!data)
			error_type(7);
		init_t_data(data);
		data->map = allocate_map(av[1]);
		if (checkfiletype(av[1]) && checkvalidmap(data))
			init_game(data);
		else
		{
			if (data->map)
				free_map(data->map);
			free(data);
			error_type(14);
		}
	}
	else
		error_type(21);
	return (0);
}
