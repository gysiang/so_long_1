/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:52:24 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/07 14:37:35 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i <= MAX_ROWS)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

t_data	*init_t_data()
{
	//int	i;
	t_data	*data = malloc(sizeof(t_data));
	if (data == NULL)
	{
		perror("Failed to allocate memory for t_data");
		exit(EXIT_FAILURE);
	}
	data->mlx_ptr = mlx_init();
	data->win_ptr = NULL;
	data->char_image = load_image('P', data->mlx_ptr);
	data->exit_image = load_image('E', data->mlx_ptr);
	data->border_image = load_image('1', data->mlx_ptr);
	data->coin_image = load_image('C', data->mlx_ptr);
	data->floor_image = load_image('0', data->mlx_ptr);
	data->map_width = 0;
	data->map_height = 0;
	data->total_coins = 0;
	data->coins_collected = 0;
	data->exit_count = 0;
	data->player_count = 0;
	// data->prev_x = 0;
	// data->prev_y = 0;
	data->curr_x = 0;
	data->curr_y = 0;
	data->tr = 0;
	data->td = 0;
	data->move_count = 0;
	//data->map = ft_split(get_next_line(fd), '\n');
	data->map = malloc(sizeof(char *) * (MAX_ROWS + 1));
	// for (int i = 0; i <= MAX_ROWS; i++) {
	// 	data->map[i] = malloc(sizeof(char) * (MAX_COLS + 1));
	// 	// Initialize the memory as needed
	// }
	return (data);
}
