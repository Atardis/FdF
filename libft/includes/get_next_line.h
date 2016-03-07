/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 16:48:22 by gahubaul          #+#    #+#             */
/*   Updated: 2016/02/13 16:48:24 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 8
# define MAX_FD 256
# define MAX_INT 2147483647

typedef struct	s_gnlstore
{
	char	*cache[MAX_FD + 1];
	char	*buff;
	int		read_bytes;
	char	*tmp;
}				t_gnlstore;

int				get_next_line(int const fd, char **line);

#endif
