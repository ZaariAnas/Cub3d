/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:22:34 by mechane           #+#    #+#             */
/*   Updated: 2023/07/20 14:42:20 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

double	dist(t_point *p1, t_point *p2)
{
	return (sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2)));
}

double	to_rad(double ang)
{
	return (ang * M_PI / 180.0);
}

t_point	*find_hz_inter(t_point *s, double ang, t_map *map)
{
	t_point		*f;
	double		x_step;
	double		y_step;

	map->offset = 0;
	f = ft_malloc(sizeof(t_point));
	f->y = ((int)(s->y / TILE_SIZE) * TILE_SIZE);
	(sin(ang) > 0) && (f->y += TILE_SIZE);
	f->x = s->x + ((f->y - s->y) / tan(ang));
	y_step = TILE_SIZE;
	(sin(ang) < 0) && (y_step = -TILE_SIZE) && (map->offset = -1);
	x_step = y_step / tan(ang);
	while (t(f->x) > 0 && t(f->y) > 0 && t(f->x) < map->col
		&& t(f->y) < map->rows && map->map[t(f->y)]
		&& map->map[t(f->y)][t(f->x)]
		&& !ft_strchr("1", map->map[t(f->y + map->offset)][t(f->x)]))
	{
		f->x += x_step;
		f->y += y_step;
	}
	return (f);
}

t_point	*find_hz_inter_door(t_point *s, double ang, t_map *map)
{
	t_point		*f;
	double		x_step;
	double		y_step;

	map->offset = 0;
	f = ft_malloc(sizeof(t_point));
	f->y = ((int)(s->y / TILE_SIZE) * TILE_SIZE);
	(sin(ang) > 0) && (f->y += TILE_SIZE);
	f->x = s->x + ((f->y - s->y) / tan(ang));
	y_step = TILE_SIZE;
	(sin(ang) < 0) && (y_step = -TILE_SIZE) && (map->offset = -1);
	x_step = y_step / tan(ang);
	while (t(f->x) > 0 && t(f->y) > 0 && t(f->x) < map->col
		&& t(f->y) < map->rows && map->map[t(f->y)]
		&& map->map[t(f->y)][t(f->x)]
		&& !ft_strchr("D", map->map[t(f->y + map->offset)][t(f->x)]))
	{
		f->x += x_step;
		f->y += y_step;
	}
	return (f);
}
