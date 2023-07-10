/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:06:28 by mechane           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/07/10 11:14:26 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int	ft_isdigit(const char *s)
=======
/*   Updated: 2023/07/10 13:36:10 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

static int	ftt_isdigit(char *s)
>>>>>>> 5ebec1a7db19d3768128d79deb4b30f517420f0c
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

<<<<<<< HEAD
int	ft_uatoi(const char *str)
=======
int	ft_uatoi(char *str)
>>>>>>> 5ebec1a7db19d3768128d79deb4b30f517420f0c
{
	long long		res;
	int				i;

	i = 0;
	res = 0;
	if (!*str)
		return (0);
<<<<<<< HEAD
	if (!ft_isdigit(str))
=======
	if (!ftt_isdigit(str))
>>>>>>> 5ebec1a7db19d3768128d79deb4b30f517420f0c
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