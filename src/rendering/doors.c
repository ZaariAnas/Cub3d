/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:31:15 by azari             #+#    #+#             */
/*   Updated: 2023/07/21 18:29:02 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	render_doors(t_data *mlx)
{
	double	ang_step;
	double	cur_ang;
	int		i;

	i = -1;
	ang_step = (60.0 / mlx->w_width);
	cur_ang = mlx->plr->r_ang - 30;
	while (++i < mlx->w_width)
	{
		cast_door_rays(mlx, cur_ang, i);
		cur_ang += ang_step;
	}
}

void	ft_set_door(t_data *mlx, double dist, double p)
{
	(mlx->txtr->side = 'O');
	(dist > 500) && (mlx->txtr->side = 'D');
	(dist > 400 && dist < 500) && (mlx->txtr->side = '1');
	(dist > 300 && dist < 400) && (mlx->txtr->side = '2');
	(dist > 200 && dist < 300) && (mlx->txtr->side = '3');
	getoffx(mlx, p);
}

void	cast_door_rays(t_data *mlx, double ang, int x)
{
	t_point	*s;
	t_point	*h;
	t_point	*v;

	s = ft_malloc(sizeof(t_point));
	s->x = mlx->plr->x;
	s->y = mlx->plr->y;
	h = find_hz_inter_door(s, to_rad(ang), mlx->map);
	v = find_vrt_inter_door(s, to_rad(ang), mlx->map);
	if (dist(s, h) < dist(s, v) && mlx->map->h_door)
	{
		ft_set_door(mlx, dist(s, h), h->x);
		render_wall(mlx, (cos(to_rad(ang - mlx->plr->r_ang)) * dist(s, h)), x);
	}	
	else if (dist(s, h) >= dist(s, v) && mlx->map->v_door)
	{
		ft_set_door(mlx, dist(s, v), v->y);
		render_wall(mlx, (cos(to_rad(ang - mlx->plr->r_ang)) * dist(s, v)), x);
	}
}
