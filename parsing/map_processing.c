/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:18:03 by azari             #+#    #+#             */
/*   Updated: 2023/07/12 09:53:49 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_parse_map(t_map *m, int fd, char *map_file)
{
	int	len;

	len = ft_lencheck(m->line);
	m->col = len;
	m->rows++;
	while (m->line)
	{
		len = ft_lencheck(m->line);
		(len > m->col) && (m->col = len);
		m->line = get_next_line(fd);
		m->rows++;
	}
	close(fd);
	m->map = malloc(sizeof(char *) * m->rows);
	if (!m->map)
		ft_raise_error(MEM_ALLOC_ERR);
	ft_getmap(m, map_file, fd);
	ft_checkmap(m);
}

t_map	*process_map(char *map_file)
{
	int		fd;
	t_map	*map;

	fd = ft_open(map_file);
	map = malloc(sizeof(t_map));
	if (!map)
		ft_raise_error(MEM_ALLOC_ERR);
	ft_memset(map, 0, sizeof(t_map));
	map->tex = malloc(sizeof(t_txtr));
	ft_memset(map->tex, 0, sizeof(t_txtr));
	map->line = get_next_line(fd);
	while (map->line)
	{
		map->flim++;
		map->tokens = ft_split_set(map->line, " \t");
		if (!process_tokens(map) && (map->tokens[0][0] != '\n'))
			break;
		map->line = get_next_line(fd);
		if(*map->line == '1' && map->flim++)
			break;
	}
	if ((map->SO & map->EA & map->NO & map->WE & map->F & map->C) != 1)
		ft_raise_error(MAP_TEX_ERR);
	ft_parse_map(map, fd, map_file);
	return (map);
}
