/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:14:15 by azari             #+#    #+#             */
/*   Updated: 2023/07/15 11:26:30 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*str;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!s1)
		str = ft_strdup("");
	else
		str = ft_strdup(s1);
	ptr = (char *)ft_malloc((ft_strlen(str) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (0);
	while (str[++i])
		ptr[i] = str[i];
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free(str);
	return (ptr);
}
