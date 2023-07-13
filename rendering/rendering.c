/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:28:42 by azari             #+#    #+#             */
/*   Updated: 2023/07/13 10:08:25 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}
static void	ft_draw(int x, int y, t_mlx *mlx, int color)
{
	int	i;
	int	j;

	i = x * 60 ;
	j = y * 60 ;
	while (i < (x * 60 + 59))
	{
		j = y * 60;
		while (j < (y * 60 + 59))
		{
			my_mlx_pixel_put(mlx, j, i, color);
			j++;
		}
		i++;
	}
}

void	ft_render_map(t_map *m, t_mlx *mlx)
{
	char	**map;
	int		x;
	int		y;
	
	map = m->map;
	x = 0;
	while (map[(x)])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '1')
				ft_draw(x, y, mlx, (0 << 16| 255 << 8| 255));	
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
}


