/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:18:03 by azari             #+#    #+#             */
/*   Updated: 2023/07/07 17:22:55 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	process_map(char *map_file)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		
	}
}