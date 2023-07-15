/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:42:49 by mechane           #+#    #+#             */
/*   Updated: 2023/07/15 09:00:36 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_clean_mlxow(t_mlx *mlx)
{
		mlx_delete_image(mlx->ptr, mlx->img);
		mlx->img = mlx_new_image(mlx->ptr, (mlx->map->col - 1) * 60 , (mlx->map->rows - 1) * 60);
}
void	right(t_mlx *mlx)
{
	mlx->map->p->rotate_ang += 5;
	if (mlx->map->p->rotate_ang > 360)
		mlx->map->p->rotate_ang -= 360;
	if (mlx->map->p->rotate_ang < 0)
		mlx->map->p->rotate_ang += 360;
}

void	left(t_mlx *mlx)
{
	mlx->map->p->rotate_ang -= 5;
	if (mlx->map->p->rotate_ang > 360)
		mlx->map->p->rotate_ang -= 360;
	if (mlx->map->p->rotate_ang < 0)
		mlx->map->p->rotate_ang += 360;
}

void	  move_forward(t_mlx *mlx)
{
	double	px;
	double	py;

	py = sin(to_rad(mlx->map->p->rotate_ang)) * 10;
	px = cos(to_rad(mlx->map->p->rotate_ang)) * 10;
	if (mlx->map->map[(int)(mlx->map->p->y + py) / 60][(int)(mlx->map->p->x + px) / 60] == '0')
	{
		mlx->map->p->x += px;
		mlx->map->p->y += py;
	}
}

void	move_backword(t_mlx *mlx)
{
	double	px;
	double	py;


	py = sin(to_rad(mlx->map->p->rotate_ang)) * 10;
	px = cos(to_rad(mlx->map->p->rotate_ang)) * 10;
	if (mlx->map->map[(int)((mlx->map->p->y - py) / 60)][(int)(mlx->map->p->x - px) / 60] == '0')
	{
		mlx->map->p->x -= px;
		mlx->map->p->y -= py;
	}
}

void	move_right(t_mlx *mlx)
{
	double	px;
	double	py;

	py = sin(to_rad(mlx->map->p->rotate_ang + 90)) * 10;
	px = cos(to_rad(mlx->map->p->rotate_ang + 90)) * 10;
	if (mlx->map->map[(int)(mlx->map->p->y + py) / 60][(int)(mlx->map->p->x + px) / 60] == '0')
	{
		mlx->map->p->x += px;
		mlx->map->p->y += py;
	}
}

void	move_left(t_mlx *mlx)
{
	double	px;
	double	py;

	py = sin(to_rad(mlx->map->p->rotate_ang + 90)) * 10;
	px = cos(to_rad(mlx->map->p->rotate_ang + 90)) * 10;
	if (mlx->map->map[(int)(mlx->map->p->y - py) / 60][(int)(mlx->map->p->x - px) / 60] == '0')
	{
		mlx->map->p->x -= px;
		mlx->map->p->y -= py;
	}
}

void	destroy(void *mlx)
{
	t_mlx	*m;

	m = (t_mlx *)mlx;
	mlx_terminate(m->ptr);
	exit(0);
}
void	ft_moves(void *mlx)
{
	t_mlx	*m;

	m = (t_mlx *)mlx;
	if (mlx_is_key_down(m->ptr, MLX_KEY_RIGHT))
		right(mlx);
	if (mlx_is_key_down(m->ptr, MLX_KEY_LEFT))
		left(mlx);
	if (mlx_is_key_down(m->ptr, MLX_KEY_UP))
		move_forward(mlx);
	if (mlx_is_key_down(m->ptr, MLX_KEY_DOWN))
		move_backword(mlx);
	// if (keypress == 124)
	// 	move_right(mlx);
	// if (keypress == 123)
	// 	move_left(mlx);
	if (mlx_is_key_down(m->ptr, MLX_KEY_ESCAPE))
		destroy(mlx);
	mlx_delete_image(m->ptr, m->img);
	m->img = mlx_new_image(m->ptr, (m->map->rows - 1) * TILE_SIZE , (m->map->rows - 1) * TILE_SIZE);
	ft_render_map(m->map, mlx);
	ft_render_player(m->map->p, mlx);
	mlx_image_to_window(m->ptr, m->img, 0, 0);

	return ;
}
