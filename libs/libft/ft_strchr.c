/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 08:20:53 by azari             #+#    #+#             */
/*   Updated: 2022/10/20 10:53:52 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *hay, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(hay))
	{
		if (hay[i] == (char)c)
			return ((char *)&hay[i]);
		i++;
	}
	return (0);
}
