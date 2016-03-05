/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:57:00 by gahubaul          #+#    #+#             */
/*   Updated: 2015/11/30 16:57:01 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp;
	char	*tmp_dst;
	char	*tmp_src;
	size_t	counter;

	tmp_dst = (char *)dst;
	tmp_src = (char *)src;
	if (!(tmp = (char *)malloc(sizeof(tmp) * (int)len)))
		return (NULL);
	counter = 0;
	while (counter < len)
	{
		tmp[counter] = tmp_src[counter];
		counter++;
	}
	counter = 0;
	while (counter < len)
	{
		tmp_dst[counter] = tmp[counter];
		counter++;
	}
	free(tmp);
	return ((void *)dst);
}
