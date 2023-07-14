/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:17:37 by mechane           #+#    #+#             */
/*   Updated: 2023/07/14 19:21:19 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
        my_mlx_pixel_put(mlx, x, y, 0xFF0000);
        x += xIncrement;
        y += yIncrement;
    }
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
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
	while(s_ang < player->rotate_ang + 30)
	{
		cast_ray(player, mlx, s_ang);
		s_ang += 1;
	}
}

void	ft_init_player(t_player *player)
{
	get_player_ang(player); 
	player->turn_speed = 3;
	player->walk_speed = 0.05; 
}