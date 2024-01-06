/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:29:07 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/06 15:06:04 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_map(const char *filename, char **array)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		array[i] = ft_strdup(line);
		ft_printf("%s", array[i]);
		free(line);
		i++;
	}
	close(fd);
}

int		check_allcoinscollected(t_data *data)
{
	if (data->total_coins == data->coins_collected)
		return (1);
	return (0);
}

void	shows_moves(t_data *data)
{
	char *moves_str;
	char *coins_str;

	moves_str = ft_itoa(data->move_count);
	coins_str = ft_itoa(data->coins_collected);
	mlx_string_put(data->mlx_ptr, data->win_ptr,
	 21, 21, 0x000000, "No of moves : ");
    mlx_string_put(data->mlx_ptr, data->win_ptr,
	 221, 21, 0x000000, moves_str);
    mlx_string_put(data->mlx_ptr, data->win_ptr,
	 21, 41, 0x000000, "No of coins : ");
    mlx_string_put(data->mlx_ptr, data->win_ptr,
	 221, 41, 0x000000, coins_str);
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		20, 20, 0xFFFFFF, "No of moves: ");
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		220, 20, 0xFFFFFF, moves_str);
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		20, 40, 0xFFFFFF, "No of coins : ");
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		220, 40, 0xFFFFFF, coins_str);
	free(moves_str);
	free(coins_str);
}

void	render_map(t_data *data)
{
	int	x;
	int	y;
	void	*image;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\n')
		{
			image = load_image(data->map[y][x], data->mlx_ptr);
			if (data->map[y][x] == 'P')
				data->char_image = image;
			if (image != NULL)
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, image,
					x * TILE_SIZE, y * TILE_SIZE);
			}
			x++;
		}
		y++;
	}
}
