/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:14:50 by mechane           #+#    #+#             */
/*   Updated: 2023/07/15 13:45:11 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	t(double x)
{
	return (x / TILE_SIZE);
}

t_point	*find_vrt_inter(t_point *s, double ang, t_map *map)
{
	t_point		*f;
	double		x_step;
	double		y_step;
	double		offset;

	offset = 0;
	f = ft_malloc(sizeof(t_point));
	ft_memset(f, 0, sizeof(t_point));
	f->x = ((int)(s->x / TILE_SIZE) * TILE_SIZE);
	(cos(ang) > 0) && (f->x += TILE_SIZE);
	f->y = s->y + ((f->x - s->x) * tan(ang));
	x_step = TILE_SIZE;
	(cos(ang) < 0) && (x_step = -TILE_SIZE) && (offset = -1);
	y_step = x_step * tan(ang);
	while (t(f->x) > 0 && t(f->y) > 0 && t(f->x) < map->col
		&& t(f->y) < map->rows && map->map[t(f->y)]
		&& map->map[t(f->y)][t(f->x)]
		&& map->map[t(f->y)][t(f->x + offset)] != '1')
	{
		f->x += x_step;
		f->y += y_step;
	}
	return (f);
}
