/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:17:37 by mechane           #+#    #+#             */
/*   Updated: 2023/07/16 12:08:20 by mechane          ###   ########.fr       */
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
	player->turn_speed = 1;
	player->walk_speed = 5;
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
			get_color(mlx->plr->side));
		p.x += inc.x;
		p.y += inc.y;
	}
}

void	cast_ray(t_data *mlx, double ang, int x)
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
	{
		if (cos(to_rad(ang + mlx->plr->rotate_ang)) < 0)
			mlx->plr->side = 'N';
		else
			mlx->plr->side = 'N';
		render_wall(mlx, (cos(to_rad(ang - mlx->plr->rotate_ang)) * distance(s,h)), x);
	}	
	else
	{
		if (sin(to_rad(ang + mlx->plr->rotate_ang)) > 0)
			mlx->plr->side = 'S';
		else
			mlx->plr->side = 'S';
		render_wall(mlx, (cos(to_rad(ang - mlx->plr->rotate_ang)) * distance(s,v)), x);
	}
	
}


double	adjust(double i, t_data *mlx)
{
	if (i < 0.0)
		return (0);
	if (i > mlx->w_height)
		return (mlx->w_height - 1);
	return (i);
}
void	render_wall(t_data *mlx, double dis, int x)
{
	double	prc_plane;
	double	wall_st_height;
	t_point		*s;
	t_point		*f;

	prc_plane = (mlx->w_width / 2) / tan(to_rad(30));
	wall_st_height = (TILE_SIZE / dis) * prc_plane;
	s = gc(sizeof(t_point) , 0);
	f = gc(sizeof(t_point) , 0);
	s->y = adjust((mlx->w_height / 2) - (wall_st_height / 2), mlx);
	f->y = adjust((mlx->w_height / 2) + (wall_st_height / 2), mlx);
	s->x = x;
	f->x = x;
	// printf("s_x= = %f s_y= %f  | f_x= %f  f_y= %f\n", s->x, s->y, f->x, f->y);
	draw_line(s, f, mlx);
}

void	ft_render_player(t_data *mlx)
{
	double	ang_step;
	double	cur_ang;
	int		i;

	i = -1;
	ang_step = (60.0 / mlx->w_width);
	cur_ang = mlx->plr->rotate_ang - 30;
	while (++i < mlx->w_width)
	{
		cast_ray(mlx, cur_ang, i);
		// printf("%d\n", i);
		cur_ang += ang_step;
	}
}
