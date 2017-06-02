/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:09:47 by gahubaul          #+#    #+#             */
/*   Updated: 2015/11/30 17:09:47 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*str;

	str = (char*)s1;
	i = 0;
	if (!*s2)
		return (str);
	while (str[i])
	{
		j = 0;
		while (s2[j] == str[i + j])
		{
			if (!(s2[j + 1]))
				return (str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
