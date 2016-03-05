/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:09:13 by gahubaul          #+#    #+#             */
/*   Updated: 2015/11/30 17:09:14 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	len;
	int		counter;

	str = (char*)s;
	counter = 0;
	if (str || str == '\0')
	{
		len = ft_strlen(str);
		while (counter < (int)len)
		{
			counter++;
			str++;
		}
		while (counter >= 0)
		{
			if (str[0] == (char)c)
				return (str);
			str--;
			counter--;
		}
	}
	return (NULL);
}
