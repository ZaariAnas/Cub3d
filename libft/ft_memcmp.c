/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:39:47 by azari             #+#    #+#             */
/*   Updated: 2022/10/14 14:23:54 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

int	ft_memcmp(const void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	while (len--)
	{
		if (*ptr_dst == *ptr_src)
		{
			ptr_dst++;
			ptr_src++;
		}
		else
			return (*ptr_dst - *ptr_src);
	}
	return (0);
}
