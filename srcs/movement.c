/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:42:02 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/05 15:58:00 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data)
{
	data->prev_x = data->curr_x;
	data->prev_y = data->curr_y;
	if (data->map[data->curr_y + 1][data->curr_x] == 'C')
		data->coins_collected++;
	data->map[data->curr_y][data->curr_x] = '0';
	data->map[data->curr_y + 1][data->curr_x] = 'P';
	data->curr_y++;
	data->move_count++;
	ft_render_map_after_move(data);
}
void	move_down(t_data *data)
{
	data->prev_x = data->curr_x;
	data->prev_y = data->curr_y;
	if (data->map[data->curr_y - 1][data->curr_x] == 'C')
		data->coins_collected++;
	data->map[data->curr_y][data->curr_x] = '0';
	data->map[data->curr_y-1][data->curr_x] = 'P';
	data->curr_y--;
	data->move_count++;
	ft_render_map_after_move(data);
}
void	move_right(t_data *data)
{
	data->prev_x = data->curr_x;
	data->prev_y = data->curr_y;
	if (data->map[data->curr_y][data->curr_x+1] =='C')
		data->coins_collected++;
	data->map[data->curr_y][data->curr_x] = '0';
	data->map[data->curr_y][data->curr_x+1] = 'P';
	data->curr_x++;
	data->move_count++;
	ft_render_map_after_move(data);
}
void	move_left(t_data *data)
{
	data->prev_x = data->curr_x;
	data->prev_y = data->curr_y;
	if (data->map[data->curr_y][data->curr_x-1] == 'C')
		data->coins_collected++;
	data->map[data->curr_y][data->curr_x] = '0';
	data->map[data->curr_y][data->curr_x-1] = 'P';
	data->curr_x--;
	data->move_count++;
	ft_render_map_after_move(data);
}

