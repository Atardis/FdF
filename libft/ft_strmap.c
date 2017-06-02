/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:06:49 by gahubaul          #+#    #+#             */
/*   Updated: 2015/11/30 17:06:49 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char				*ft_strmap(char const *s, char (*f)(char))
{
	char			*str;
	char			*str_new;
	unsigned int	counter;

	str = (char *)s;
	counter = 0;
	if (!(str_new = ft_memalloc(ft_strlen(str) + 1)))
		return (NULL);
	while (str[counter])
	{
		str_new[counter] = (*f)(str[counter]);
		counter++;
	}
	str_new[counter] = '\0';
	return (str_new);
}
