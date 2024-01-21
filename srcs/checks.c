/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:50:04 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/21 22:49:51 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	checkborder(char **map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[y] != NULL)
		y++;
	while (map[0][x] != '\n' && map[y -1][x] != '\0')
	{
		if (map[0][x] != '1' || map[y -1][x] != '1')
			return (0);
		x++;
	}
	x = 0;
	while (map[x] && map[y -1][x] != '\0')
	{
		if (map[0][x] != '1' || map[y -1][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	checkrectangle(char **map)
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
			{
				return (0);
			}
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
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == 'C')
				data->total_coins++;
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

void	allocate_exitvalues(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == 'E')
			{
				data->exit_count++;
				data->exit_y = y;
				data->exit_x = x;
			}
			x++;
		}
		y++;
	}
}
