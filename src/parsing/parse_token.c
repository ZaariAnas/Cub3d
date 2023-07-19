/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:36:45 by mechane           #+#    #+#             */
/*   Updated: 2023/07/18 15:01:00 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_check_token(char *token)
{
	char	*r;
	int		flag;

	flag = -2;
	r = ft_strchr(token, ',');
	if (r && r != token && ft_isdigit(*(r + 1)) && ft_isdigit(*(r - 1)))
		flag++;
	r = ft_strrchr(token, ',');
	if (r && r != token && ft_isdigit(*(r + 1)) && ft_isdigit(*(r - 1)))
		flag++;
	if (!flag)
		return (1);
	return (0);
}

static void	get_rgb(t_data *mlx)
{
	char	**tmp;
	char	*s;
	int		i;

	s = NULL;
	i = -0;
	while (mlx->map->tokens[++i])
		s = ft_strjoin(s, mlx->map->tokens[i]);
	if (!ft_check_token(s))
		ft_raise_error(RGB_ERR);
	i = -1;
	tmp = ft_split_set(s, " \t,\n");
	while (tmp[++i])
	{
		if (ft_uatoi(tmp[i]) == -1)
			ft_raise_error(RGB_ERR);
		if (!ft_strncmp(mlx->map->tokens[0], "C",
				ft_strlen(mlx->map->tokens[0])))
			mlx->txtr->c += (ft_uatoi(tmp[i]) << (24 - (8 * i)) | 255);
		else
			mlx->txtr->f += (ft_uatoi(tmp[i]) << (24 - (8 * i)) | 255);
	}
	if (i != 3)
		ft_raise_error(RGB_ERR);
}

static bool	if_valid(char *token, t_map *m, t_data *mlx)
{
	if (!token)
		return (false);
	if (!ft_strncmp(m->tokens[0], "F", ft_strlen(m->tokens[0]))
		|| !ft_strncmp(m->tokens[0], "C", ft_strlen(m->tokens[0])))
		get_rgb(mlx);
	else if (m->tokens[2] && m->tokens[2][0] != '\n')
		return (false);
	return (true);
}

static int	func(t_map *m, char *var, int *flag, t_data *mlx)
{
	if (!ft_strncmp(m->tokens[0], var,
			ft_strlen(m->tokens[0])) && if_valid(m->tokens[1], mlx->map, mlx))
		return ((*flag)++, 1);
	return (0);
}

int	process_tokens(t_data *mlx)
{
	int	i;

	i = 0;
	(func(mlx->map, "SO", &mlx->map->so, mlx))
		&& (mlx->txtr->so = ft_strtrim(mlx->map->tokens[1], WHITESPACE), i += 1);
	(func(mlx->map, "WE", &mlx->map->we, mlx))
		&& (mlx->txtr->we = ft_strtrim(mlx->map->tokens[1], WHITESPACE), i += 1);
	(func(mlx->map, "EA", &mlx->map->ea, mlx))
		&& (mlx->txtr->ea = ft_strtrim(mlx->map->tokens[1], WHITESPACE), i += 1);
	(func(mlx->map, "NO", &mlx->map->no, mlx))
		&& (mlx->txtr->no = ft_strtrim(mlx->map->tokens[1], WHITESPACE), i += 1);
	(func(mlx->map, "F", &mlx->map->f, mlx)) && (i += 1);
	(func(mlx->map, "C", &mlx->map->c, mlx)) && (i += 1);
	return (i);
}
