/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:50:04 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/19 14:32:01 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


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
	while (map[0][x] != '\0')
		x++;
	if (x > y)
		return (1);
	return (0);
}
int	is_validated(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] != 'P' && map[y][x] != 'E' && map[y][x] != 'C'
				&& map[y][x] != '0' && map[y][x] != '1')
			return (0);
			x++;
		}
		y++;
	}
	return (1);
}


void	allocate_gamevalues(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	ft_printf("allocate gamevalues is called\n");
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
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
	ft_printf("allocate mapvalues is called\n");
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
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
	ft_printf("player count %d\n:", data->player_count);
	ft_printf("exit count %d\n:", data->exit_count);
	ft_printf("total coins %d\n:", data->total_coins);
	if (data->player_count == 1
			&& data->exit_count == 1
			&& data->total_coins >= 1
			&& checkRectangle(data->map)
			&& checkBorder(data->map)
			&& is_validated(data->map))
		return (1);
	return (0);
}
