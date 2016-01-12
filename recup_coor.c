/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_coor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:17:40 by amineau           #+#    #+#             */
/*   Updated: 2016/01/12 17:58:00 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coor	*line_create(char *ptr)
{
	int 	i;
	char	**split;
	t_coor	*cr;

	if (!(cr = ft_memalloc(sizeof(t_coor))))
		return (NULL);
	cr->lenght = 0;
	split = ft_strsplit(ptr, ' ');
	while (split[cr->lenght] != NULL)
		cr->lenght++;
	if (!(cr->tab = ft_memalloc(sizeof(int) * cr->lenght)))
		return (NULL);
	i = 0;
	while (i < cr->lenght)
	{
		cr->tab[i] = ft_atoi(split[i]);
		i++;
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
