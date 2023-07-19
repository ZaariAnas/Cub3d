/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 06:09:08 by azari             #+#    #+#             */
/*   Updated: 2023/07/18 15:00:39 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_get_texture(t_data *mlx, t_texture *t)
{
	t->ea = mlx_load_png(mlx->txtr->ea);
	ft_raise_perror(t->ea, PNG_LOAD_ERR);
	t->we = mlx_load_png(mlx->txtr->we);
	ft_raise_perror(t->we, PNG_LOAD_ERR);
	t->so = mlx_load_png(mlx->txtr->so);
	ft_raise_perror(t->so, PNG_LOAD_ERR);
	t->no = mlx_load_png(mlx->txtr->no);
	ft_raise_perror(t->no, PNG_LOAD_ERR);
}
