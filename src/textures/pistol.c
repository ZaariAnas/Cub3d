/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pistol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:41:14 by azari             #+#    #+#             */
/*   Updated: 2023/07/21 18:41:59 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static mlx_texture_t	*set_pistol(t_data *mlx)
{
	mlx_texture_t	*text;

	if (mlx->frame < 1)
		text = mlx_load_png("./assets/pi/0.png");
	else if (mlx->frame == 1)
		text = mlx_load_png("./assets/pi/1.png");
	else if (mlx->frame == 2)
		text = mlx_load_png("./assets/pi/2.png");
	else
		text = mlx_load_png("./assets/pi/3.png");
	return (text);
}

void	draw_pistol(t_data *mlx)
{
	mlx_texture_t	*text;

	text = set_pistol(mlx);
	if (mlx->torch != NULL)
		mlx_delete_image(mlx->ptr, mlx->torch);
	mlx->torch = mlx_texture_to_image(mlx->ptr, text);
	mlx_delete_texture(text);
	if (mlx_image_to_window(mlx->ptr, mlx->torch, 550, 310) == -1)
	{
		mlx_close_window(mlx->ptr);
		puts(mlx_strerror(mlx_errno));
		return ;
	}
	mlx_set_instance_depth(mlx->torch->instances, 10);
	if (mlx_is_key_down(mlx->ptr, MLX_KEY_SPACE))
		mlx->frame++;
	else
		mlx->frame = 0;
	if (mlx->frame > 3)
		mlx->frame = 0;
}
