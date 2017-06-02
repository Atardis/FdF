/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:50:58 by gahubaul          #+#    #+#             */
/*   Updated: 2015/11/30 16:51:00 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(const char *str)
{
	int result;
	int negatif;

	result = 0;
	negatif = 0;
	while (*str == ' ' || *str == '\v' || *str == '\t' || *str == '\f'
		|| *str == '\r' || *str == '\n')
		str++;
	if (*str == '-')
	{
		negatif = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result += *str++ - '0';
		if (*str >= '0' && *str <= '9')
			result *= 10;
	}
	return (negatif ? -result : result);
}
