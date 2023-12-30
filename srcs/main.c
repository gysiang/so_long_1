/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:37:08 by gyong-si          #+#    #+#             */
/*   Updated: 2023/12/21 16:41:37 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "This is a window");
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	render_map(data);
	mlx_loop(data->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_data	*data;
	
	if (ac == 2)
	{
		if (checkfiletype(av[1]) == 0)
		{
			perror("This filetype is not .ber");
			exit(EXIT_FAILURE);
		}
		data = init_t_data();
		open_map(av[1], data->map);
		if (checkValidMap(data) == 0)
		{
			perror("This is not a valid map");
			exit(EXIT_FAILURE);
		}
		init_t_data(data);
		init_game(data);
	}
	return (0);
}

