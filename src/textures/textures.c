/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 06:09:08 by azari             #+#    #+#             */
/*   Updated: 2023/07/20 10:02:18 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_get_texture(t_data *mlx)
{
	mlx->txtr->t_ea = mlx_load_png(mlx->txtr->ea);
	mlx->txtr->t_we = mlx_load_png(mlx->txtr->we);
	mlx->txtr->t_so = mlx_load_png(mlx->txtr->so);
	mlx->txtr->t_no = mlx_load_png(mlx->txtr->no);
}



static mlx_texture_t	*set_textures(t_data *mlx)
{
	mlx_texture_t	*txt;

	if (mlx->torch_frame == 0)
		txt = mlx_load_png("./assets/torch/torch.png");
	else if (mlx->torch_frame == 1)
		txt = mlx_load_png("./assets/torch/torch1.png");
	else if (mlx->torch_frame == 2)
		txt = mlx_load_png("./assets/torch/torch2.png");
	else if (mlx->torch_frame == 3)
		txt = mlx_load_png("./assets/torch/torch3.png");
	else if (mlx->torch_frame == 4)
		txt = mlx_load_png("./assets/torch/torch4.png");
	else
		txt = mlx_load_png("./assets/torch/torch5.png");
	return (txt);
}

void	draw_torch(t_data *mlx)
{
	mlx_texture_t	*txt;

	txt = set_textures(mlx);
	if (mlx->torch != NULL)
		mlx_delete_image(mlx->ptr, mlx->torch);
	mlx->torch = mlx_texture_to_image(mlx->ptr, txt);
	mlx_delete_texture(txt);
	mlx_image_to_window(mlx->ptr, mlx->torch, 0,0);
	mlx->torch->instances[0].y = -100;
	mlx->torch_frame++;
	if (mlx->torch_frame > 5)
		mlx->torch_frame = 0;
}