/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:37:29 by pboonpro          #+#    #+#             */
/*   Updated: 2023/07/09 15:54:38 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_fdf(char *av)
{
	int	len;

	len = ft_strlen(av);
	if (!ft_strnstr(av, ".fdf", len))
	{
		ft_putendl_fd("please input only .fdf file", 2);
		exit(0);
	}
	if (av[0] == '.' && av[1] == 'f' && av[2] == 'd' && av[3] == 'f')
	{
		ft_putendl_fd("can't input only '.fdf'", 2);
		exit(0);
	}
}

void	check_read(char *av)
{
	int		fd;
	char	*buffer;

	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("can't read file", 2);
		exit(0);
	}
	buffer = get_next_line(fd);
	if (buffer == NULL)
	{
		close(fd);
		free(buffer);
		ft_putendl_fd("noting to read", 2);
		exit(0);
	}
	free(buffer);
}

void	check_file(char *av)
{
	check_fdf(av);
	check_read(av);
}
