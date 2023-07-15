/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:18:03 by azari             #+#    #+#             */
/*   Updated: 2023/07/15 15:21:34 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_parse_map(t_data *mlx, int fd, char *map_file)
{
	int	len;
	int	flag;

	flag = 1;
	len = ft_lencheck(mlx->map->line);
	if (len < 3)
		ft_raise_error(UNF_MAP_ERR);
	mlx->map->col = len;
	mlx->map->rows++;
	while (mlx->map->line)
	{
		(ft_isempty(mlx->map->line) == 1) && (flag = 0);
		len = ft_lencheck(mlx->map->line);
		(len > mlx->map->col) && (mlx->map->col = len);
		mlx->map->line = get_next_line(fd);
		if (!flag && !ft_isempty(mlx->map->line))
			ft_raise_error(MAP_SHAPE_ERR);
		(flag) && (mlx->map->rows++);
	}
	close(fd);
	mlx->map->map = ft_malloc(sizeof(char *) * mlx->map->rows);
	if (!mlx->map->map)
		ft_raise_error(MEM_ALLOC_ERR);
	ft_getmap(mlx->map, map_file, fd);
	ft_checkmap(mlx);
}

static t_data	*ft_init(void)
{
	t_data	*mlx;

	mlx = ft_malloc(sizeof(t_data));
	if (!mlx)
		ft_raise_error(MEM_ALLOC_ERR);
	ft_memset(mlx, 0, sizeof(t_data));
	mlx->plr = ft_malloc(sizeof(t_player));
	if (!mlx->plr)
		ft_raise_error(MEM_ALLOC_ERR);
	ft_memset(mlx->plr, 0, sizeof(t_player));
	mlx->map = ft_malloc(sizeof(t_map));
	if (!mlx->map)
		ft_raise_error(MEM_ALLOC_ERR);
	ft_memset(mlx->map, 0, sizeof(t_map));
	mlx->txtr = ft_malloc(sizeof(t_txtr));
	if (!mlx->txtr)
		ft_raise_error(MEM_ALLOC_ERR);
	ft_memset(mlx->txtr, 0, sizeof(t_txtr));
	return (mlx);
}

t_data	*process_map(char *map_file)
{
	int		fd;
	t_map	*map;
	t_data	*mlx;

	fd = ft_open(map_file);
	mlx = ft_init();
	map = mlx->map;
	map->line = get_next_line(fd);
	while (map->line)
	{
		map->flim++;
		map->tokens = ft_split_set(map->line, " \t");
		if (!process_tokens(mlx) && (map->tokens[0][0] != '\n'))
			break ;
		map->line = get_next_line(fd);
		if (map->line && *map->line == '1' && map->flim++)
			break ;
	}
	if ((map->so & map->ea & map->no & map->we & map->f & map->c) != 1)
		ft_raise_error(MAP_TEX_ERR);
	ft_parse_map(mlx, fd, map_file);
	mlx->w_height = (mlx->map->rows - 1) * TILE_SIZE;
	mlx->w_width = (mlx->map->col - 1) * TILE_SIZE;
	return (mlx);
}
