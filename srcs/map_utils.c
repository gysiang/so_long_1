/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:29:07 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/21 22:52:55 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**allocate_map(char *filename)
{
	int		fd;
	char	*line;
	char	*holder_map;
	char	*holder;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	holder_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		holder = holder_map;
		holder_map = ft_strjoin(holder, line);
		free(line);
		free(holder);
	}
	map = ft_split(holder_map, '\n');
	free(holder_map);
	close(fd);
	return (map);
}

int	check_allcoinscollected(t_data *data)
{
	if (data->total_coins == data->coins_collected)
		return (1);
	return (0);
}

void	shows_moves(t_data *data)
{
	char	*moves_str;
	char	*coins_str;

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

void	img_draw(t_data *data, void *image, int x, int y)
{
	mlx_put_image_to_window
		(data->mlx_ptr, data->win_ptr, image, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				img_draw(data, data->border_image, x, y);
			else if (data->map[y][x] == '0')
				img_draw(data, data->floor_image, x, y);
			else if (data->map[y][x] == 'P')
				img_draw(data, data->char_image, x, y);
			else if (data->map[y][x] == 'C')
				img_draw(data, data->coin_image, x, y);
			else if (data->map[y][x] == 'E')
				img_draw(data, data->exit_image, x, y);
			x++;
		}
		y++;
	}
}
