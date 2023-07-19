/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 06:09:08 by azari             #+#    #+#             */
/*   Updated: 2023/07/19 12:34:30 by azari            ###   ########.fr       */
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



