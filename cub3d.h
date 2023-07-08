/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:37:30 by azari             #+#    #+#             */
/*   Updated: 2023/07/07 17:22:11 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// # include "mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "includes/get_next_line/get_next_line.h"

typedef struct s_map{
	char	**map; // to return a squared map for minimap
	int		NO;
	int		EA;
	int		WE;
	int		SO;
	int		F;
	int		C;
}t_map;

void	process_map(char *map_file);

#endif