/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:36:52 by azari             #+#    #+#             */
/*   Updated: 2023/07/10 10:52:18 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_args(int ac, char **av)
{
	int	len;

	if (ac != 2)
		return (false);
	len = ft_strlen(av[1]) - 4;
	if (len < 1 || ft_strncmp(av[1] + len , ".cub", 4)
		|| open(av[1], O_RDONLY) < 0)
		return (false);
	return (true);
}

int main(int ac, char **av)
{
	if (!check_args(ac, av))
		return (printf("%s\n", ARG_ERR));
	// int fd = open("cub3d.c", O_RDONLY);
	// printf("[%s]\n", get_next_line(fd));
	// process_map(av[1]);
	printf("success\n");
}
