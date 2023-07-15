/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:42:49 by mechane           #+#    #+#             */
/*   Updated: 2023/07/14 18:49:20 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_clean_mlxow(t_mlx *mlx)
{
		mlx_destroy_image(mlx->ptr, mlx->img);
		mlx->img = mlx_new_image(mlx->ptr, (mlx->map->col - 1) * 60 , (mlx->map->rows - 1) * 60);
    	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
            &mlx->line_length, &mlx->endian);
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

int	destroy(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(0);
}
int	ft_moves(int keypress, t_mlx *mlx)
{
	if (keypress == 2)
		right(mlx);
	if (keypress == 0)
		left(mlx);
	if (keypress == 126)
		move_forward(mlx);
	if (keypress == 125)
		move_backword(mlx);
	if (keypress == 124)
		move_right(mlx);
	if (keypress == 123)
		move_left(mlx);
	if (keypress == 53)
		destroy(mlx);
	ft_clean_mlxow(mlx);
	ft_render_map(mlx->map, mlx);
	ft_render_player(mlx->map->p, mlx);
	return (0);
}
