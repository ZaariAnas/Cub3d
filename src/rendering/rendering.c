/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:28:42 by azari             #+#    #+#             */
/*   Updated: 2023/07/16 11:10:30 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_init_player(t_player *player)
{
	get_player_ang(player);
	player->turn_speed = 0.5;
	player->walk_speed = 1;
}

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
				ft_draw(x, y, mlx, (255 << 24 | 255 << 16 | 255 << 8 | 255));
			y++;
		}
		x++;
	}
}
