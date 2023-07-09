/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_xy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:29:50 by pboonpro          #+#    #+#             */
/*   Updated: 2023/07/09 12:32:07 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ratio_set(t_graph *graph)
{
	float	i;

	i = 0;
	while (i < WIN_WIDTH / ((graph->row + graph->coloumn) * cos(ANGLE)) * 0.44)
		i++;
	graph->ratio = i * 0.44 * 3.444;
}

void	assigend_xy(t_graph *graph)
{
	int	i;
	int	j;

	i = 0;
	while (i < graph->row)
	{
		j = 0;
		while (j < graph->coloumn)
		{
			graph->point[i][j].x = j * graph->ratio;
			graph->point[i][j].y = i * graph->ratio;
			j++;
		}
		i++;
	}
}

void	apply_z(t_graph *graph)
{
	int	i;
	int	j;

	i = 0;
	while (i < graph->row)
	{
		j = 0;
		while (j < graph->coloumn)
		{
			graph->point[i][j].z *= graph->ratio * 0.14;
			j++;
		}
		i++;
	}
}

void	put_xy(t_graph *graph)
{
	ratio_set(graph);
	assigend_xy(graph);
	apply_z(graph);
}
