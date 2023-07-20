/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 07:38:12 by mechane           #+#    #+#             */
/*   Updated: 2023/07/20 09:16:00 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	mouse_rotate(t_data *mlx)
{
	int	x;
	int	y;

	mlx_get_mouse_pos(mlx->ptr, &x, &y);
	x -= mlx->w_width/ 2;
	if (x < 0)
		mlx->plr->r_ang += (float)x / (mlx->w_width / 50 );
	else
		mlx->plr->r_ang += (float)x / (mlx->w_width/ 50 );
	mlx_set_mouse_pos(mlx->ptr, mlx->w_width / 2, mlx->w_height / 2);
}