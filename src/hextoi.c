/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hextoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:09:10 by pboonpro          #+#    #+#             */
/*   Updated: 2023/07/09 15:13:54 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strcount(char *str, int n)
{
	int	i;
	int	count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == n)
			count++;
		i++;
	}
	return (count);
}

long	hextoi(char *s)
{
	int		i;
	long	sum;
	long	num;

	i = 0;
	sum = 0;
	num = 0;
	while (ft_isdigit(s[i]))
		i++;
	while (s[i] == ',' || s[i] == '0' || s[i] == 'x')
		i++;
	while (s[i] && s[i] != ' ' && s[i] != '\n')
	{
		if (s[i] >= 'a' && s[i] <= 'f')
			num = s[i] - 'a' + 10;
		else if (s[i] >= 'A' && s[i] <= 'F')
			num = s[i] - 'A' + 10;
		else if (s[i] >= '0' && s[i] <= '9')
			num = s[i] - '0';
		sum = (sum * 16) + num;
		i++;
	}
	return (sum);
}
