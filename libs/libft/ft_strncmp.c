/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:39:01 by azari             #+#    #+#             */
/*   Updated: 2022/10/20 10:54:12 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *dst, const char *src, size_t n)
{
	size_t	i;

	if (n <= 0)
		return (0);
	i = 0;
	while (dst[i] == src[i] && (dst[i] || src[i]) && i < n - 1)
	i++;
	return ((unsigned char)dst[i] - (unsigned char)src[i]);
}
