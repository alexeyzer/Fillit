/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 08:15:19 by aguiller          #+#    #+#             */
/*   Updated: 2019/11/02 20:59:39 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	if(first_check(fd) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	if (close(fd) < 0)
		return (0);
	if ((fd = checkarg(argc,argv)) == 0)
		return (0);

	return (0);
}
