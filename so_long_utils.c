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

#include "includes/so_long_utils.h"

void	open_map(const char *filename, char **array)
{
	int		fd;
	int		i;
	char	*line

	i = 0;
	fd = open(filename, 0_RDONLY, 0666);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		array[i] = ft_strdup(line);
		printf("%s", array[i]);
		free(line);
		i++;
	}
	close(fd);
}

int	checkfiletype(const char *filename)
{
	size_t	len = ft_strlen(filename);
	
	if (ft_strcmp(filename + len - 4, ".ber") == 0)
		return (1);
	else
		return (0);
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
