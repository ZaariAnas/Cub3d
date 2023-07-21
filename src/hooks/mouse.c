/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 07:38:12 by mechane           #+#    #+#             */
/*   Updated: 2023/07/21 18:43:23 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	right(t_data *mlx)
{
	mlx->plr->r_ang += mlx->plr->turn_speed;
	if (mlx->plr->r_ang > 360)
		mlx->plr->r_ang -= 360;
	if (mlx->plr->r_ang < 0)
		mlx->plr->r_ang += 360;
}

void	left(t_data *mlx)
{
	mlx->plr->r_ang -= mlx->plr->turn_speed;
	if (mlx->plr->r_ang > 360)
		mlx->plr->r_ang -= 360;
	if (mlx->plr->r_ang < 0)
		mlx->plr->r_ang += 360;
}

void	destroy(void *mlx)
{
	t_data	*m;

	m = (t_data *)mlx;
	mlx_terminate(m->ptr);
	exit(0);
}

void	chose_gun(t_data *mlx)
{
	if (mlx->type == 0)
		draw_pistol(mlx);
	else if (mlx->type == 1)
		draw_m_g(mlx);
	else
		draw_punch(mlx);
}

void	mouse_rotate(t_data *mlx)
{
	int	x;
	int	y;

	mlx_get_mouse_pos(mlx->ptr, &x, &y);
	x -= mlx->w_width / 2;
	if (x < 0)
		mlx->plr->r_ang += (float)x / (mlx->w_width / 50);
	else
		mlx->plr->r_ang += (float)x / (mlx->w_width / 50);
	mlx_set_mouse_pos(mlx->ptr, mlx->w_width / 2, mlx->w_height / 2);
}
