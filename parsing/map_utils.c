/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:17:02 by azari             #+#    #+#             */
/*   Updated: 2023/07/10 10:23:44 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdlib.h>
#include <sys/fcntl.h>

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
		m->map[m->flim] = m->line;
		m->line = 
	}
}