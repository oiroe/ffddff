/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 12:24:02 by pboonpro          #+#    #+#             */
/*   Updated: 2023/07/01 19:29:41 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*need structure to collect the x y z and colour
in need to do that we need to make a first table(array) that contain
the index of it and then use function to put the scale into it and then
just keep the z dont do anything to them*/


char	*rowcount(char *av)
{
	int		fd;
	int		row;
	char	*buffer;

	fd = open(av, O_RDWR, 0777);
	buffer = NULL;
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == '\0')
		{
			return (get_next_line);
			break ;
		}
		free(buffer);
		row++;
	}
	free(buffer);
}
