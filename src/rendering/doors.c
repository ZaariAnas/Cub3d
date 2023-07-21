/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:31:15 by azari             #+#    #+#             */
/*   Updated: 2023/07/21 16:17:49 by mechane          ###   ########.fr       */
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
	if (dist(s, h) < dist(s, v))
	{
		(sin(to_rad(ang)) >= 0) && (mlx->txtr->side = 'N');
		(sin(to_rad(ang)) < 0) && (mlx->txtr->side = 'S');
		if (mlx->map->h_door)
		{
			(mlx->txtr->side = 'O');
			(dist(s, h) > 500) && (mlx->txtr->side = 'D');
			(dist(s, h) > 400 && dist(s, h) < 500) && (mlx->txtr->side = '1');
			(dist(s, h) > 300 && dist(s, h) < 400) && (mlx->txtr->side = '2');
			(dist(s, h) > 200 && dist(s, h) < 300) && (mlx->txtr->side = '3');
			getoffx(mlx, h->x);
			render_wall(mlx, (cos(to_rad(ang - mlx->plr->r_ang)) * dist(s, h)), x);
		}
	}	
	else
	{
		(cos(to_rad(ang)) >= 0) && (mlx->txtr->side = 'W');
		(cos(to_rad(ang)) < 0) && (mlx->txtr->side = 'E');
		if (mlx->map->v_door)
		{	
			(mlx->txtr->side = 'O');
			(dist(s, v) > 500) && (mlx->txtr->side = 'D');
			(dist(s, v) > 400 && dist(s, v) < 500) && (mlx->txtr->side = '1');
			(dist(s, v) > 300 && dist(s, v) < 400) && (mlx->txtr->side = '2');
			(dist(s, v) > 200 && dist(s, v) < 300) && (mlx->txtr->side = '3');
			getoffx(mlx, v->y);
			render_wall(mlx, (cos(to_rad(ang - mlx->plr->r_ang)) * dist(s, v)), x);
		}
	}
}
