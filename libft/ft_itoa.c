/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:26:25 by azari             #+#    #+#             */
/*   Updated: 2022/10/21 12:12:13 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long c)
{
	int	i;

	i = 0;
	if (c < 0)
		i++;
	if (c == 0)
		return (1);
	while (c != 0)
	{
		c /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		cnt;
	char	*nbr;
	long	x;

	i = 0;
	x = n;
	cnt = count_digits(n);
	nbr = (char *)malloc((cnt + 1) * sizeof(char));
	if (!nbr)
		return (0);
	if (x < 0)
	{
		nbr[0] = '-';
		i = 1;
		x *= (-1);
	}
	nbr[cnt] = '\0';
	while (cnt > i)
	{
		cnt--;
		nbr[cnt] = (x % 10) + 48;
		x /= 10;
	}
	return (nbr);
}
