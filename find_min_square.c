/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiller <aguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:49:41 by ehell             #+#    #+#             */
/*   Updated: 2019/12/21 18:33:47 by aguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

int		check_clash(char **square, t_tetra **tmp, int x, int y, int n)
{
	int	i;
	int	*elem;
	elem = (int*)((*tmp)->data);
	/*
	 * 0 - столкновение,
	 * 1 - все верно,
	 * -1 - не проходит по высоте
	 * -2 - не проходит по ширине
	 * n - высота переданного прямоугольника
	 */
	i = 0;
	if (n - y < elem[7] + 1)
		return (-1);
	while (i < 4 && (square[elem[2 * i + 1]
		+ y][elem[2 * i] + x]) != '\n')
	{
		if ((square[elem[2 * i + 1] +
			y][elem[2 * i] + x]) != '.')
			return (0);
		i++;
	}
	if (i != 4)
		return (-2);
	return (1);
}

void	push_figure(char ***square, const int *elem, char c, int x, int y)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		(*square)[elem[2 * i + 1] + y][elem[2 * i] + x] = c;
		i++;
	}
}

void	new_square(char ***square, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free((*square)[i]);
		i++;
	}
	free(*square);
	*square = create_square(n);
}

int size(char **square)
{
	int i;

	i = 0;
	while(square[0][i])
	{
		i++;
	}
	return (i - 1);
}

int	req_function(char ***square, t_tetra **tmp,int x, int y, t_tetra **head)
{
	int	check;
	
	check = check_clash(*square, tmp, x, y, size(*square));
	if ((check == -1 || check == -2) && (*tmp)->c == 'A')
	{
		new_square(square, size(*square) + 1);
		return (req_function(square, tmp, x, y , head));
	}
	if (check == 1)
	{
		write(1,"b",1);
		push_figure(square, (int *)(*tmp)->data, (*tmp)->c, x, y);
		while (specialagent(square, tmp, x, y, head) == 0)
		{
			printf("c");
			free_letter(square, (*tmp)->c, size(*square));
			if (koord_changer(&x, &y, size(*square)) == 1)
				push_figure(square, (int *)(*tmp)->data, (*tmp)->c, x, y);
		    else if((*tmp)->c == 'A')
			{
				new_square(square, size(*square) + 1);
				return (req_function(square, head, x  , y, head));
			}
			else
				return (0);
		}
		return (1);
	}
	if (check == 0 || check == -2 || check == -1)
		return (specialagent(square, tmp,  x, y, head));
	return (1);
}


int specialagent(char ***square, t_tetra **tmp,int x, int y, t_tetra **head)
{
	int a;
	int n;
	
	n = size(*square);
	a = koord_changer(&x, &y, n);
	write(1,"\nkkord stat=",12);
	ft_putnbr(a);
	write(1,"\n",1);
	if ((*tmp)->next && a == 1)
		return (req_function(square, &(*tmp)->next, x, y , head));
	if (a == 0)
		return (0);
	write(1,"\nr",2);
	return (0);
}

int		find_min_square(char ***square, t_tetra **elem)
{
	t_tetra			**tmp;
	int		x;
	int		y;

	x = 0;
	y = 0;
	tmp = elem;
	if (*tmp)
	{
		req_function(square, tmp ,x, y, elem);
	}
	return (1);
}
