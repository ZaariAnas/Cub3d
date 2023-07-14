/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:36:52 by azari             #+#    #+#             */
/*   Updated: 2023/07/14 13:28:34 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	mlx->ptr = mlx_init();
	ft_raise_perror(mlx->ptr, MLX_INIT_ERR);
	mlx->win = mlx_new_window(mlx->ptr, (map->col - 1)* TILE_SIZE, (map->rows - 1) * TILE_SIZE, TITLE);
	mlx->img = mlx_new_image(mlx->ptr, (map->col - 1) * TILE_SIZE , (map->rows - 1) * TILE_SIZE);
    mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
            &mlx->line_length, &mlx->endian);
	ft_raise_perror(mlx->win, MLX_WIN_ERR);
	ft_render_map(map, mlx);
	ft_init_player(map->p);
	ft_render_player(map->p, mlx);
	mlx->map = map;
	printf("success\n");
	mlx_hook(mlx->win, 02, 0, ft_moves, mlx);
	mlx_hook(mlx->win, 17, 0, destroy, mlx);
	mlx_loop(mlx->ptr);
}
