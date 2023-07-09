/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:32:53 by pboonpro          #+#    #+#             */
/*   Updated: 2023/07/09 12:33:43 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_free(void *param)
{
	(void)param;
	exit(0);
}

int	close_keycode(int keycode, t_data *mlx)
{
	if (keycode == 53)
	{
		free_graph(mlx->graph);
		mlx->graph = NULL;
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx->img = NULL;
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		mlx->mlx_win = NULL;
		mlx_free(mlx->mlx);
		mlx->mlx = NULL;
		exit(0);
	}
	return (0);
}

int	close_bar(t_data *mlx)
{
	free_graph(mlx->graph);
	mlx->graph = NULL;
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = NULL;
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx->mlx_win = NULL;
	mlx_free(mlx->mlx);
	mlx->mlx = NULL;
	exit(0);
	return (0);
}
