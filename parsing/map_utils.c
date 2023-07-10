/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:17:02 by azari             #+#    #+#             */
/*   Updated: 2023/07/10 11:54:12 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_fill(char *line, int len)
{
	int		i;
	char	*ptr;

	i = -1;
	ptr = (char *)malloc(len * sizeof(char));
	ptr[len] = 0;
	if (!ptr)
		ft_raise_error(MEM_ALLOC_ERR);
	while (line[++i])
	{
		ptr[i] = line[i];
		len--;
	}
	ft_memset(ptr + i, ' ', len - 1);
	return (ptr);
}

void	ft_getmap(t_map *m, char *map_file, int fd)
{
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_raise_error(FILE_OPEN_ERR);
	m->map = (char **)malloc(sizeof(char *) * m->rows);
	if (!m->map)
		ft_raise_error(MEM_ALLOC_ERR);
	m->line = get_next_line(fd);
	while (m->line && m->flim--)
		m->line = get_next_line(fd);
	m->flim = 0;
	while (m->line)
	{
		m->map[m->flim] = ft_fill(m->line, m->col);
		m->line = get_next_line(fd);
		m->flim++;
	}
	m->map[m->flim++] = NULL;
}

void	check_surrounding(t_map *m, int i, int j)
{
	if (i == m->col || j == m->col || !i || !j)
		ft_raise_error(MAP_SHAPE_ERR);
	if (!ft_strchr(HOLES, m->map[i][j + 1]) || 
	!ft_strchr(HOLES, m->map[i][j - 1]) ||
	!ft_strchr(HOLES, m->map[i + 1][j]) || 
	!ft_strchr(HOLES, m->map[i - 1][j]))
		ft_raise_error(MAP_SHAPE_ERR);
}

void	ft_checkmap(t_map *m)
{
	int	i;
	int	j;

	i = -1;
	while (m->map[++i])
	{
		j = -1;
		while (m->map[i][++j])
		{
			if (ft_strchr(FREE_SPACE, m->map[i][j]))
				check_surrounding(m, i, j);
		}
	}
}
