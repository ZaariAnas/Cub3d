/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:39:34 by azari             #+#    #+#             */
/*   Updated: 2022/10/21 13:42:24 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(const char *s, int c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			count++;
	}
	return (count);
}

static char	**free_str(char **str, int cnt)
{
	while (cnt > 0)
	{
		cnt--;
		free(str[cnt]);
	}
	free(str);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		cnt;
	char	**ptr;

	i = 0;
	cnt = -1;
	if (!s)
		return (NULL);
	ptr = (char **)malloc(sizeof(char *) * (count(s, c) + 1));
	if (!ptr)
		return (0);
	while (++cnt < count((char *)s, c))
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		ptr[cnt] = ft_substr(s, j, i - j);
		if (!ptr[cnt])
			return (free_str(ptr, cnt));
	}
	ptr[cnt] = 0;
	return (ptr);
}
