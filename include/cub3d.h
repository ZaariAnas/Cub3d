/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:37:30 by azari             #+#    #+#             */
/*   Updated: 2023/07/16 15:29:20 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define MEM_ALLOC_ERR "error : memory allocation failure"
# define MAP_TEX_ERR "error : unvalid map texture format"
# define FILE_OPEN_ERR "error : unable to open map file"
# define PLR_POS_ERR "error : unvalid player position"
# define MAP_ELEM_ERR "error : unvalid map elements"
# define MAP_SHAPE_ERR "error : unvalid map shape"
# define MLX_WIN_ERR "error : mlx window failure"
# define MLX_INIT_ERR "error : mlx init failure"
# define RGB_ERR "error : unvalid RGB color"
# define ARG_ERR "error : unvalid arguments"
# define UNF_MAP_ERR "error : map unfound"
# define MAP_ELEM "NSEW10 \t\n"
# define WHITESPACE " \t\r\v\n"
# define FREE_SPACE "NSWE0"
# define RED "\033[1;31m"
# define TITLE "Cub3d"
# define TILE_SIZE 32
# define HOLES " \t"

# include "../libs/get_next_line/get_next_line.h"
# include "../libs/libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <sys/fcntl.h>
# include "MLX42.h"
# include <math.h>
# include <stdlib.h>

typedef struct s_txtr{
	char			*no;
	char			*we;
	char			*ea;
	char			*so;
	unsigned int	f;
	unsigned int	c;
	char			side;
}t_txtr;

typedef struct s_player{
	double	x;
	double	y;
	double	height;
	double	width;
	double	rotate_ang;
	double	walk_speed;
	double	turn_speed;
	int		turn_dir;
	int		walk_dir;
	char	side;
}t_player;

typedef struct s_map{
	char		**map;
	char		**tokens;
	char		*line;
	t_txtr		*tex;
	int			flim;
	int			rows;
	int			col;
	int			no;
	int			ea;
	int			we;
	int			so;
	int			f;
	int			c;
	int			ff;
	int			cc;
}t_map;

typedef struct s_data{
	mlx_t		*ptr;
	void		*win;
	mlx_image_t	*img;
	void		*img1;
	t_map		*map;
	t_player	*plr;
	t_txtr		*txtr;
	int			w_height;
	int			w_width;
	double		mini_scale;
}t_data;

typedef struct s_point{
	double	x;
	double	y;
}t_point;

void	ft_getmap(t_map *m, char *map_file, int fd);
void	ft_raise_perror(void *ptr, char *err);
void	ft_raise_error(char *err_msg);
t_data	*process_map(char *map_file);
int		process_tokens(t_data *mlx);
int		ft_open(char *map_file);
int		ft_lencheck(char *str);
void	ft_checkmap(t_data *mlx);
int		ft_uatoi(char *str);
void	ft_moves(void *mlx);
void	ft_init_player(t_player *player);
void	destroy(void *mlx);
t_point	*find_hz_inter(t_point *s, double ang, t_map *map);
double	to_rad(double ang);
double	distance(t_point *p1, t_point *p2);
t_point	*find_vrt_inter(t_point *s, double ang, t_map *map);
int		ft_isempty(char *s);
int		t(double x);
void	ft_render_map(t_data *mlx);
void	render_walls(t_data *mlx);
bool	isnt_wall(char **map, int y, int x);
void	move_forward(t_data *mlx);
void	move_backword(t_data *mlx);
void	move_right(t_data *mlx);
void	move_left(t_data *mlx);
void	get_player_ang(t_player *player);
void	ft_render(t_data *m);
void	render_wall(t_data *mlx, double dis, int y);
int		get_color(char dir);
int		get_rgba(int r, int g, int b, int a);
void	render_ceil_a_floor(t_data *mlx);
void	render_mini_map(t_map *m, t_data *mlx);
#endif