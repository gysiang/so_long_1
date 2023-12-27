/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:52:24 by gyong-si          #+#    #+#             */
/*   Updated: 2023/12/20 19:03:30 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkfiletype(const char *filename)
{
	size_t	len = ft_strlen(filename);
	
	if (ft_strcmp(filename + len - 4, ".ber") == 0)
		return (1);
	else
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

t_data	*init_t_data()
{
	t_data	*data = malloc(sizeof(t_data));
	
	if (data == NULL)
	{
		perror("Failed to allocate memory for t_data");
		exit(EXIT_FAILURE);
	}
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->coins = 0;
	data->exit_x = 0;
	data->exit_y = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->map = malloc(sizeof(char *) * (MAX_ROWS + 1));
	return (data);
}
