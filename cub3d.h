/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:37:30 by azari             #+#    #+#             */
/*   Updated: 2023/07/12 13:42:54 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define MEM_ALLOC_ERR "error : memory allocation failure"
# define MAP_TEX_ERR "error : unvalid map texture format"
# define FILE_OPEN_ERR "error : unable to open map file"
# define MAP_ELEM_ERR "error : unvalid map elements"
# define MAP_SHAPE_ERR "error : unvalid map shape"
# define MLX_WIN_ERR "error : mlx window failure"
# define MLX_INIT_ERR "error : mlx init failure"
# define RGB_ERR "error : unvalid RGB color"
# define ARG_ERR "error : unvalid arguments"
# define MAP_ELEM "NSEW10 \t\n"
# define FREE_SPACE "NSWE0"
# define RED "\033[1;31m"
# define HOLES " \t"
# define TITLE "Cub3d"

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <sys/fcntl.h>
# include <mlx.h>

typedef struct s_txtr{
	char	*NO;
	char	*WE;
	char	*EA;
	char	*SO;
	int		F;
	int		C;
}t_txtr;

typedef struct s_player{
	float	x;
	float	y;
	float	height;
	float	width;
	float	rotate_ang;
	float	walk_speed;
	float	turn_speed;
	int		turn_dir;
	int		walk_dir;
	char	side;
}t_player;

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
	t_player	*p;
}t_map;

typedef struct s_mlx{
	void	*ptr;
	void	*win;
	void	*img;
	char	**map;
	char    *addr;
    int        bits_per_pixel;
    int        line_length;
    int        endian;
}t_mlx;


void	ft_getmap(t_map *m, char *map_file, int fd);
void	ft_raise_perror(void *ptr, char *err);
void	ft_render_map(t_map *m, t_mlx *mlx);
void	ft_raise_error(char *err_msg);
t_map	*process_map(char *map_file);
int		process_tokens(t_map *m);
int		ft_open(char *map_file);
int		ft_lencheck(char *str);
void	ft_checkmap(t_map *m);
int		ft_uatoi(char *str);
void    my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
#endif