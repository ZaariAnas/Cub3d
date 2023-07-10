/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:17:02 by azari             #+#    #+#             */
/*   Updated: 2023/07/10 09:21:17 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_fill(char *line, int len)
{
	int		i;
	char	*ptr;

	i = -1;
	ptr = (char *)malloc(len * sizeof(char));
	if (!ptr)
		ft_raise_error(MEM_ALLOC_ERR);
	while (line[++i])
	{
		ptr[i] = line[i];
		len--;
	}
	while (len)
	{
		
	}
}