/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:37:30 by azari             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/07/10 12:47:41 by mechane          ###   ########.fr       */
=======
/*   Updated: 2023/07/10 13:49:47 by mechane          ###   ########.fr       */
>>>>>>> 5ebec1a7db19d3768128d79deb4b30f517420f0c
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// # include "mlx.h"
# define MAP_TEX_ERR "error : unvalid map texture format"
# define FILE_OPEN_ERR "error : unable to open map file"
# define MEM_ALLOC_ERR "error : memory allocation failure"
# define MAP_SHAPE_ERR "error : unvalid map shape"
# define MAP_ELEM_ERR "error : unvalid map elements"
# define ARG_ERR "error : unvalid argumentS"
# define RGB_ERR "error : unvalid RGB color"
# define MAP_ELEM "NSEW10 \t\n"
# define FREE_SPACE "NSWE0"
# define HOLES " \t"
# define RED "\033[1;31m"
# define ARG_ERR "error : unvalid argument !!"

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <sys/fcntl.h>
<<<<<<< HEAD
=======

typedef struct s_txtr{
	char	*NO;
	char	*WE;
	char	*EA;
	char	*SO;
	int		F;
	int		C;
}t_txtr;
>>>>>>> 5ebec1a7db19d3768128d79deb4b30f517420f0c

typedef struct s_map{
	char	**map; // to return a squared map for minimap
	char	**tokens;
	char	*line;
	t_txtr	*tex;
	int		flim;
	int		rows;
	int		col;
	int		NO;
	int		EA;
	int		WE;
	int		SO;
	int		F;
	int		C;
	int		FF;
	int		CC;
	
}t_map;

void	ft_getmap(t_map *m, char *map_file, int fd);
void	ft_raise_error(char *err_msg);
void	process_map(char *map_file);
int		ft_lencheck(char *str);
<<<<<<< HEAD
int		ft_uatoi(const char *str);
int		process_tokens(t_map *m);
=======
void	ft_checkmap(t_map *m);
int		ft_uatoi(char *str);
int		process_tokens(t_map *m);

>>>>>>> 5ebec1a7db19d3768128d79deb4b30f517420f0c
#endif