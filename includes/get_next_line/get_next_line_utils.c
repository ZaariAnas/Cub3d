/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:48:47 by azari             #+#    #+#             */
/*   Updated: 2022/10/27 12:45:18 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	ptr = (char *)malloc((ft_strlen(str) + ft_strlen(s2) + 1) * sizeof(char));
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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	sub_len;
	size_t	slen;

	i = 0;
	sub_len = ft_strlen(s + start);
	slen = ft_strlen (s);
	if (s)
	{
		if (len > sub_len)
			len = sub_len;
		sub = (char *)malloc((len + 1) * sizeof(char));
		if (!sub)
			return (0);
		while (i < len && s[start] && start <= slen)
			sub[i++] = s[start++];
		sub[i] = '\0';
		return (sub);
	}
	return (0);
}

char	*ft_strchr(const char *hay, int c)
{
	size_t	i;

	i = 0;
	while (hay[i])
	{
		if (hay[i] == (char)c)
			return ((char *)&hay[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	i;

	i = -1;
	ptr = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (str[++i])
		ptr[i] = str[i];
	ptr[i] = '\0';
	return (ptr);
}
