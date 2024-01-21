/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:31:05 by gyong-si          #+#    #+#             */
/*   Updated: 2024/01/20 15:54:32 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_type(int c)
{
	if (c == 7)
	{
		perror("Failed to initialise game");
	}
	if (c == 14)
	{
		perror("This Map is not valid. Please check again\n");
	}
	if (c == 21)
	{
		perror("File type must be .ber");
	}
	if (c == 42)
	{
		perror("There is no valid path to exit!");
	}
	exit(EXIT_FAILURE);
}
