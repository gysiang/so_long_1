/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:52:24 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/21 22:49:23 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	allocate_mapvalues(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			x++;
		}
		y++;
	}
	data->tr = x -1;
	data->td = y -1;
	data->map_width = x * TILE_SIZE;
	data->map_height = y * TILE_SIZE;
}

int	checkfiletype(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (ft_strcmp(filename + len - 4, ".ber") == 0)
		return (1);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	init_t_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->char_image = NULL;
	data->exit_image = NULL;
	data->border_image = NULL;
	data->coin_image = NULL;
	data->floor_image = NULL;
	data->map = NULL;
	data->map_width = 0;
	data->map_height = 0;
	data->total_coins = 0;
	data->coins_collected = 0;
	data->exit_count = 0;
	data->player_count = 0;
	data->exit_x = 0;
	data->exit_y = 0;
	data->curr_x = 0;
	data->curr_y = 0;
	data->tr = 0;
	data->td = 0;
	data->move_count = 0;
}
