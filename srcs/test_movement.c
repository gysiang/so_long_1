/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:47:01 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/05 13:42:21 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moveup_test(t_data *data)
{
	if (data->map[data->curr_y+1][data->curr_x] == '1')
		return (1);
	return (0);
}

int	movedown_test(t_data *data)
{
	if (data->map[data->curr_y-1][data->curr_x] == '1')
		return (1);
	return (0);
}

int moveright_test(t_data *data)
{
	if (data->map[data->curr_y][data->curr_x+1] == '1')
		return (1);
	return (0);
}

int moveleft_test(t_data *data)
{
	if (data->map[data->curr_y][data->curr_x-1] == '1')
		return (1);
	return (0);
}
