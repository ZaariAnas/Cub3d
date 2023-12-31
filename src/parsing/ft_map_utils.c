/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:15:01 by azari             #+#    #+#             */
/*   Updated: 2023/07/21 19:27:06 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_fill(char *line, int len)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)ft_malloc(len * sizeof(char));
	ptr[len - 1] = 0;
	if (!ptr)
		ft_raise_error(MEM_ALLOC_ERR);
	while (line[i] && line[i] != '\n')
	{
		ptr[i] = line[i];
		len--;
		i++;
	}
	if (len > 1)
		ft_memset(ptr + i, ' ', len - 1);
	return (ptr);
}

void	ft_getmap(t_map *m, char *map_file, int fd)
{
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_raise_error(FILE_OPEN_ERR);
	m->map = (char **)ft_malloc(sizeof(char *) * m->rows);
	if (!m->map)
		ft_raise_error(MEM_ALLOC_ERR);
	m->line = get_next_line(fd);
	m->flim--;
	while (m->line && m->flim--)
	{
		free(m->line);
		m->line = get_next_line(fd);
	}
	m->flim = 0;
	while (m->line && !ft_isempty(m->line))
	{
		m->map[m->flim] = ft_fill(m->line, m->col);
		free(m->line);
		m->line = get_next_line(fd);
		m->flim++;
	}
	m->map[m->flim++] = NULL;
	free(m->line);
	close(fd);
}

void	check_surrounding(t_map *m, int i, int j)
{
	if (i == m->rows || j == m->col || !i || !j)
		ft_raise_error(MAP_SHAPE_ERR);
	if (ft_strchr(HOLES, m->map[i][j + 1])
		|| ft_strchr(HOLES, m->map[i][j - 1])
		|| ft_strchr(HOLES, m->map[i + 1][j])
		|| ft_strchr(HOLES, m->map[i - 1][j]))
	{
		if (m->map[i][j] == 'D')
			ft_raise_error(DOOR_POS_ERR);
		ft_raise_error(MAP_SHAPE_ERR);
	}
}

static void	ft_get_player_pos(t_data *mlx, int i, int j)
{
	mlx->plr->side = mlx->map->map[i][j];
	mlx->map->map[i][j] = '0';
	mlx->plr->x = j * TILE_SIZE + (TILE_SIZE / 2.0);
	mlx->plr->y = i * TILE_SIZE + (TILE_SIZE / 2.0);
}

void	ft_checkmap(t_data *mlx)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = -1;
	while (mlx->map->map[++i])
	{
		j = -1;
		while (mlx->map->map[i][++j])
		{
			if (ft_strchr("NSEW", mlx->map->map[i][j]))
			{
				ft_get_player_pos(mlx, i, j);
				flag++;
			}
			if (ft_strchr(FREE_SPACE, mlx->map->map[i][j]))
				check_surrounding(mlx->map, i, j);
			if (mlx->map->map[i][j] == 'D')
				check_door(mlx->map, i, j);
		}
	}
	if (flag != 1)
		ft_raise_error(PLR_POS_ERR);
}
