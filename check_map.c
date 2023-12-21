/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:29:07 by gyong-si          #+#    #+#             */
/*   Updated: 2023/12/20 19:03:16 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long_utils.h"

int	checkBorder(char **map)
{
	int	len;
	int	x;
	int	y;

	len = ft_strlen(map[0]) - 2;
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
	return (1)
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
	int y = 0;
	int	player;
	int	map_exit;

	map_exit = 0;
	player = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\n')
		{
			if (data->map[y][x] == 'C')
				data->coins += 1;
			if (data->map[y][x] == 'E')
			{
				map_exit++;
				data->exit_x = x;
				data->exit_y = y;
			}
			if (data->map[y][x] == 'P')
			{
				player++;
				data->player_x = x;
				data->player_y = y;
			}
			x++;
		}
		y++;
	}
	if (player == 1 && map_exit == 1 && data->coins >= 1 
			&& checkRectangle(map) == 1 && checkBorder(map))
		return (1);
	return (0);
}
