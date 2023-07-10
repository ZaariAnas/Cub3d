/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:06:28 by mechane           #+#    #+#             */
/*   Updated: 2023/07/10 15:58:26 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

static int	ftt_isdigit(char *s)
{
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			s++;
		else
			return (0);
	}
	return (1);
}

int	ft_uatoi(char *str)
{
	long long		res;
	int				i;

	i = 0;
	res = 0;
	if (!*str)
		return (0);
	if (!ftt_isdigit(str))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (res > 255)
		return (-1);
	return (res);
}

int	ft_open(char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		ft_raise_error(FILE_OPEN_ERR);
	return (fd);
}