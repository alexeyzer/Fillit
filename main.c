/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 08:15:19 by aguiller          #+#    #+#             */
/*   Updated: 2019/10/24 20:47:49 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char **rd(int fd)
{
	char	**massive;
	char	*line;

	massive = NULL;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{

	}

	return (0);

}

int checkarg(int argc, char **argv)
{
	int fd;

	if (argc <= 1)
	{
		ft_putendl("You should give as parametr file with tetriminos");
		return (0);
	}
	if (argc > 2)
	{
	 	ft_putendl("fillit could work only with one file");
		 return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd <=0 )
	{
		ft_putendl("Could not to open the file");
		return (0);
	}
	return (fd);
}


int main(int argc, char **argv)
{
	int	fd;
	char	**massive;

	massive = NULL;
	if ((fd = checkarg(argc,argv)) == 0)
		return (0);
	

	return (0);
}
