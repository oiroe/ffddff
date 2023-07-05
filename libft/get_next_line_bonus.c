/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:22:20 by pboonpro          #+#    #+#             */
/*   Updated: 2023/07/05 21:07:24 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*trimming_stored(char *stored_next)
{
	int		len;
	char	*str;

	len = ft_strlen_new(stored_next, 1);
	if (!stored_next[len])
	{
		free(stored_next);
		return (0);
	}
	str = ft_strdup_new(stored_next + len + 1, 0);
	free(stored_next);
	return (str);
}

char	*trimming_return(char *str)
{
	char	*buff;

	if (!str[0])
		return (0);
	if (ft_strchr(str, '\n'))
		buff = ft_strdup_new(str, 1);
	else
		buff = ft_strdup_new(str, 0);
	return (buff);
}

char	*reading(int fd, char *to_return)
{
	char	*temp;
	int		byte_read;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (0);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, temp, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(temp);
			return (0);
		}
		temp[byte_read] = '\0';
		to_return = ft_strjoin_new(to_return, temp);
		if (ft_strchr(temp, '\n'))
			break ;
	}
	free(temp);
	return (to_return);
}

char	*get_next_line(int fd)
{
	char		*to_return;
	static char	*stored_next[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	stored_next[fd] = reading(fd, stored_next[fd]);
	if (!stored_next[fd])
		return (0);
	to_return = trimming_return(stored_next[fd]);
	stored_next[fd] = trimming_stored(stored_next[fd]);
	return (to_return);
}
