/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geters.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:02:06 by azari             #+#    #+#             */
/*   Updated: 2023/07/20 11:11:28 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

uint32_t	getwidth(t_data *mlx)
{
	if (mlx->txtr->side == 'N')
		return (mlx->txtr->t_no->width);
	if (mlx->txtr->side == 'W')
		return (mlx->txtr->t_we->width);
	if (mlx->txtr->side == 'E')
		return (mlx->txtr->t_ea->width);
	if (mlx->txtr->side == 'S')
		return (mlx->txtr->t_so->width);
	return (0);
}

uint32_t	getheight(t_data *mlx)
{
	if (mlx->txtr->side == 'N')
		return (mlx->txtr->t_no->height);
	if (mlx->txtr->side == 'W')
		return (mlx->txtr->t_we->height);
	if (mlx->txtr->side == 'E')
		return (mlx->txtr->t_ea->height);
	if (mlx->txtr->side == 'S')
		return (mlx->txtr->t_so->height);
	return (0);
}

mlx_texture_t	*getside(t_data *mlx)
{
	if (mlx->txtr->side == 'N')
		return (mlx->txtr->t_no);
	if (mlx->txtr->side == 'W')
		return (mlx->txtr->t_we);
	if (mlx->txtr->side == 'E')
		return (mlx->txtr->t_ea);
	if (mlx->txtr->side == 'S')
		return (mlx->txtr->t_so);
	return (0);
}

double	get_offset(double z)
{
	return (100 - z);
}

void	getoffx(t_data *mlx, double p)
{
	if (mlx->txtr->side == 'E' || mlx->txtr->side == 'N')
		mlx->txtr->ofsx = (1 - ((fmod(p, TILE_SIZE) / TILE_SIZE)))\
			* getwidth(mlx);
	else if (mlx->txtr->side == 'S' || mlx->txtr->side == 'W')
		mlx->txtr->ofsx = ((fmod(p, TILE_SIZE) / TILE_SIZE)) * getwidth(mlx);
}
