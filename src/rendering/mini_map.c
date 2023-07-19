/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:26:35 by mechane           #+#    #+#             */
/*   Updated: 2023/07/19 17:46:59 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

double	get_offset(double z)
{
	return (100 - z);
}



static void	ft_draw(int x, int y, t_data *mlx, int color)
{
	int	i;
	int	j;
	int	i1;
	int	j1;

	i = x * 10 ;
	while (i < (x * 10 + 10))
	{
		j = y * 10 ;
		while (j < (y * 10 + 10))
		{
			i1 = i + get_offset((mlx->plr->x / TILE_SIZE) * 10);
			j1 = j + get_offset((mlx->plr->y / TILE_SIZE) * 10);
			if (j1 > 0 && i1 > 0 && j1 < 200 && i1 < 200)
			{
				int dx = i1 - 100;
				int dy = j1 - 100;
				int distance = sqrt(dx * dx + dy * dy);
				if (distance <= 98)
					mlx_put_pixel(mlx->img, j1, i1, color);
			}
			j++;
		}
		i++;
	}
}
void draw_circle(t_data *mlx,int center_x, int center_y, int radius)
{
    for (int y = 0; y < 250; ++y) {
        for (int x = 0; x < 250; ++x)
		{
            int dx = x - center_x;
            int dy = y - center_y;
            int distance = sqrt(dx * dx + dy * dy);

            if (distance < radius)
				mlx_put_pixel(mlx->img,x, y, 0);
			else if (distance >= radius && distance <= radius + 2)
				mlx_put_pixel(mlx->img,x, y, (190 << 24| 63 << 8 |120));	
        }
    }
}
void	draw_line_p(t_point *p2, t_point *p1, t_data *mlx)
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
		mlx_put_pixel(mlx->img, p.x, p.y,0);
		p.x += inc.x;
		p.y += inc.y;
	}
}
 void	ft_draw_p(t_data *mlx, int color)
{
	double	end_x;
	double	end_y;
	double	ang;

	ang = to_rad(mlx->plr->rotate_ang);
	end_x = 100 + 15 * cos(ang);
	end_y = 100 + 15 * sin(ang);
	(void)color;
	draw_line_p(&(t_point){100,100}, &(t_point){end_x, end_y}, mlx);
	draw_circle(mlx, 100, 100, 1);
}

void	render_mini_map(t_map *m, t_data *mlx)
{
	char	**map;
	int		x;
	int		y;
	
	map = m->map;
	draw_circle(mlx,100,100,100);
	x = 0;
	while (map[(x)])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '1')
				ft_draw(y , x , mlx, (255 << 24| 255 << 16| 255 << 8 | 255));	
			else
				ft_draw(y , x , mlx, (62 << 24| 100 << 16| 25 << 8 | 255));
			y++;
		}
		x++;
	}
	// draw_player(mlx, 100 , 100, mlx->plr->rotate_ang, 10);
	ft_draw_p(mlx, (255 << 24 | 255));
}

