/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:10:12 by gahubaul          #+#    #+#             */
/*   Updated: 2015/11/30 17:10:12 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*str_new;
	unsigned int	i;

	if (!(str_new = ft_strnew(len)) || (int)len < 0)
		return (NULL);
	str = (char *)s;
	i = 0;
	while (i < len)
	{
		str_new[i] = str[start];
		start++;
		i++;
	}
	return (str_new);
}
