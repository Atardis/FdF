/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:05:44 by gahubaul          #+#    #+#             */
/*   Updated: 2015/11/30 17:05:45 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	char			*str;
	unsigned int	counter;

	str = (char *)s;
	counter = 0;
	while (str[counter])
	{
		(*f)(&str[counter]);
		counter++;
	}
}
