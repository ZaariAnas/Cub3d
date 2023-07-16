/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:26:35 by mechane           #+#    #+#             */
/*   Updated: 2023/07/16 15:54:59 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// static void	ft_draw(int x, int y, t_data *mlx, int color)
// {
// 	int	i;
// 	int	j;

// 	i = x * 3 ;
// 	j = y * 3 ;
// 	while (i < (x * 10 + 10))
// 	{
// 		j = y * 10;
// 		while (j < (y * 10 + 10))
// 		{
// 			mlx_put_pixel(mlx->img1, j, i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }
// static void	ft_draw_p(t_data *mlx, int color)
// {
// 	int	i;
// 	int	j;

// 	i = t(mlx->plr->y) * 3;
// 	while (i < t(mlx->plr->y) * 3 +3)
// 	{
// 		j = t(mlx->plr->x) * 3;
// 		while (j < t(mlx->plr->x) * 3 + 3)
// 		{
// 			mlx_put_pixel(mlx->img1, j, i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	render_mini_map(t_map *m, t_data *mlx)
// {
// 	char	**map;
// 	int		x;
// 	int		y;
	
// 	map = m->map;
// 	x = 0;
// 	while (map[(x)])
// 	{
// 		y = 0;
// 		while (map[x][y])
// 		{
// 			if (map[x][y] == '1')
// 				ft_draw(y, x, mlx, (255 << 24| 255 << 16| 255 << 8 | 255));	
// 			else
// 				ft_draw(y, x, mlx, (62 << 24| 100 << 16| 25 << 8 | 255));
// 			y++;
// 		}
// 		x++;
// 	}
// 	ft_draw_p(mlx, get_rgba(0, 0, 0, 255));
// }

// void	transfer_pixel(t_data *mlx)
// {
// 	int	x;
// 	uint8_t add;

	
// 	x = -1;
// 	while (++x < 300)
// 	{
// 		add = mlx->img1->pixels[x];
// 		ft_memset(mlx->img, add, sizeof(add));
// 	}
// }