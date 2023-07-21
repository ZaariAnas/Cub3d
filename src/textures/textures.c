/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 06:09:08 by azari             #+#    #+#             */
/*   Updated: 2023/07/20 13:01:24 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_get_texture(t_data *mlx)
{
	mlx->txtr->t_ea = mlx_load_png(mlx->txtr->ea);
	ft_raise_perror(mlx->txtr->t_ea, PNG_LOAD_ERR);
	mlx->txtr->t_we = mlx_load_png(mlx->txtr->we);
	ft_raise_perror(mlx->txtr->t_we, PNG_LOAD_ERR);
	mlx->txtr->t_so = mlx_load_png(mlx->txtr->so);
	ft_raise_perror(mlx->txtr->t_so, PNG_LOAD_ERR);
	mlx->txtr->t_no = mlx_load_png(mlx->txtr->no);
	ft_raise_perror(mlx->txtr->t_no, PNG_LOAD_ERR);
	mlx->txtr->t_do = mlx_load_png("./assets/wall/wood.png");
	ft_raise_perror(mlx->txtr->t_do, PNG_LOAD_ERR);
}
