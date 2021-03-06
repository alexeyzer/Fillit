/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koord_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiller <aguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:15:31 by ehell             #+#    #+#             */
/*   Updated: 2019/12/23 13:41:07 by aguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		koord_changer(int *x, int *y, int n)
{
	*x = *x + 1;
	if (*x >= n)
	{
		*y = *y + 1;
		*x = 0;
	}
	if (*y >= n)
	{
		*x = 0;
		*y = 0;
		return (0);
	}
	return (1);
}

void	free_letter(char ***square, char c, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if ((*square)[i][j] == c)
				(*square)[i][j] = '.';
			j++;
		}
		i++;
	}
}
