/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:48:35 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/21 22:53:42 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_img(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->char_image);
	mlx_destroy_image(data->mlx_ptr, data->border_image);
	mlx_destroy_image(data->mlx_ptr, data->floor_image);
	mlx_destroy_image(data->mlx_ptr, data->coin_image);
	mlx_destroy_image(data->mlx_ptr, data->exit_image);
}

void	free_array(char **array, int rows)
{
	int	i;

	i = 0;
	while (i <= rows)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
