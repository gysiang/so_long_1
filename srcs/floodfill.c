/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:07:27 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/21 22:40:27 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validmove(t_data *data, char **array, int row, int col)
{
	return (data->map[row][col] != '1' && array[row][col] == '0');
}

void	floodfill(t_data *data, int row, int col, char **array)
{
	if (row < 0 || row >= data->td || col < 0 || col >= data->tr
		|| array[row][col] != '0')
		return ;
	if (!validmove(data, array, row, col))
		return ;
	array[row][col] = '1';
	floodfill(data, row - 1, col, array);
	floodfill(data, row + 1, col, array);
	floodfill(data, row, col - 1, array);
	floodfill(data, row, col + 1, array);
}

char	**create_array(int rows, int cols)
{
	char	**array;
	int		i;
	int		j;

	i = 0;
	array = malloc(cols * sizeof(char *));
	while (i <= rows)
	{
		array[i++] = malloc(cols * sizeof(char *));
	}
	i = 0;
	while (i <= rows)
	{
		j = 0;
		while (j < cols)
		{
			array[i][j++] = '0';
		}
		i++;
	}
	return (array);
}

int	valid_path(t_data *data)
{
	char	**array;
	int		valid_path;

	array = create_array(data->td, data->tr);
	floodfill(data, data->curr_y, data->curr_x, array);
	valid_path = (array[data->curr_y][data->curr_x] == '1'
			&& array[data->exit_y][data->exit_x] == '1');
	free_array(array, data->td);
	if (valid_path)
		return (1);
	printf("%s\n", "There is no valid path");
	return (0);
}

int	checkvalidmap(t_data *data)
{
	allocate_gamevalues(data);
	allocate_exitvalues(data);
	allocate_mapvalues(data);
	if (data->player_count == 1
		&& data->exit_count == 1
		&& data->total_coins >= 1
		&& valid_path(data) == 1
		&& checkRectangle(data->map)
		&& checkBorder(data->map)
		&& is_validated(data->map))
		return (1);
	return (0);
}

/**
 * 	// before floodfill
	i = 0;
	while (i <= data->td)
	{
		j = 0;
		while (j < data->tr)
		{
			printf("%c", array[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	floodfill(data, data->curr_y, data->curr_x, array);
	// after floodfill
	ft_printf("after floodfill\n");
	i = 0;
	while (i <= data->td)
	{
		j = 0;
		while (j < data->tr)
		{
			printf("%c", array[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
*/
