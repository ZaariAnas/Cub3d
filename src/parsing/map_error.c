/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:58:40 by azari             #+#    #+#             */
/*   Updated: 2023/07/21 19:28:11 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_lencheck(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
	{
		if (!ft_strchr(MAP_ELEM, str[i]))
			ft_raise_error(MAP_ELEM_ERR);
	}
	return (i);
}

void	ft_raise_error(char *err_msg)
{
	printf("%s%s\n", RED, err_msg);
	exit(1);
}

void	ft_raise_perror(void *ptr, char *err)
{
	if (!ptr)
	{
		printf("%s%s\n", RED, err);
		exit(1);
	}
}

void	check_door(t_map *m, int i, int j)
{
	if (i == m->rows || j == m->col || !i || !j)
		ft_raise_error(DOOR_POS_ERR);
	if (!((m->map[i][j + 1] == '1' && m->map[i][j - 1] == '1')
		|| (m->map[i + 1][j] == '1' && m->map[i - 1][j] == '1')))
		ft_raise_error(DOOR_POS_ERR);
}
