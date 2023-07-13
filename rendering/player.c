/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:17:37 by mechane           #+#    #+#             */
/*   Updated: 2023/07/13 10:30:29 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void get_player_ang(t_player *player)
{
	if (player->side == 'N')
		player->rotate_ang = 90;
	else if (player->side == 'W')
		player->rotate_ang = 180;
	else if (player->side == 'E')
		player->rotate_ang = 0;
	else if (player->side == 'S')
		player->rotate_ang = 270;
	
}

void draw_line(t_mlx *mlx, int x, int y, int angle, int length)
{
	t_line	l;

	l.rad = angle * M_PI / 180.0;
	l.endX = x + length * cos(l.rad);
	l.endY = y + length * sin(l.rad);
	l.currentX = x;
	l.currentY = y;
    while (l.currentX != l.endX || l.currentY != l.endY) 
    {
        my_mlx_pixel_put(mlx, l.currentX, l.currentY, 0xFF0000);
        l.dx = l.endX - l.currentX;
		l.dy = l.endY - l.currentY;
        l.dist = sqrt(l.dx * l.dx + l.dy * l.dy);
    	l.stepX = l.dx / l.dist;
		l.stepY = l.dy / l.dist;
        l.currentX += (int) round(l.stepX);
        l.currentY += (int) round(l.stepY);
    }
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
}
void	ft_render_player(t_player *player, t_mlx *mlx)
{
	get_player_ang(player);
	draw_line(mlx , player->x *60, player->y *60, player->rotate_ang, 30);
}
