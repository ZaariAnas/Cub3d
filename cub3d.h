/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:37:30 by azari             #+#    #+#             */
/*   Updated: 2023/07/10 09:15:39 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// # include "mlx.h"
# define MAP_TEX_ERR "error : unvalid map texture format"
# define FILE_OPEN_ERR "error : unable to open map file"
# define MEM_ALLOC_ERR "error : memory allocation failure"
# define MAP_ELEM_ERR "error : unvalid map elements"
# define MAP_ELEM "NSEW10 \t\n"
# define RED "\033[1;31m"

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_map{
	char	**map; // to return a squared map for minimap
	char	**tokens;
	char	*line;
	int		rows;
	int		col;
	int		NO;
	int		EA;
	int		WE;
	int		SO;
	int		F;
	int		C;
}t_map;

void	ft_raise_error(char *err_msg);
void	process_map(char *map_file);
int		ft_lencheck(char *str);

#endif