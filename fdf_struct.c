#include "fdf.h"

int	count_carac(char *line)
{
	int index;
	int count;

	index = 0;
	count = 0;
	while (line[index])
	{
		if (line[index] == '-' || (line[index] >= '0' && line[index] <= '9'))
		{
			count++;
			while (line[index] && line[index] != ' ')
				index++;
		}
		else
			index++;
	}
	return (count);
}

t_map	**fonction_creat_struct(t_all *all)
{
	unsigned int y;
	int x;

	if (!(all->map = (t_map **)malloc(sizeof(t_map *) * all->env.max_line)))
		ft_error("Malloc has Failed for the struct Y");
	y = -1;
	while (++y < all->env.max_line)
	{
		if (!(all->map[y] = (t_map *)malloc(sizeof(t_map) * all->env.nb_caract)))
			ft_error("Malloc has Failed for the struct X");
			x = -1;
		while (++x < all->env.nb_caract)
		{
			all->map[y][x].z = 0;
			all->map[y][x].y = y;
			all->map[y][x].x = x;
			all->map[y][x].color = 0;
		}
	}
	return(all->map);
}

void		send_map_to_struct(t_all all, char *str, int y)
{
	int i;
	int x;
	int find;

	i = 0;
	find = 0;
	x = 0;
	while (str[i] && y < all.env.max_line)
	{
		while (str[i] != '-' && (str[i] < '0' || str[i] > '9'))
			i++;
		while ((str[i] == '-' || (str[i] >= '0' && str[i] <= '9')) && find == 0 &&
			x < all.env.nb_caract)
		{
			find = 1;
			all.map[y][x].z = ft_atoi_re(str, i);
			x++;
		}
		while (str[i] && (str[i] == '-' || (str[i] >= '0' && str[i] <= '9') ||
			(str[i] >= 'A' && str[i] <= 'F') || str[i] == ',' || str[i] == 'x'))
			i++;
		find = 0;
	}
}
