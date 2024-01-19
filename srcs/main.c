/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:37:08 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/19 15:02:37 by gyong-si         ###   ########.fr       */
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
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, on_destroy, data);
	mlx_loop(data->mlx_ptr);
}

void print_map(char **map)
{
    int y = 0;
    while (map[y] != NULL)
    {
        int x = 0;
        while (map[y][x] != '\0')
        {
            putchar(map[y][x]);
            x++;
        }
        putchar('\n');
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
		print_map(data->map);
		if (checkfiletype(av[1]) && checkValidMap(data))
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
	{
		ft_putstr_fd("File Type must be .ber", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
