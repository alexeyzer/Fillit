/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:17:54 by alexzudin         #+#    #+#             */
/*   Updated: 2019/11/13 15:01:39 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetra		*tetra_new(void const *content, char a, size_t content_size)
{
	t_tetra	*new_list;

	new_list = NULL;
	new_list = (t_tetra*)malloc(sizeof(t_tetra) * 1);
	if (new_list == NULL)
		return (NULL);
	new_list->next = NULL;
	if (content == NULL)
	{
		new_list->data = NULL;
		new_list->c = a;
	}
	else
	{
		new_list->data = (void*)malloc(content_size);
		if (new_list->data == NULL)
		{
			free(new_list);
			return (NULL);
		}
		ft_memcpy(new_list->data, content, content_size);
	}
	return (new_list);
}

int reas(int fd, int count, t_tetra **head)
{
	t_tetra *now;
	int		*mass;
	char	*s;
	int		i;

	i = 0;
	if (!(mass = (*int)malloc(sizeof(int)* 8))
		return (0);
	while (i < count)
	{

	}

}

int second_check(int fd, int count)
{
	t_tetra	*head;

	head = NULL;
	reas(fd, count, &head);
	return (0);

}