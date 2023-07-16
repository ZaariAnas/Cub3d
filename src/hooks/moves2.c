/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:26:37 by mechane           #+#    #+#             */
/*   Updated: 2023/07/16 13:12:46 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	isnt_wall(char **map, int y, int x)
{
	int	i;

	i = -1;
	while (i++ < 3)
	{
		if (map[t(y + i)][t(x + i)] == '1')
			return (0);
		if (map[t(y)][t(x + i)] == '1')
			return (0);
		if (map[t(y - i)][t(x)] == '1')
			return (0);
	}
	return (1);
}

void	move_forward(t_data *mlx)
{
	double	px;
	double	py;

	py = sin(to_rad(mlx->plr->rotate_ang)) * mlx->plr->walk_speed;
	px = cos(to_rad(mlx->plr->rotate_ang)) * mlx->plr->walk_speed;
	if (isnt_wall(mlx->map->map, (mlx->plr->y + py), mlx->plr->x + px))
	{
		mlx->plr->x += px;
		mlx->plr->y += py;
	}
}

void	move_backword(t_data *mlx)
{
	double	px;
	double	py;

	py = sin(to_rad(mlx->plr->rotate_ang)) * mlx->plr->walk_speed;
	px = cos(to_rad(mlx->plr->rotate_ang)) * mlx->plr->walk_speed;
	if (isnt_wall(mlx->map->map, (mlx->plr->y - py), mlx->plr->x - px))
	{
		mlx->plr->x -= px;
		mlx->plr->y -= py;
	}
}

void	move_right(t_data *mlx)
{
	double	px;
	double	py;

	py = sin(to_rad(mlx->plr->rotate_ang + 90)) * mlx->plr->walk_speed;
	px = cos(to_rad(mlx->plr->rotate_ang + 90)) * mlx->plr->walk_speed;
	if (isnt_wall(mlx->map->map, (mlx->plr->y + py), mlx->plr->x + px))
	{
		mlx->plr->x += px;
		mlx->plr->y += py;
	}
}

void	move_left(t_data *mlx)
{
	double	px;
	double	py;

	py = sin(to_rad(mlx->plr->rotate_ang + 90)) * mlx->plr->walk_speed;
	px = cos(to_rad(mlx->plr->rotate_ang + 90)) * mlx->plr->walk_speed;
	if (isnt_wall(mlx->map->map, (mlx->plr->y - py), mlx->plr->x - px))
	{
		mlx->plr->x -= px;
		mlx->plr->y -= py;
	}
}
