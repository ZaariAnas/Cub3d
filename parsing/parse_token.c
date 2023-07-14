/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:36:45 by mechane           #+#    #+#             */
/*   Updated: 2023/07/14 11:00:57 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_token(char *token)
{
	char	*r;
	int		flag;

	flag = -2;
	r = ft_strchr(token, ',');
	if (r && r != token && ft_isdigit(*(r + 1)) && ft_isdigit(*(r - 1)))
		flag++;
	r = ft_strrchr(token, ',');
	if (r && r != token && ft_isdigit(*(r + 1)) && ft_isdigit(*(r - 1)))
		flag++;
	if (!flag)
		return (1);
	return (0);
}

static void get_rgb(t_map *m)
{
	char	**tmp;
	char 	*s;
	int		i;
	
	s = NULL;
	i = -0;
	while(m->tokens[++i])
		s = ft_strjoin(s ,m->tokens[i]);
	if (!ft_check_token(s))
		ft_raise_error(RGB_ERR);
	i = -1;
	tmp = ft_split_set(s, " \t,\n");
	while(tmp[++i])
	{
		if (ft_uatoi(tmp[i]) == -1)
			ft_raise_error(RGB_ERR);
		if (!ft_strncmp(m->tokens[0], "C", ft_strlen(m->tokens[0])))
			m->tex->C += ft_uatoi(tmp[i]) << (16 - (8 * i));
		else
			m->tex->F += ft_uatoi(tmp[i]) << (16 - (8 * i));
	}
	if (i != 3)
		ft_raise_error(RGB_ERR);
}

static bool	if_valid(char *token, t_map *m)
{
	if (!token)
		return (false);
	if (!ft_strncmp(m->tokens[0], "F", ft_strlen(m->tokens[0]))
		|| !ft_strncmp(m->tokens[0], "C", ft_strlen(m->tokens[0])))
		get_rgb(m);
	else if(m->tokens[2] && m->tokens[2][0] != '\n')
		return (false);
	return (true);
}

static int	func(t_map *m, char *var, int *flag)
{
	if (!ft_strncmp(m->tokens[0], var,
		ft_strlen(m->tokens[0])) && if_valid(m->tokens[1], m))
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