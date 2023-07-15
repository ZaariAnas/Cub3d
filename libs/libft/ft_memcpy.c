/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:06:18 by azari             #+#    #+#             */
/*   Updated: 2022/10/22 11:01:42 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_d;
	unsigned char	*ptr_s;
	size_t			i;

	i = -1;
	ptr_d = (unsigned char *)dst;
	ptr_s = (unsigned char *)src;
	if (ptr_d == ptr_s)
		return (dst);
	while (++i < n)
	(*ptr_d++) = (*ptr_s++);
	return (dst);
}
