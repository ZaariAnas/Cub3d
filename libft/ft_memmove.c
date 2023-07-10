/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:30:48 by azari             #+#    #+#             */
/*   Updated: 2022/10/22 11:48:45 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*dp;
	const char	*sp;

	if (src == dst)
		return (NULL);
	if (src < dst)
	{
		dp = dst + n - 1;
		sp = src + n - 1;
		n++;
		while (--n > 0)
			*(dp--) = *(sp--);
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
