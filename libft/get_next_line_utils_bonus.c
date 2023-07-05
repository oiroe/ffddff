/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:22:31 by pboonpro          #+#    #+#             */
/*   Updated: 2023/07/05 17:28:17 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_new(const char *s, int mode)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (mode == 1 && s[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

char	*ft_strjoin_new(char *old, char *join)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	if (!old)
	{
		old = malloc(1 * sizeof(char));
		old[0] = '\0';
	}
	newstr = malloc((ft_strlen_new(old, 0)
				+ ft_strlen_new(join, 0) + 1) * sizeof(char));
	if (!newstr || !join)
		return (0);
	i = -1;
	if (old)
		while (old[++i])
			newstr[i] = old[i];
	j = 0;
	while (join[j])
		newstr[i++] = join[j++];
	newstr[i] = '\0';
	free(old);
	return (newstr);
}

char	*ft_strdup_new(char *s, int mode)
{
	char	*str;
	int		i;
	int		check;

	if (mode == 1)
		check = 2;
	else
		check = 1;
	str = malloc(sizeof(char) * (ft_strlen_new(s, mode) + check));
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		if (str[i] == '\n' && mode == 1)
		{
			i++;
			break ;
		}
		i++;
	}
	str[i] = '\0';
	return (str);
}
