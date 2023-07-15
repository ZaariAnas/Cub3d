/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:36:52 by azari             #+#    #+#             */
/*   Updated: 2023/07/15 08:21:54 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdbool.h>

static bool	check_args(int ac, char **av)
{
	int	len;

	if (ac != 2)
		return (false);
	len = ft_strlen(av[1]) - 4;
	if (len < 0 || ft_strncmp(av[1] + len , ".cub", 4)
		|| open(av[1], O_RDONLY) < 0)
		return (false);
	return (true);
}

int main(int ac, char **av)
{
	t_map	*map;
	t_mlx	*mlx;

	if (!check_args(ac, av))
		ft_raise_error(ARG_ERR);
	mlx = malloc(sizeof(t_mlx));
	ft_memset(mlx, 0, sizeof(t_mlx));
	map = process_map(av[1]);
	mlx->map = map;
	mlx->ptr = mlx_init((map->col - 1)* TILE_SIZE, (map->rows - 1) * TILE_SIZE, TITLE, false);
	ft_raise_perror(mlx->ptr, MLX_INIT_ERR);
	mlx->img = mlx_new_image(mlx->ptr, (map->rows - 1) * TILE_SIZE , (map->rows - 1) * TILE_SIZE);
	ft_render_map(map, mlx);
	ft_init_player(map->p);
	ft_render_player(map->p, mlx);
	mlx_loop_hook(mlx->ptr, ft_moves, mlx);
	mlx_loop(mlx->ptr);
}
