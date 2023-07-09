/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:32:46 by pboonpro          #+#    #+#             */
/*   Updated: 2023/07/09 15:33:43 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	colounmcount(char **split)
{
	int	i;
	int	colounm;

	i = 0;
	colounm = 0;
	while (split[i] != NULL)
	{
		i++;
		colounm++;
	}
	return (colounm);
}

int	coloumn(char *buffer, int mode)
{
	char	**split;
	int		len;

	split = ft_split(buffer, ' ');
	len = colounmcount(split);
	my_free(split);
	if (mode == 1)
		free(buffer);
	return (len);
}

int	row_count(int row, int fd, char *buffer)
{
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break ;
		free(buffer);
		row++;
	}
	free(buffer);
	close(fd);
	return (row);
}

void	rowcol_count(char *av, t_graph *graph)
{
	int		fd;
	int		row;
	char	*buffer;

	fd = open(av, O_RDWR, 0777);
	buffer = get_next_line(fd);
	graph->coloumn = coloumn(buffer, 1);
	row = row_count(1, fd, buffer);
	graph->row = row;
}
