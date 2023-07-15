/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:17:37 by mechane           #+#    #+#             */
/*   Updated: 2023/07/15 09:01:00 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>

void get_player_ang(t_player *player)
{
	if (player->side == 'N')
		player->rotate_ang = 90;
	else if (player->side == 'W')
		player->rotate_ang = 180;
	else if (player->side == 'E')
		player->rotate_ang = 0;
	else if (player->side == 'S')
		player->rotate_ang = 270;
	
}
int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}
void draw_line(t_point *p1, t_point *p2, t_mlx *mlx)
{
    double dy = p2->y - p1->y;
    double dx = p2->x - p1->x;

    double steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
    double xIncrement = dx / steps;
    double yIncrement = dy / steps;

    double x = p1->x;
    double y = p1->y;

    int i = -1;
    while (++i <= steps)
    {
		mlx_put_pixel(mlx->img, x, y,get_rgba(255, 0, 0, 255));
        x += xIncrement;
        y += yIncrement;
    }
}
void	cast_ray(t_player *player, t_mlx *mlx, double ang)
{
	t_point *s;
	t_point *h;
	t_point	*v;
	
	s = malloc(sizeof(t_point));
	s->x = player->x;
	s->y = player->y;
	h = find_hz_inter(s, to_rad(ang), mlx->map);
	v = find_vrt_inter(s, to_rad(ang), mlx->map);
	if (distance(s ,h) < distance(s, v))
		draw_line(s, h, mlx);
	else
		draw_line(s, v, mlx);
}

void	ft_render_player(t_player *player, t_mlx *mlx)
{
	double	s_ang;
	
	s_ang = player->rotate_ang - 30;
	while(s_ang <= player->rotate_ang + 30)
	{
		cast_ray(player, mlx, s_ang);
		s_ang += 0.3;
	}
}

void	ft_init_player(t_player *player)
{
	get_player_ang(player); 
	player->turn_speed = 3;
	player->walk_speed = 0.05; 
}