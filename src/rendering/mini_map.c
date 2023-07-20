/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:26:35 by mechane           #+#    #+#             */
/*   Updated: 2023/07/20 08:47:32 by mechane          ###   ########.fr       */
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
	int	distance;

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
				distance = sqrt(pow(i1 - 100, 2) + pow(j1 -100, 2));
				if (distance <= 96)
					mlx_put_pixel(mlx->img, j1, i1, color);
			}
			j++;
		}
		i++;
	}
}
static void draw_circle(t_data *mlx,int center_x, int center_y, int radius)
{
    int	x;
	int	y;
	int	dx;
	int	dy;
	int	distance;
	
	y = -1;
	while (++y < 200)
	{
        x = -1;
		while(++x < 200)
		{
			dx = x - center_x;
			dy = y - center_y;
			distance = sqrt(dx * dx + dy * dy);
			if (distance <= radius)
				mlx_put_pixel(mlx->img,x, y, 0);	
		}
	}
}
 static void	ft_draw_p(t_data *mlx)
{
	double	end_x;
	double	end_y;
	double	ang;

	ang = to_rad(mlx->plr->r_ang);
	end_y = 100.0 + 2.0 * cos(ang);
	end_x = 100.0 + 2.0 * sin(ang);
	draw_circle(mlx, 100, 100, 5);
	mlx_put_pixel(mlx->img, end_x, end_y,(255 << 24 | 255 << 16|255<< 8|255));
	mlx_put_pixel(mlx->img, end_x + sin(ang), end_y + cos(ang),(255 << 24 | 255 << 16|255<< 8|255));
	mlx_put_pixel(mlx->img, end_x + 2*sin(ang), end_y + 2*cos(ang),(255 << 24 | 255 << 16|255<< 8|255));
}

void	draw_star(t_data *mlx, int color)
{
	int			x;
	int			y;
	float		angle;

	angle = (float)M_PI / 180 * -1;
	while (angle <= (float)M_PI * 2)
	{
		angle += (float)M_PI / 180;
		x = mlx->w_width / 2 + 1 * roundf(cos(angle));
		y = mlx->w_height / 2 + 1 * roundf(sin(angle));
		mlx_put_pixel(mlx->img, x, y, color);
		x = mlx->w_width / 2 + 2 * roundf(cos(angle));
		y = mlx->w_height / 2 + 2 * roundf(sin(angle));
		mlx_put_pixel(mlx->img, x, y, color);
		x = mlx->w_width / 2 + 3 * roundf(cos(angle));
		y = mlx->w_height / 2 + 3 * roundf(sin(angle));
		mlx_put_pixel(mlx->img, x, y, color);
	}
}

void	render_mini_map(t_map *m, t_data *mlx)
{
	char	**map;
	int		x;
	int		y;
	
	map = m->map;
	draw_circle(mlx,100,100, 96);
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
	ft_draw_p(mlx);
	draw_star(mlx, get_rgba(255,255,255,255));
}

