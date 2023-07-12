/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:17:37 by mechane           #+#    #+#             */
/*   Updated: 2023/07/12 15:55:51 by mechane          ###   ########.fr       */
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
    double rad = angle * M_PI / 180.0;

    int endX = x + length * cos(rad);
    int endY = y + length * sin(rad);


    int currentX = x, currentY = y;
    while (currentX != endX || currentY != endY) 
    {
        my_mlx_pixel_put(mlx, currentX, currentY, 0xFF0000);
        double dx = endX - currentX, dy = endY - currentY;
        double dist = sqrt(dx*dx + dy*dy);
        double stepX = dx / dist, stepY = dy / dist;
        currentX += (int) round(stepX);
        currentY += (int) round(stepY);
    }
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
}
void	ft_render_player(t_player *player, t_mlx *mlx)
{
	get_player_ang(player);
	draw_line(mlx , player->x *60, player->y *60, player->rotate_ang, 10);
}