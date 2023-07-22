/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geters.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:02:06 by azari             #+#    #+#             */
/*   Updated: 2023/07/21 18:32:59 by azari            ###   ########.fr       */
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
	if (mlx->txtr->side == 'D')
		return (mlx->txtr->t_do->width);
	if (mlx->txtr->side == 'O')
		return (mlx->txtr->t_dc->width);
	if (mlx->txtr->side == '1')
		return (mlx->txtr->t_d1->width);
	if (mlx->txtr->side == '2')
		return (mlx->txtr->t_d2->width);
	if (mlx->txtr->side == '3')
		return (mlx->txtr->t_d3->width);
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
	if (mlx->txtr->side == 'D')
		return (mlx->txtr->t_do->height);
	if (mlx->txtr->side == 'O')
		return (mlx->txtr->t_dc->height);
	if (mlx->txtr->side == '1')
		return (mlx->txtr->t_d1->height);
	if (mlx->txtr->side == '2')
		return (mlx->txtr->t_d2->height);
	if (mlx->txtr->side == '3')
		return (mlx->txtr->t_d3->height);
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
	if (mlx->txtr->side == 'D')
		return (mlx->txtr->t_do);
	if (mlx->txtr->side == 'O')
		return (mlx->txtr->t_dc);
	if (mlx->txtr->side == '1')
		return (mlx->txtr->t_d1);
	if (mlx->txtr->side == '2')
		return (mlx->txtr->t_d2);
	if (mlx->txtr->side == '3')
		return (mlx->txtr->t_d3);
	return (0);
}

double	get_offset(double z)
{
	return (100 - z);
}

void	getoffx(t_data *mlx, double p)
{
	if (ft_strchr("ENO1D23", mlx->txtr->side))
		mlx->txtr->ofsx = (1 - ((fmod(p, TILE_SIZE) / TILE_SIZE))) \
			* getwidth(mlx);
	else if (ft_strchr("WS", mlx->txtr->side))
		mlx->txtr->ofsx = ((fmod(p, TILE_SIZE) / TILE_SIZE)) * getwidth(mlx);
}
