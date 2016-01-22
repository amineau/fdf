/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_coor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:17:40 by amineau           #+#    #+#             */
/*   Updated: 2016/01/22 10:38:53 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coor	*line_create(char *ptr)
{
	int		i;
	char	**split;
	t_coor	*cr;

	if (!(cr = ft_memalloc(sizeof(t_coor))))
		return (NULL);
	cr->len = 0;
	if (ptr[0] == '\0' || ptr[0] == '\n' || !(split = ft_strsplit(ptr, ' ')))
		return (NULL);
	while (split[cr->len])
		cr->len++;
	if (!(cr->tab = ft_memalloc(sizeof(int) * cr->len)))
	{
		split_clear(split);
		return (NULL);
	}
	i = 0;
	while (i < cr->len)
	{
		cr->tab[i] = ft_atoi(split[i]);
		i++;
	}
	split_clear(split);
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
		if (!(tmp->next = line_create(ptr)))
			recup_error(5, cr);
	}
	else
	{
		if (!(*cr = line_create(ptr)))
			recup_error(5, cr);
	}
}

t_coor	**recup(char *str)
{
	int		fd;
	int		get;
	char	*ptr;
	t_coor	**cr;

	if (!(cr = ft_memalloc(sizeof(t_coor*))))
		recup_error(0, cr);
	if ((fd = open(str, O_RDONLY)) == -1)
		recup_error(1, cr);
	while ((get = get_next_line(fd, &ptr)) == 1)
	{
		line_add(cr, ptr);
		ft_strdel(&ptr);
	}
	if (get == -1 || !*cr)
		recup_error(2, cr);
	if (close(fd) == -1)
		recup_error(4, cr);
	if (test_map(cr) == -1)
		recup_error(5, cr);
	return (cr);
}
