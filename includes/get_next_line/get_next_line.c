/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:04:16 by azari             #+#    #+#             */
/*   Updated: 2022/10/30 21:54:30 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static char	*full_line(char *adv)
{
	size_t	i;

	i = 0;
	while (adv[i] && adv[i] != '\n')
		i++;
	return (ft_substr(adv, 0, i + 1));
}

static void	new_adv(char **x)
{
	size_t	i;
	char	*nadv;
	char	*adv;

	adv = *x;
	i = 0;
	while (adv[i] && adv[i] != '\n')
		i++;
	if (adv[i] == '\n')
		i++;
	nadv = ft_substr(adv, i, ft_strlen(adv + i));
	free(adv);
	*x = nadv;
}

static char	*my_line(int fd, char *buffer, char *adv)
{
	char	*str;
	ssize_t	n;

	n = 1;
	while (n != 0 && !ft_strchr(buffer, '\n'))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[n] = '\0';
		str = ft_strjoin(adv, buffer);
		free(adv);
		adv = str;
	}
	free(buffer);
	return (adv);
}

char	*get_next_line(int fd)
{
	static char	*adv;
	char		*buffer;
	char		*rslt;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(adv);
		return (NULL);
	}
	buffer[0] = '\0';
	adv = my_line(fd, buffer, adv);
	if (!adv)
		return (NULL);
	if (!*adv)
	{
		free(adv);
		adv = 0;
		return (NULL);
	}
	rslt = full_line(adv);
	new_adv(&adv);
	return (rslt);
}
