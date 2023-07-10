/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:36:52 by azari             #+#    #+#             */
/*   Updated: 2023/07/10 09:37:39 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <sys/fcntl.h>

int main(int ac, char **av)
{
	(void)(ac);
	(void)(av);
	// int fd = open("cub3d.c", O_RDONLY);
	// printf("[%s]\n", get_next_line(fd));
	process_map(av[1]);
	printf("success\n");
}
