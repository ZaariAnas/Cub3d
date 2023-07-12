/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:28:42 by azari             #+#    #+#             */
/*   Updated: 2023/07/12 12:26:12 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}
static void	ft_draw(t_coord *o, t_mlx *mlx)
{
	int	i;
	int	j;

	i = o->x *60;
	j = o->y *60;
	while (i < (o->x*60 + 60))
	{
		j = o->y *60;
		while (j < (o->y*60 + 60))
		{
			my_mlx_pixel_put(mlx, j, i, 255);
			j++;
		}
		i++;
	}
}

void	ft_render_map(t_map *m, t_mlx *mlx)
{
	t_coord	*w;
	char	**map;

	w = malloc(sizeof(t_coord));
	ft_memset(w, 0, sizeof(t_coord));
	w->x = 0;
	map = m->map;
	while (map[(w->x)])
	{
		w->y = 0;
		while (map[w->x][w->y])
		{
			if (map[w->x][w->y] == '1')
				ft_draw(w, mlx);
			w->y++;
		}
		w->x++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
}


