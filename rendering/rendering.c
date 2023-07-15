/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:28:42 by azari             #+#    #+#             */
/*   Updated: 2023/07/15 08:56:55 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
			mlx_put_pixel(mlx->img, j, i, color);
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
				ft_draw(x, y, mlx, (255 << 24| 255 << 16| 255 << 8 | 255));	
			y++;
		}
		x++;
	}
}


