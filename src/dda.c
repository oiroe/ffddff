/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:48:44 by pboonpro          #+#    #+#             */
/*   Updated: 2023/07/09 13:35:11 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	apply_step(int dx, int dy)
{
	if (ft_abs(dx) > ft_abs(dy))
		return (ft_abs(dx));
	else
		return (ft_abs(dy));
}

void	dda(t_xyz *xy_0, t_xyz *xy_1, t_data *mlx)
{
	t_dda	dda;
	int		i;

	dda.dx = xy_1->x - xy_0->x;
	dda.dy = xy_1->y - xy_0->y;
	dda.step = apply_step(dda.dx, dda.dy);
	dda.x_inc = dda.dx / (float)dda.step;
	dda.y_inc = dda.dy / (float)dda.step;
	dda.temp_x = xy_0->x;
	dda.temp_y = xy_0->y;
	i = 0;
	while (i < dda.step)
	{
		my_mlx_pixel_put(mlx, (int)dda.temp_x + 444, (int)dda.temp_y - 144, \
					xy_0->colour);
		dda.temp_x += dda.x_inc;
		dda.temp_y += dda.y_inc;
		i++;
	}
}

void	draw_img(t_graph *graph, t_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < graph->row)
	{
		j = 0;
		while (j < graph->coloumn)
		{
			if (i < graph->row - 1)
				dda(&graph->point[i][j], &graph->point[i + 1][j], mlx);
			if (j < graph->coloumn - 1)
				dda(&graph->point[i][j], &graph->point[i][j + 1], mlx);
			j++;
		}
		if (i < graph->row - 1 && j < graph->coloumn - 1)
			dda(&graph->point[i][j], &graph->point[i + 1][j], mlx);
		i++;
	}
}
