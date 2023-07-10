/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:54:54 by azari             #+#    #+#             */
/*   Updated: 2023/07/08 17:55:10 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int is_delimiter(char c, char* delimiter_set) {
 
    int	i;

	i = 0;
	while (delimiter_set[i] != '\0') 
	{
        if (c == delimiter_set[i])
            return 1;
		i++;
    }
    return 0;
}

int	num_word(char	*delimiter_set, char *str)
{
	int count;
	int len;

	len = 0;
	count = 0;
    while (str[len] != '\0')
	{
		if (is_delimiter(str[len], delimiter_set))
        	count++;
		len++;
    }
    count++;
	return (count); 
}

static int	word_len(const char *str, char *c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !is_delimiter(str[i], c))
	{
		i++;
	}
	return (i);
}

static char	**free_all(char **tab, int j)
{
	while (j >= 0)
		free(tab[j--]);
	free(tab);
	tab = NULL;
	return (tab);
}

char	**ft_split_set(char *str, char *c)
{
	int			i;
	int			j;
	char		**tab;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	tab = malloc((num_word(c, str) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		if (!is_delimiter(str[i], c))
		{
			tab[j] = ft_substr(str, i, (word_len((str + i), c)));
			if (!tab[j])
				return (free_all(tab, j));
			i = i + word_len(str + i, c) - 1;
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}