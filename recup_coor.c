/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_coor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:17:40 by amineau           #+#    #+#             */
/*   Updated: 2016/01/11 15:00:39 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		space_digit(char *ptr, size_t *i)
{
	int space;
	int	j;

	space = 0;
	if (ptr[*i] == ' ')
	{
		while (ptr[*i] == ' ')
			(*i)++;
	}
	j = *i;
		while (ptr[j] != ' ')
			j++;
		while (ptr[j] && ptr[j] == ' ')
		{
			space++;
			j++;
		}
		while (ptr[j] && ptr[j] != ' ')
		{
			space++;
			j++;
		}
	return (space);
}

int		nbr_digit(int i, char *ptr)
{
	while (ptr[i] && ptr[i] != ' ')
		i++;
	while (ptr[i] && ptr[i] == ' ')
		i++;
	return (i);
}

t_coor	*line_create(char *ptr)
{
	size_t 	i;
	size_t	lenght;
	int		space;
	t_coor	*cr;

	if (!(cr = ft_memalloc(sizeof(t_coor))))
		return (NULL);
	i = 0;
	space = 0;
	cr->lenght = 0;
	lenght = ft_strlen(ptr);
	space = space_digit(ptr, &i);
	cr->start = (i + 1) / space;
	if (!(cr->tab = ft_memalloc(sizeof(int) * (lenght / space))))
		return (NULL);
	while (i < lenght)
	{
		cr->tab[cr->lenght] = ft_atoi(&ptr[i]);
		i = nbr_digit(i, ptr);;
		cr->lenght++;
	}
	cr->next = NULL;
	return (cr);
}

void	line_add(t_coor **cr, char *ptr)
{
	t_coor	*tmp;

	if (*cr)
	{
		tmp = *cr;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = line_create(ptr);
	}
	else
		*cr = line_create(ptr);
}

t_coor	**recup(char *str)
{
	int		fd;
	char	*ptr;
	t_coor	**cr;

	if (!(cr = ft_memalloc(sizeof(t_coor*))))
		return (NULL);
	if ((fd = open(str, O_RDONLY)) == -1)
		return (NULL);
	while (get_next_line(fd, &ptr) == 1)
	{
		line_add(cr, ptr);
	ft_strdel(&ptr);
	}
	close(fd);
	return (cr);
}
