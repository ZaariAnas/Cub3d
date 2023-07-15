/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:42:49 by mechane           #+#    #+#             */
/*   Updated: 2023/07/15 16:20:02 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	right(t_data *mlx)
{
	mlx->plr->rotate_ang += mlx->plr->turn_speed;
	if (mlx->plr->rotate_ang > 360)
		mlx->plr->rotate_ang -= 360;
	if (mlx->plr->rotate_ang < 0)
		mlx->plr->rotate_ang += 360;
}

void	left(t_data *mlx)
{
	mlx->plr->rotate_ang -= mlx->plr->turn_speed;
	if (mlx->plr->rotate_ang > 360)
		mlx->plr->rotate_ang -= 360;
	if (mlx->plr->rotate_ang < 0)
		mlx->plr->rotate_ang += 360;
}

void	destroy(void *mlx)
{
	t_data	*m;

	m = (t_data *)mlx;
	mlx_terminate(m->ptr);
	exit(0);
}

void	ft_moves(void *mlx)
{
	t_data	*m;

	m = (t_data *)mlx;
	if (mlx_is_key_down(m->ptr, MLX_KEY_D))
		right(mlx);
	if (mlx_is_key_down(m->ptr, MLX_KEY_A))
		left(mlx);
	if (mlx_is_key_down(m->ptr, MLX_KEY_UP))
		move_forward(mlx);
	if (mlx_is_key_down(m->ptr, MLX_KEY_DOWN))
		move_backword(mlx);
	if (mlx_is_key_down(m->ptr, MLX_KEY_RIGHT))
		move_right(mlx);
	if (mlx_is_key_down(m->ptr, MLX_KEY_LEFT))
		move_left(mlx);
	if (mlx_is_key_down(m->ptr, MLX_KEY_ESCAPE))
		destroy(mlx);
	ft_render(mlx);
	return ;
}

void	ft_render(t_data *m)
{
	mlx_delete_image(m->ptr, m->img);
	m->img = mlx_new_image(m->ptr, (m->map->col - 1) * TILE_SIZE,
			(m->map->rows - 1) * TILE_SIZE);
	ft_render_map(m);
	ft_render_player(m);
	mlx_image_to_window(m->ptr, m->img, 0, 0);
}
