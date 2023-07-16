/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:17:37 by mechane           #+#    #+#             */
/*   Updated: 2023/07/16 08:10:00 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_player_ang(t_player *player)
{
	if (player->side == 'N')
		player->rotate_ang = 90;
	else if (player->side == 'W')
		player->rotate_ang = 180;
	else if (player->side == 'E')
		player->rotate_ang = 0;
	else if (player->side == 'S')
		player->rotate_ang = 270;
	player->turn_speed = 2;
	player->walk_speed = 3;
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_line(t_point *p1, t_point *p2, t_data *mlx)
{
	double	steps;
	t_point	d;
	t_point	p;
	t_point	inc;

	d.y = p2->y - p1->y;
	d.x = p2->x - p1->x;
	if (fabs(d.x) > fabs(d.y))
		steps = fabs(d.x);
	else
		steps = fabs(d.y);
	inc.x = d.x / steps;
	inc.y = d.y / steps;
	p.x = p1->x;
	p.y = p1->y;
	while (steps-- >= 0)
	{
		mlx_put_pixel(mlx->img, p.x, p.y,
			get_rgba(255, 0, 0, 255));
		p.x += inc.x;
		p.y += inc.y;
	}
}

void	cast_ray(t_data *mlx, double ang)
{
	t_point	*s;
	t_point	*h;
	t_point	*v;

	s = ft_malloc(sizeof(t_point));
	s->x = mlx->plr->x;
	s->y = mlx->plr->y;
	h = find_hz_inter(s, to_rad(ang), mlx->map);
	v = find_vrt_inter(s, to_rad(ang), mlx->map);
	if (distance(s, h) < distance(s, v))
		draw_line(s, h, mlx);
	else
		draw_line(s, v, mlx);
}

void	ft_render_player(t_data *mlx)
{
	double	s_ang;

	s_ang = mlx->plr->rotate_ang - 30;
	while (s_ang <= mlx->plr->rotate_ang + 30)
	{
		cast_ray(mlx, s_ang);
		s_ang += 0.3;
	}
}
