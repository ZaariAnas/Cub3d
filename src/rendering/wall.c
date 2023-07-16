/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 08:08:09 by mechane           #+#    #+#             */
/*   Updated: 2023/07/16 11:39:48 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	render_ceil_a_floor(t_data *mlx)
{
	int	x;
	int	y;
	
	y = -1;
	while (++y < mlx->w_height)
	{
		x = -1;
		while (++x < mlx->w_width)
		{
			if (y < mlx->w_height / 2)
				mlx_put_pixel(mlx->img, x, y, mlx->txtr->f);
			else
				mlx_put_pixel(mlx->img, x, y, mlx->txtr->c);
		}
	
	}
}
int	get_color(char dir)
{
	if (dir == 'N')
		return (get_rgba(172, 70, 23, 255));
	else if (dir == 'E')
		return (get_rgba(170, 83, 23, 255));
	else if (dir == 'S')
		return (get_rgba(174, 83, 10, 255));
	else if (dir == 'W')
		return (get_rgba(190, 83, 23, 255));
	return (0);
}