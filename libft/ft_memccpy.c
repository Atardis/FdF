/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:55:37 by gahubaul          #+#    #+#             */
/*   Updated: 2015/11/30 16:55:38 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	counter;
	char	*str_dst;
	char	*str_src;

	counter = 0;
	str_dst = (char *)dst;
	str_src = (char *)src;
	while (counter < n)
	{
		str_dst[counter] = str_src[counter];
		if ((char)c == str_dst[counter])
			return ((void*)&str_dst[counter + 1]);
		counter++;
	}
	return (NULL);
}
