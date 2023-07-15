/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:28:42 by azari             #+#    #+#             */
/*   Updated: 2023/07/15 10:37:59 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_draw(int x, int y, t_data *mlx, int color)
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

void	ft_render_map(t_data *mlx)
{
	char	**map;
	int		x;
	int		y;
	
	map = mlx->map->map;
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


