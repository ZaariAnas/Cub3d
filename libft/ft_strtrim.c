/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:02:23 by azari             #+#    #+#             */
/*   Updated: 2022/10/21 12:56:02 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char const *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == (char)c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*t;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] != '\0' && check(set, s1[i]))
		i++;
	if (i == ft_strlen(s1))
	{
		t = (char *)malloc(sizeof(char));
		t[0] = '\0';
		return (t);
	}
	j = i;
	i = ft_strlen(s1) - 1;
	while (i >= 0 && check(set, s1[i]))
		i--;
	t = ft_substr(s1, j, i - j + 1);
	return (t);
}
