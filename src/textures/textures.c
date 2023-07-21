/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 06:09:08 by azari             #+#    #+#             */
/*   Updated: 2023/07/21 10:15:43 by mechane          ###   ########.fr       */
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
}



static mlx_texture_t	*set_text(t_data *mlx)
{
	mlx_texture_t	*txt;

	if (mlx->frame < 1)
		txt = mlx_load_png("./assets/pn/0.png");
	else if (mlx->frame < 2)
		txt = mlx_load_png("./assets/pn/1.png");
	else 
		txt = mlx_load_png("./assets/pn/2.png");
	return (txt);
}

void	draw_gun(t_data *mlx)
{
	mlx_texture_t	*text;

	text = set_text(mlx);
	if (mlx->torch != NULL)
		mlx_delete_image(mlx->ptr, mlx->torch);
	mlx->torch = mlx_texture_to_image(mlx->ptr, text);
	mlx_delete_texture(text);
	if (mlx_image_to_window(mlx->ptr, mlx->torch, 500, 627) == -1)
	{
		mlx_close_window(mlx->ptr);
		puts(mlx_strerror(mlx_errno));
		return;
	}
	mlx_set_instance_depth(mlx->torch->instances, 10);
	if (mlx_is_key_down(mlx->ptr, MLX_KEY_SPACE))
		mlx->frame++;
	else
		mlx->frame = 0;
	if (mlx->frame > 2)
		mlx->frame = 0;
}
static mlx_texture_t	*set_gun(t_data *mlx)
{
	mlx_texture_t	*text;

	if (mlx->frame < 1)
		text = mlx_load_png("./assets/pi/0.png");
	else if (mlx->frame == 1)
		text = mlx_load_png("./assets/pi/1.png");
	else if(mlx->frame == 2)
		text = mlx_load_png("./assets/pi/2.png");
	else
		text = mlx_load_png("./assets/pi/3.png");
	return (text);
}
void	draw_pistol(t_data *mlx)
{
	mlx_texture_t	*text;

	text = set_gun(mlx);
	if (mlx->torch != NULL)
		mlx_delete_image(mlx->ptr, mlx->torch);
	mlx->torch = mlx_texture_to_image(mlx->ptr, text);
	mlx_delete_texture(text);
	if (mlx_image_to_window(mlx->ptr, mlx->torch, 550, 310) == -1)
	{
		mlx_close_window(mlx->ptr);
		puts(mlx_strerror(mlx_errno));
		return;
	}
	mlx_set_instance_depth(mlx->torch->instances, 10);
	if (mlx_is_key_down(mlx->ptr, MLX_KEY_SPACE))
		mlx->frame++;
	else
		mlx->frame = 0;
	if (mlx->frame > 3)
		mlx->frame = 0;
}
static mlx_texture_t	*set_gun_1(t_data *mlx)
{
	mlx_texture_t	*text;

	if (mlx->frame < 1)
		text = mlx_load_png("./assets/gun/1.png");
	else
		text = mlx_load_png("./assets/gun/2.png");
	return (text);
}
void	draw_m_g(t_data *mlx)
{
	mlx_texture_t	*text;

	text = set_gun_1(mlx);
	if (mlx->torch != NULL)
		mlx_delete_image(mlx->ptr, mlx->torch);
	mlx->torch = mlx_texture_to_image(mlx->ptr, text);
	mlx_delete_texture(text);
	if (mlx_image_to_window(mlx->ptr, mlx->torch, 630, 738) == -1)
	{
		mlx_close_window(mlx->ptr);
		puts(mlx_strerror(mlx_errno));
		return;
	}
	mlx_set_instance_depth(mlx->torch->instances, 10);
	if (mlx_is_key_down(mlx->ptr, MLX_KEY_SPACE))
		mlx->frame++;
	else
		mlx->frame = 0;
	if (mlx->frame > 2)
		mlx->frame = 0;
}


void	key(mlx_key_data_t keydata, void* param)
{
	t_data *mlx;

	mlx = (t_data *)param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
		mlx->type++;
	if (mlx->type > 2)
		mlx->type = 0;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
		mlx->type--;
	if (mlx->type < 0)
		mlx->type = 2;
}
