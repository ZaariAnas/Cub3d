/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:42:49 by mechane           #+#    #+#             */
/*   Updated: 2023/07/15 10:16:14 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	isnt_wall(char **map, int y, int x)
{
	int	i;

	i = -1;
	while(i++ < 5)
	{
		if (map[t(y)][t(x)] == '1')
			return (0);
		if (map[t(y - i)][t(x + i)] != '0')
			return (0);
		if (map[t(y + i)][t(x - i)] != '0')
			return (0);
	}
	return (1);
}

void	right(t_mlx *mlx)
{
	mlx->map->p->rotate_ang += 3;
	if (mlx->map->p->rotate_ang > 360)
		mlx->map->p->rotate_ang -= 360;
	if (mlx->map->p->rotate_ang < 0)
		mlx->map->p->rotate_ang += 360;
}

void	left(t_mlx *mlx)
{
	mlx->map->p->rotate_ang -= 3;
	if (mlx->map->p->rotate_ang > 360)
		mlx->map->p->rotate_ang -= 360;
	if (mlx->map->p->rotate_ang < 0)
		mlx->map->p->rotate_ang += 360;
}

void	  move_forward(t_mlx *mlx)
{
	double	px;
	double	py;

	py = sin(to_rad(mlx->map->p->rotate_ang)) * 5;
	px = cos(to_rad(mlx->map->p->rotate_ang)) * 5;
	if (isnt_wall(mlx->map->map, (mlx->map->p->y + py), mlx->map->p->x + px))
	{
		mlx->map->p->x += px;
		mlx->map->p->y += py;
	}
}

void	move_backword(t_mlx *mlx)
{
	double	px;
	double	py;


	py = sin(to_rad(mlx->map->p->rotate_ang)) * 5;
	px = cos(to_rad(mlx->map->p->rotate_ang)) * 5;
	if (isnt_wall(mlx->map->map, (mlx->map->p->y - py), mlx->map->p->x - px))
	{
		mlx->map->p->x -= px;
		mlx->map->p->y -= py;
	}
}

void	move_right(t_mlx *mlx)
{
	double	px;
	double	py;

	py = sin(to_rad(mlx->map->p->rotate_ang + 90)) * 5;
	px = cos(to_rad(mlx->map->p->rotate_ang + 90)) * 5;
	if (isnt_wall(mlx->map->map, (mlx->map->p->y + py), mlx->map->p->x + px))
	{
		mlx->map->p->x += px;
		mlx->map->p->y += py;
	}
}

void	move_left(t_mlx *mlx)
{
	double	px;
	double	py;

	py = sin(to_rad(mlx->map->p->rotate_ang + 90)) * 5;
	px = cos(to_rad(mlx->map->p->rotate_ang + 90)) * 5;
	if (isnt_wall(mlx->map->map, (mlx->map->p->y - py), mlx->map->p->x - px))
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
	mlx_delete_image(m->ptr, m->img);
	m->img = mlx_new_image(m->ptr, (m->map->col - 1) * TILE_SIZE , (m->map->rows - 1) * TILE_SIZE);
	ft_render_map(m->map, mlx);
	ft_render_player(m->map->p, mlx);
	mlx_image_to_window(m->ptr, m->img, 0, 0);

	return ;
}
