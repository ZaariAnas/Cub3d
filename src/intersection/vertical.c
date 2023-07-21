/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:14:50 by mechane           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/07/21 12:16:26 by azari            ###   ########.fr       */
=======
/*   Updated: 2023/07/21 13:44:44 by mechane          ###   ########.fr       */
>>>>>>> c5cea7f656d6a8fd8241f961ae5c54b01fe41bc5
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

	map->offset = 0;
	map->is_door = 0;
	f = ft_malloc(sizeof(t_point));
	ft_memset(f, 0, sizeof(t_point));
	f->x = ((int)(s->x / TILE_SIZE) * TILE_SIZE);
	(cos(ang) > 0) && (f->x += TILE_SIZE);
	f->y = s->y + ((f->x - s->x) * tan(ang));
	x_step = TILE_SIZE;
	(cos(ang) < 0) && (x_step = -TILE_SIZE) && (map->offset = -1);
	y_step = x_step * tan(ang);
	while (t(f->x) > 0 && t(f->y) > 0 && t(f->x) < map->col
		&& t(f->y) < map->rows && map->map[t(f->y)]
		&& map->map[t(f->y)][t(f->x)]
		&& !ft_strchr("1D", map->map[t(f->y)][t(f->x + map->offset)]))
	{
		f->x += x_step;
		f->y += y_step;
	}
	return (f);
}


t_point	*find_vrt_inter_door(t_point *s, double ang, t_map *map)
{
	t_point		*f;
	double		x_step;
	double		y_step;

	map->v_door = 0;
	map->offset = 0;
	f = ft_malloc(sizeof(t_point));
	ft_memset(f, 0, sizeof(t_point));
	f->x = ((int)(s->x / TILE_SIZE) * TILE_SIZE);
	(cos(ang) > 0) && (f->x += TILE_SIZE);
	f->y = s->y + ((f->x - s->x) * tan(ang));
	x_step = TILE_SIZE;
	(cos(ang) < 0) && (x_step = -TILE_SIZE) && (map->offset = -1);
	y_step = x_step * tan(ang);
	while (t(f->x) > 0 && t(f->y) > 0 && t(f->x) < map->col
		&& t(f->y) < map->rows && map->map[t(f->y)]
		&& map->map[t(f->y)][t(f->x)]
		&& !ft_strchr("1D", map->map[t(f->y)][t(f->x + map->offset)]))
	{
		f->x += x_step;
		f->y += y_step;
		if (t(f->x) > 0 && t(f->y) > 0 && t(f->x) < map->col
        && t(f->y) < map->rows && map->map[t(f->y)]
        && map->map[t(f->y)][t(f->x)]
        && ft_strchr("D", map->map[t(f->y)][t(f->x + map->offset)]))
        {
            map->v_door++;
			break;
        }
	}
	return (f);
}
