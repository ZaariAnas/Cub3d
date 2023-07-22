/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:35:49 by azari             #+#    #+#             */
/*   Updated: 2023/07/22 05:37:42 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	key(mlx_key_data_t keydata, void *param)
{
	t_data	*mlx;

	mlx = (t_data *)param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
		mlx->type++;
	if (mlx->type > 2)
		mlx->type = 0;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
		mlx->type--;
	if (mlx->type < 0)
		mlx->type = 2;
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_RELEASE)
		mlx->r_mouse = !mlx->r_mouse;
}
