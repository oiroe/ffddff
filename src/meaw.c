/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 12:24:02 by pboonpro          #+#    #+#             */
/*   Updated: 2023/07/09 15:49:33 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

t_graph	*graph_init(void)
{
	t_graph	*new;

	new = malloc(sizeof(t_graph));
	if (!new)
		return (NULL);
	new->coloumn = 0;
	new->point = NULL;
	new->row = 0;
	new->ratio = 0;
	return (new);
}

void	free_graph(t_graph *graph)
{
	int	i;

	i = 0;
	while (i < graph->row)
	{
		free(graph->point[i]);
		graph->point[i] = NULL;
		i++;
	}
	free(graph->point);
	graph->point = NULL;
	free(graph);
	graph = NULL;
}

int	main(int ac, char **av)
{
	t_data	mlx;

	if (ac == 2)
	{
		check_file(av[1]);
		mlx.graph = graph_init();
		rowcol_count(av[1], mlx.graph);
		index_init(av[1], mlx.graph);
		put_xy(mlx.graph);
		middle_set(mlx.graph);
		create_img(&mlx);
		draw_img(mlx.graph, &mlx);
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
		mlx_hook(mlx.mlx_win, 2, 1L << 0, close_keycode, &mlx);
		mlx_hook(mlx.mlx_win, 17, 0, close_bar, &mlx);
		mlx_loop(mlx.mlx);
	}
	else
		ft_putendl_fd("bad parameter", 2);
	return (0);
}
