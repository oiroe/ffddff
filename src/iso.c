/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:45:53 by pboonpro          #+#    #+#             */
/*   Updated: 2023/07/09 12:49:48 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_into_iso(t_graph *graph)
{
	int	i;
	int	j;
	int	temp_x;
	int	temp_y;

	i = 0;
	while (i < graph->row)
	{
		j = 0;
		while (j < graph->coloumn)
		{
			temp_x = graph->point[i][j].x;
			temp_y = graph->point[i][j].y;
			graph->point[i][j].x = (temp_x - temp_y) * cos(ANGLE);
			graph->point[i][j].y = ((temp_x + temp_y) * sin(ANGLE)) \
					- graph->point[i][j].z;
			j++;
		}
		i++;
	}
}

int	iso_point(int x, int y, int mode)
{
	if (mode == 0)
		return ((x - y) * cos(ANGLE));
	else if (mode == 1)
		return ((x + y) * sin(ANGLE));
	return (0);
}

void	loop(t_graph *graph, int real_cen_x, int real_cen_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < graph->row)
	{
		j = 0;
		while (j < graph->coloumn)
		{
			graph->point[i][j].x += real_cen_x;
			graph->point[i][j].y += real_cen_y;
			j++;
		}
		i++;
	}
}

void	set_iso_middle(t_graph *graph)
{
	int	middle_row;
	int	middle_coloumn;
	int	real_cen_x;
	int	real_cen_y;

	middle_row = (graph->row / 2) * graph->ratio;
	middle_coloumn = (graph->coloumn / 2) * graph->ratio * 0.14;
	real_cen_x = WIN_WIDGHT_CEN - iso_point(middle_row, middle_coloumn, 0);
	real_cen_y = WIN_HEIGHT_CEN - iso_point(middle_row, middle_coloumn, 1);
	loop(graph, real_cen_x, real_cen_y);
}

void	middle_set(t_graph *graph)
{
	set_iso_middle(graph);
	change_into_iso(graph);
}
