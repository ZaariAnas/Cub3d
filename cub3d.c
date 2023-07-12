/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:36:52 by azari             #+#    #+#             */
/*   Updated: 2023/07/12 12:25:45 by azari            ###   ########.fr       */
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
	// int fd = open("cub3d.c", O_RDONLY);
	// printf("[%s]\n", get_next_line(fd));
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
	printf("success\n");
	mlx_loop(t->ptr);
}
