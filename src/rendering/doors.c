/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:31:15 by azari             #+#    #+#             */
/*   Updated: 2023/07/20 14:56:14 by azari            ###   ########.fr       */
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
		getoffx(mlx, h->x);
		if (h->x < mlx->w_width && h->y < mlx->w_height)
			render_wall(mlx, (cos(to_rad(ang - mlx->plr->r_ang)) * dist(s, h)), x);
	}	
	else
	{
		getoffx(mlx, v->y);
		if (h->x < mlx->w_width && h->y < mlx->w_height)
			render_wall(mlx, (cos(to_rad(ang - mlx->plr->r_ang)) * dist(s, v)), x);
	}
}

