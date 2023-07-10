/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:18:03 by azari             #+#    #+#             */
/*   Updated: 2023/07/10 15:42:27 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdlib.h>
#include <sys/fcntl.h>

static int	func(char **token, char *var, int *flag)
{
	if (!ft_strncmp(token[0], var, ft_strlen(token[0])) && token[1])
		return ((*flag)++, 1);
	return 0;
}

static int	process_tokens(t_map *m)
{
	int	i;
	
	i = 0;
	i+=func(m->tokens, "SO", &m->SO);
	i+=func(m->tokens, "WE", &m->WE);
	i+=func(m->tokens, "EA", &m->EA);
	i+=func(m->tokens, "NO", &m->NO);
	i+=func(m->tokens, "F", &m->F);
	i+=func(m->tokens, "C", &m->C);
	return (i);
}

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
	ft_checkmap(m->map);
}

void	process_map(char *map_file)
{
	int		fd;
	t_map	*map;

	fd = open(map_file, O_RDWR);
	if (fd == -1)
		ft_raise_error(FILE_OPEN_ERR);
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
}
