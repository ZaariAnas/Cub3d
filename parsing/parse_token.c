/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:36:45 by mechane           #+#    #+#             */
/*   Updated: 2023/07/10 12:38:12 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	if_valid(char *token, t_map *m)
{
	char **tmp;
	int		i;
	
	if (!token)
		return (false);
	if (!ft_strncmp(token, "F", ft_strlen(token))
		|| !ft_strncmp(token, "C", ft_strlen(token)))
	{
		tmp = ft_split_set(token, " \t,");
		i = -1;
		while(tmp[++i])
		{
			if (ft_uatoi(tmp[i]) == -1)
				return (false);
			if (!ft_strncmp(token, "C", ft_strlen(token)))
				m->CC += ft_uatoi(tmp[i]) << (16 - (8 * i));
			else
				m->FF += ft_uatoi(tmp[i]) << (16 - (8 * i));
		}	
		if (i != 3)
			return (false);
	}
	
	return (true);
}

static int	func(t_map *m, char *var, int *flag)
{
	if (!ft_strncmp(m->tokens[0], var,
		ft_strlen(m->tokens[0])) && if_valid(m->tokens[1], m)
			&& !m->tokens[2])
		return ((*flag)++, 1);
	return 0;
}

int	process_tokens(t_map *m)
{
	int	i;
	
	i = 0;
	i+=func(m, "SO", &m->SO);
	i+=func(m, "WE", &m->WE);
	i+=func(m, "EA", &m->EA);
	i+=func(m, "NO", &m->NO);
	i+=func(m, "F", &m->F);
	i+=func(m, "C", &m->C);
	return (i);
}