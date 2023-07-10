/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:14:49 by azari             #+#    #+#             */
/*   Updated: 2022/10/14 16:00:01 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *hay, int c)
{
	int	i;

	i = ft_strlen(hay);
	while (i >= 0)
	{
		if (hay[i] == (char)c)
			return ((char *)&hay[i]);
		i--;
	}
	return (0);
}
