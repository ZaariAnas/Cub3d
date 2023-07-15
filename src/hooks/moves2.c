/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:05:38 by azari             #+#    #+#             */
/*   Updated: 2023/07/15 13:08:22 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	isnt_wall(char **map, int y, int x)
{
	int	i;

	i = -1;
	while (i++ < 5)
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

void	move_forward(t_data *mlx)
{
	double	px;
	double	py;

	py = sin(to_rad(mlx->plr->rotate_ang)) * 5;
	px = cos(to_rad(mlx->plr->rotate_ang)) * 5;
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

	py = sin(to_rad(mlx->plr->rotate_ang)) * 5;
	px = cos(to_rad(mlx->plr->rotate_ang)) * 5;
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

	py = sin(to_rad(mlx->plr->rotate_ang + 90)) * 5;
	px = cos(to_rad(mlx->plr->rotate_ang + 90)) * 5;
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

	py = sin(to_rad(mlx->plr->rotate_ang + 90)) * 5;
	px = cos(to_rad(mlx->plr->rotate_ang + 90)) * 5;
	if (isnt_wall(mlx->map->map, (mlx->plr->y - py), mlx->plr->x - px))
	{
		mlx->plr->x -= px;
		mlx->plr->y -= py;
	}
}
