/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:50:04 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/06 15:52:53 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkBorder(char **map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[y] != NULL)
		y++;
	while (map[0][x] != '\n' && map[y-1][x] != '\0')
	{
		if (map[0][x] != '1' || map[y-1][x] != '1')
			return (0);
		x++;
	}
	x = 0;
	while (map[x] && map[y-1][x] != '\0')
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

void	allocate_gamevalues(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\n')
		{
			if (data->map[y][x] == 'C')
				data->total_coins++;
			if (data->map[y][x] == 'E')
				data->exit_count++;
			if (data->map[y][x] == 'P')
			{
				data->player_count++;
				data->curr_y = y;
				data->curr_x = x;
			}
			x++;
		}
		y++;
	}
}

void	allocate_mapvalues(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\n')
		{
			x++;
		}
		y++;
	}
	data->tr = x-1;
	data->td = y-1;
	data->map_width = x * TILE_SIZE;
	data->map_height = y * TILE_SIZE;
}

int	checkValidMap(t_data *data)
{
	allocate_gamevalues(data);
	allocate_mapvalues(data);
	if (data->player_count == 1
			&& data->exit_count == 1
			&& data->total_coins >= 1
			&& checkRectangle(data->map) == 1
			&& checkBorder(data->map) == 1)
		return (1);
	return (0);
}
