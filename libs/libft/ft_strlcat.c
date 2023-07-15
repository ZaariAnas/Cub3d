/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 08:52:27 by azari             #+#    #+#             */
/*   Updated: 2022/10/19 11:11:14 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	i = -1;
	slen = ft_strlen(src);
	if ((!dst && !dstsize) || !dstsize)
		return (slen);
	dlen = ft_strlen(dst);
	if (dstsize <= dlen)
		return (dstsize + slen);
	while (src[++i] && i + dlen < dstsize - 1)
		dst[i + dlen] = src[i];
	dst[i + dlen] = '\0';
	return (dlen + slen);
}
