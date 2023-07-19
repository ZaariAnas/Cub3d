/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:36:52 by azari             #+#    #+#             */
/*   Updated: 2023/07/18 15:00:13 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

static bool	check_args(int ac, char **av)	
{
	int	len;

	if (ac != 2)
		return (false);
	len = ft_strlen(av[1]) - 4;
	if (len < 0 || ft_strncmp(av[1] + len, ".cub", 4)
		|| open(av[1], O_RDONLY) < 0)
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_data	*mlx;

	if (!check_args(ac, av))
		ft_raise_error(ARG_ERR);
	mlx = process_map(av[1]);
	printf("[%d]\n", mlx->tex->no->height);
	printf("[%d]\n", mlx->tex->no->width);
	printf("[%d]\n", mlx->tex->no->bytes_per_pixel);
	printf("[%d]\n", mlx->tex->no->pixels[0]);
	printf("[%d]\n", mlx->tex->no->pixels[1]);
	printf("[%d]\n", mlx->tex->no->pixels[2]);
	printf("[%d]\n", mlx->tex->no->pixels[3]);
	printf("[%d]\n", mlx->tex->no->pixels[4]);
	mlx->ptr = mlx_init(mlx->w_width, mlx->w_height, TITLE, false);
	ft_raise_perror(mlx->ptr, MLX_INIT_ERR);
	mlx->img = mlx_new_image(mlx->ptr, mlx->w_height, mlx->w_height);
	ft_raise_perror(mlx->img, MLX_INIT_ERR);
	mlx_loop_hook(mlx->ptr, ft_moves, mlx);
	mlx_loop(mlx->ptr);
}
