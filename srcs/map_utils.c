/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:29:07 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/05 15:49:25 by gyong-si         ###   ########.fr       */
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
		printf("%s", array[i]);
		free(line);
		i++;
	}
	close(fd);
}

int	checkBorder(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
		y++;
	while (map[0][x] != '\n')
	{
		if (map[0][x] != '1' || map[y-1][x] != '1')
			return (0);
		x++;
	}
	x = 0;
	while (map[x])
	{
		if (map[0][x] != '1' || map[y-1][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	checkRectangle(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y] != NULL)
		y++;
	while (map[0][x] != '\n')
		x++;
	if (x > y)
		return (1);
	return (0);
}

int	checkValidMap(t_data *data)
{
	int	x;
	int y;
	int	player;
	int	map_exit;

	map_exit = 0;
	player = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\n')
		{
			if (data->map[y][x] == 'C')
				data->coins++;
			if (data->map[y][x] == 'E')
			{
				map_exit++;
				data->exit_x = x;
				data->exit_y = y;
			}
			if (data->map[y][x] == 'P')
			{
				player++;
				data->curr_x = x;
				data->curr_y = y;
			}
			x++;
		}
		y++;
	}
	ft_printf("curr_y: %d\n", data->curr_y);
	ft_printf("curr_x: %d\n", data->curr_x);
	data->map_width = x * TILE_SIZE;
	data->map_height = y * TILE_SIZE;
	if (player == 1 && map_exit == 1 && data->coins >= 1
			&& checkRectangle(data->map) == 1
			&& checkBorder(data->map) == 1)
		return (1);
	return (0);
}

void	render_map(t_data *data)
{
	int	x;
	int	y = 0;
	void	*image;

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
