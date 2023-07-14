/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:18:03 by azari             #+#    #+#             */
/*   Updated: 2023/07/14 13:55:24 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_parse_map(t_map *m, int fd, char *map_file)
{
	int	len;
	int	flag;

	flag = 1;
	len = ft_lencheck(m->line);
	if (len < 3)
		ft_raise_error(UNF_MAP_ERR);
	m->col = len;
	m->rows++;
	while (m->line)
	{
		(ft_isempty(m->line) == 1) && (flag = 0);
		len = ft_lencheck(m->line);
		(len > m->col) && (m->col = len);
		m->line = get_next_line(fd);
		if (!flag && !ft_isempty(m->line))
			ft_raise_error(MAP_SHAPE_ERR);
		(flag) && (m->rows++);
	}
	close(fd);
	m->map = malloc(sizeof(char *) * m->rows);
	if (!m->map)
		ft_raise_error(MEM_ALLOC_ERR);
	ft_getmap(m, map_file, fd);
	ft_checkmap(m);
}
static t_map *ft_init(void)
{
	t_map	*m;
	
	m = malloc(sizeof(t_map));
	if (!m)
		ft_raise_error(MEM_ALLOC_ERR);
	ft_memset(m, 0, sizeof(t_map));
	m->tex = malloc(sizeof(t_txtr));
	if (!m->tex)
		ft_raise_error(MEM_ALLOC_ERR);
	ft_memset(m->tex, 0, sizeof(t_txtr));
	m->p = malloc(sizeof(t_player));
	if (!m->p)
		ft_raise_error(MEM_ALLOC_ERR);
	ft_memset(m->p, 0, sizeof(t_player));
	return (m);
}

t_map	*process_map(char *map_file)
{
	int		fd;
	t_map	*map;

	fd = ft_open(map_file);
	map = ft_init();
	map->line = get_next_line(fd);
	while (map->line)
	{
		map->flim++;
		map->tokens = ft_split_set(map->line, " \t");
		if (!process_tokens(map) && (map->tokens[0][0] != '\n'))
			break;
		map->line = get_next_line(fd);
		if(map->line && *map->line == '1' && map->flim++)
			break;
	}
	if ((map->SO & map->EA & map->NO & map->WE & map->F & map->C) != 1)
		ft_raise_error(MAP_TEX_ERR);
	ft_parse_map(map, fd, map_file);
	return (map);
}
