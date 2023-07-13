/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:42:49 by mechane           #+#    #+#             */
/*   Updated: 2023/07/13 13:46:41 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_clean_window(t_mlx *mlx)
{
		mlx_destroy_image(mlx->ptr, mlx->img);
		mlx->img = mlx_new_image(mlx->ptr, (mlx->map->col - 1) * 60 , (mlx->map->rows - 1) * 60);
    	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
            &mlx->line_length, &mlx->endian);
}
void	ft_update(t_player *player, int turn_dir)
{
	player->rotate_ang += turn_dir * player->turn_speed;
	
	
}

int	ft_moves(int keycode, t_mlx *mlx)
{
	if (keycode == 126)
	{
		ft_clean_window(mlx);
		ft_update(mlx->map->p, 1);
		ft_render_map(mlx->map, mlx);
		ft_render_player(mlx->map->p, mlx);
	}
	if (keycode == 125)
	{
		ft_clean_window(mlx);
		
		ft_render_map(mlx->map, mlx);
		ft_render_player(mlx->map->p, mlx);
	}
	if (keycode == 124)
	{
		ft_clean_window(mlx);
		
		ft_render_map(mlx->map, mlx);
		ft_render_player(mlx->map->p, mlx);
	}
	if (keycode == 123)
	{
		ft_clean_window(mlx);
		
		ft_render_map(mlx->map, mlx);
		ft_render_player(mlx->map->p, mlx);
	}
	if (keycode == 53)
		destroy(mlx);
	return (0);
}

int	destroy(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img);
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(0);
}