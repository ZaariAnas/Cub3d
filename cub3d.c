/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:36:52 by azari             #+#    #+#             */
/*   Updated: 2023/07/12 09:55:33 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	// t_mlx	*t;

	if (!check_args(ac, av))
		ft_raise_error(ARG_ERR);
	// int fd = open("cub3d.c", O_RDONLY);
	// printf("[%s]\n", get_next_line(fd));
	map = process_map(av[1]);
	// t.mlx=mlx_init();
	// ft_raise_perror(t.mlx, MLX_INIT_ERR)
	// t.win = mlx_new_win
	printf("success\n");
}
