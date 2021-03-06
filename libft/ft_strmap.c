/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:03:14 by aguiller          #+#    #+#             */
/*   Updated: 2019/09/20 12:28:30 by aguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newmem;
	int		i;
	int		j;

	j = 0;
	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	newmem = ft_strnew(i);
	ft_strclr(newmem);
	if (newmem == NULL)
		return (NULL);
	while (s[j])
	{
		newmem[j] = f(s[j]);
		j++;
	}
	return (newmem);
}
