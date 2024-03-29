/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:47:01 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/21 22:42:17 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	moveup_test(t_data *data)
{
	if (data->curr_y -1 == 0)
		return (1);
	if (data->map[data->curr_y -1][data->curr_x] == '1')
		return (1);
	return (0);
}

int	movedown_test(t_data *data)
{
	if (data->curr_y +1 == data->td)
		return (1);
	if (data->map[data->curr_y +1][data->curr_x] == '1')
		return (1);
	return (0);
}

int	moveright_test(t_data *data)
{
	if (data->curr_x +1 == data->tr)
		return (1);
	if (data->map[data->curr_y][data->curr_x +1] == '1')
		return (1);
	return (0);
}

int	moveleft_test(t_data *data)
{
	if (data->curr_x -1 == 0)
		return (1);
	if (data->map[data->curr_y][data->curr_x -1] == '1')
		return (1);
	return (0);
}
