/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:37:30 by azari             #+#    #+#             */
/*   Updated: 2023/07/12 09:55:01 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// # include "mlx.h"
# define MEM_ALLOC_ERR "error : memory allocation failure"
# define MAP_TEX_ERR "error : unvalid map texture format"
# define FILE_OPEN_ERR "error : unable to open map file"
# define MAP_ELEM_ERR "error : unvalid map elements"
# define MAP_SHAPE_ERR "error : unvalid map shape"
# define MLX_INIT_ERR "error : mlx init failure"
# define RGB_ERR "error : unvalid RGB color"
# define ARG_ERR "error : unvalid arguments"
# define MAP_ELEM "NSEW10 \t\n"
# define FREE_SPACE "NSWE0"
# define RED "\033[1;31m"
# define HOLES " \t"

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <sys/fcntl.h>

typedef struct s_txtr{
	char	*NO;
	char	*WE;
	char	*EA;
	char	*SO;
	int		F;
	int		C;
}t_txtr;

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

typedef struct s_mlx{
	void	*ptr;
	void	*win;
	char	**map;
}t_mlx;

typedef struct s_coord{
	int	x;
	int	y;
}t_coord;

void	ft_getmap(t_map *m, char *map_file, int fd);
void	ft_raise_perror(void *ptr, char *err);
void	ft_raise_error(char *err_msg);
t_map	*process_map(char *map_file);
int		process_tokens(t_map *m);
int		ft_open(char *map_file);
int		ft_lencheck(char *str);
void	ft_checkmap(t_map *m);
int		ft_uatoi(char *str);
#endif