/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 08:15:19 by aguiller          #+#    #+#             */
/*   Updated: 2019/11/01 19:59:23 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int checkline(char *line, int *strok, int *reshotki)
{
	if (line[0])
		(*strok)++;
	else 
	{	
		if (*strok != 4)
			return (0);
		*strok = 0;
		if (*reshotki != 4)
			return (0);
		*reshotki = 0;
	}
	return (1);
}
int lastcheck(int i, char **line)
{
	if (i != 4 && (*line)[0])
		return (0);
	ft_strdel(line);
	return (1);
}
int first_check(int fd)
{
	int		reshotki;
	char	*line;
	int		strok;
	int		i;

	line = NULL;
	reshotki = 0;
	strok = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		if (checkline(line, &strok, &reshotki) == 0)
			return (0);
		while (line[i])
		{
			if (line[i] != '#' && line[i] != '.')
				return (0);
			if(line[i] == '#')
				reshotki++;
			i++;
		}
		if (lastcheck(i, &line) == 0)
			return (0);
	}
	return (1);
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
	if(first_check(fd) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	return (0);
}
