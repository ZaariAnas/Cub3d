/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:42:49 by mechane           #+#    #+#             */
/*   Updated: 2023/07/13 10:09:13 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_moves(int keycode, t_mlx *mlx)
{
	if (keycode == 126)
	{
		mlx->map_s->p->x += 0.2;
		puts("HH");
		ft_render_map(mlx->map_s, mlx);
		ft_render_player(mlx->map_s->p, mlx);
	}
	return (0);
}