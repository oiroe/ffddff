/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 12:24:02 by pboonpro          #+#    #+#             */
/*   Updated: 2023/07/05 22:40:05 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_xyz
{
	int		row_at;
	int		coloumn_at;
	int		x;
	int		y;
	int		z;
	int		colour;
}		t_xyz;

typedef struct s_graph
{
	t_xyz	*point;
	int		row;
	int		coloumn;
	int		area;
}		t_graph;

/*need structure to collect the x y z and colour
in need to do that we need to make a first table(array) that contain
the index of it and then use function to put the scale into it and then
just keep the z dont do anything to them*/

void	my_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

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

void	coloumn(char *buffer, t_graph *graph)
{
	char	**split;

	split = ft_split(buffer, ' ');
	graph->coloumn = colounmcount(split);
	my_free(split);
	free(buffer);
}

void	rowcol_count(char *av, t_graph *graph)
{
	int		fd;
	int		row;
	char	*buffer;

	fd = open(av, O_RDWR, 0777);
	buffer = get_next_line(fd);
	coloumn(buffer, graph);
	row = 1;
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
	graph->row = row;
	graph->area = graph->row * graph->coloumn;
}

t_graph	*graph_init()
{
	t_graph	*new;

	new = malloc(sizeof(t_graph));
	if (!new)
		return (NULL);
	new->area = 0;
	new->coloumn = 0;
	new->point = NULL;
	new->row = 0;
	return (new);
}

void	put_index(char **split, t_graph *graph, int i)
{
	int	j;

	j = 0;
	while (j < graph->coloumn)
	{
		graph->point[j].row_at = i;
		graph->point[j].coloumn_at = j;
		graph->point[j].z = atoi(split[j]);
		j++;
	}
}

void	index_init(char *av, t_graph *graph)
{
	int		fd;
	char	*buffer;
	char	**split;
	int		i;

	graph->point = malloc(sizeof(t_xyz) * graph->area);
	if (!graph->point)
		return ;
	fd = open(av, O_RDWR, 0777);
	i = 0;
	while (i < graph->row)
	{
		buffer = get_next_line(fd);
		split = ft_split(buffer, ' ');
		free(buffer);
		put_index(split, graph, i);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_graph	*graph;

	graph = graph_init();
	if (ac == 2)
	{
		rowcol_count(av[1], graph);
		index_init(av[1], graph);
		printf("row : %d\n", graph->row);
		printf("coloumn : %d\n", graph->coloumn);
		printf("row 1: %d\n", graph->point[0].row_at);
		printf("coloumn 1: %d\n", graph->point[0].coloumn_at);
	}
	free(graph);
	return (0);
}
