/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:42:49 by mechane           #+#    #+#             */
/*   Updated: 2023/07/13 10:54:17 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_moves(int keycode, t_mlx *mlx)
{
	if (keycode == 126)
	{
		mlx->map->p->y -= mlx->map->p->walk_speed;
		mlx_destroy_image(mlx->ptr, mlx->img);
		mlx->img = mlx_new_image(mlx->ptr, (mlx->map->col - 1) * 60 , (mlx->map->rows - 1) * 60);
    	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
            &mlx->line_length, &mlx->endian);
		ft_render_map(mlx->map, mlx);
		ft_render_player(mlx->map->p, mlx);
	}
	if (keycode == 125)
	{
		mlx->map->p->y += mlx->map->p->walk_speed;
		mlx_destroy_image(mlx->ptr, mlx->img);
		mlx->img = mlx_new_image(mlx->ptr, (mlx->map->col - 1) * 60 , (mlx->map->rows - 1) * 60);
    	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
            &mlx->line_length, &mlx->endian);
		ft_render_map(mlx->map, mlx);
		ft_render_player(mlx->map->p, mlx);
	}
	if (keycode == 124)
	{
		mlx->map->p->rotate_ang += mlx->map->p->turn_speed;
		mlx_destroy_image(mlx->ptr, mlx->img);
		mlx->img = mlx_new_image(mlx->ptr, (mlx->map->col - 1) * 60 , (mlx->map->rows - 1) * 60);
    	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
            &mlx->line_length, &mlx->endian);
		ft_render_map(mlx->map, mlx);
		ft_render_player(mlx->map->p, mlx);
	}
	if (keycode == 123)
	{
		mlx->map->p->rotate_ang -= mlx->map->p->turn_speed;
		mlx_destroy_image(mlx->ptr, mlx->img);
		mlx->img = mlx_new_image(mlx->ptr, (mlx->map->col - 1) * 60 , (mlx->map->rows - 1) * 60);
    	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
            &mlx->line_length, &mlx->endian);
		ft_render_map(mlx->map, mlx);
		ft_render_player(mlx->map->p, mlx);
	}
	return (0);
}