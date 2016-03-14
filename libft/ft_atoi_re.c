/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_re.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 15:53:14 by gahubaul          #+#    #+#             */
/*   Updated: 2016/03/14 15:53:18 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi_re(const char *str, const int c)
{
	int result;
	int negatif;
	int i;

	result = 0;
	negatif = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || i < c)
		i++;
	if (str[i] == '-')
	{
		negatif = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result += str[i++] - '0';
		if (str[i] >= '0' && str[i] <= '9')
			result *= 10;
	}
	return (negatif ? -result : result);
}
