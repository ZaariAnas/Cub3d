/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:36:52 by azari             #+#    #+#             */
/*   Updated: 2023/07/13 10:20:16 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"

static bool	check_args(int ac, char **av)
{
	int	len;

	if (ac != 2)
		return (false);
	len = ft_strlen(av[1]) - 4;
	if (len < 0 || ft_strncmp(av[1] + len , ".cub", 4)
		|| open(av[1], O_RDONLY) < 0)
		return (false);
	return (true);
}

int main(int ac, char **av)
{
	t_map	*map;
	t_mlx	*t;

	if (!check_args(ac, av))
		ft_raise_error(ARG_ERR);
	t = malloc(sizeof(t_mlx));
	ft_memset(t, 0, sizeof(t_mlx));
	map = process_map(av[1]);
	t->ptr = mlx_init();
	ft_raise_perror(t->ptr, MLX_INIT_ERR);
	t->win = mlx_new_window(t->ptr, (map->col - 1)* 60, (map->rows - 1) * 60, TITLE);
	t->img = mlx_new_image(t->ptr, (map->col - 1) * 60 , (map->rows - 1) * 60);
    t->addr = mlx_get_data_addr(t->img, &t->bits_per_pixel,
            &t->line_length, &t->endian);
	ft_raise_perror(t->win, MLX_WIN_ERR);
	ft_render_map(map, t);
	ft_render_player(map->p, t);
	t->map = map;
	printf("success\n");
	mlx_hook(t->win, 02, 0, ft_moves, t);
	mlx_loop(t->ptr);
}
