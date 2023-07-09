/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 23:46:18 by pboonpro          #+#    #+#             */
/*   Updated: 2023/07/09 15:33:54 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"

# define ANGLE 0.523599
# define WIN_HEIGHT 1044
# define WIN_WIDTH 1444
# define WIN_HEIGHT_CEN 522
# define WIN_WIDGHT_CEN 722
# define RED 0xFE0000
# define GREEN 0x0FFE00
# define BLUE 0xFFFFF

typedef struct s_xyz
{
	int		x;
	int		y;
	int		z;
	long	colour;
}		t_xyz;

typedef struct s_graph
{
	t_xyz	**point;
	int		row;
	int		coloumn;
	float	ratio;
}		t_graph;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_graph	*graph;
}		t_data;

typedef struct s_dda
{
	int		dx;
	int		dy;
	int		step;
	float	x_inc;
	float	y_inc;
	float	temp_x;
	float	temp_y;
}		t_dda;

long	hextoi(char *s);
void	rowcol_count(char *av, t_graph *graph);
void	my_free(char **str);
void	middle_set(t_graph *graph);
void	create_img(t_data *mlx);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_img(t_graph *graph, t_data *mlx);
void	free_graph(t_graph *graph);
int		close_keycode(int keycode, t_data *mlx);
int		close_bar(t_data *mlx);
void	index_init(char *av, t_graph *graph);
void	put_xy(t_graph *graph);
void	my_free(char **str);
void	check_file(char *av);
int		ft_strcount(char *str, int n);

#endif
