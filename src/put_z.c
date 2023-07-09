/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_z.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:31:47 by pboonpro          #+#    #+#             */
/*   Updated: 2023/07/09 15:19:41 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_error(int i, t_graph *graph)
{
	while (i >= 0)
	{
		free(graph->point[i]);
		i--;
	}
	free(graph->point);
	free(graph);
	ft_putendl_fd("Error", 2);
	exit(0);
}

void	inside(int i, int j, t_graph *graph)
{
	if (graph->point[i][j].z != 0)
		graph->point[i][j].colour = RED;
	else if (graph->point[i][j].z == 0)
		graph->point[i][j].colour = GREEN;
}

void	put_z(char **split, t_graph *graph, int i)
{
	int	j;

	graph->point[i] = malloc(sizeof(t_xyz) * graph->coloumn);
	if (!graph->point[i])
	{
		my_free(split);
		free_error(i, graph);
	}
	j = 0;
	while (j < graph->coloumn)
	{
		graph->point[i][j].z = ft_atoi(split[j]);
		if (ft_strcount(split[j], ',') == 1)
			graph->point[i][j].colour = hextoi(split[j]);
		else if (ft_strcount(split[j], ',') == 0)
			inside(i, j, graph);
		else
		{
			my_free(split);
			free_error(i, graph);
		}
		j++;
	}
}

void	index_init(char *av, t_graph *graph)
{
	int		fd;
	char	*buffer;
	char	**split;
	int		i;

	graph->point = malloc(sizeof(t_xyz) * graph->row);
	if (!graph->point)
		return ;
	fd = open(av, O_RDWR, 0777);
	i = 0;
	while (i < graph->row)
	{
		buffer = get_next_line(fd);
		split = ft_split(buffer, ' ');
		free(buffer);
		put_z(split, graph, i);
		my_free(split);
		i++;
	}
}
