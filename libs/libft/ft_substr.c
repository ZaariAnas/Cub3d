/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:52:47 by azari             #+#    #+#             */
/*   Updated: 2023/07/15 11:26:30 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	lens;

	i = 0;
	if (s)
	{
		lens = ft_strlen(s);
		if (len > lens)
			len = lens;
		sub = (char *)ft_malloc((len + 1) * sizeof(char));
		if (!sub)
			return (0);
		while (i < len && s[start] && start <= lens)
			sub[i++] = s[start++];
		sub[i] = '\0';
		return (sub);
	}
	return (0);
}
