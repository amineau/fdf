/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 16:59:39 by amineau           #+#    #+#             */
/*   Updated: 2016/01/20 17:25:02 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calcul(t_env *e, int x, int y, t_coor *tmp)
{
	e->z1 = tmp->tab[x];
	e->x1 = e->ctr_x + e->cf * (e->k * (cos(e->om) * y + sin(e->om) *
	(x - tmp->len / 2)));
	e->y1 = e->ctr_y + e->cf * (e->k * (sin(e->al) * (sin(e->om) * y -
	cos(e->om) * (x - tmp->len / 2)) + cos(e->al) * e->z1 * e->h));
	segment(e);
}

int		len_y(t_coor **cr)
{
	t_coor	*tmp;
	int		y;

	y = 0;
	tmp = *cr;
	while (tmp)
	{
		y++;
		tmp = tmp->next;
	}
	return (-y / 2);
}

void	display_map(t_env *e)
{
	t_coor	*tmp;
	int		y;
	int		x;

	tmp = *e->cr;
	y = len_y(e->cr);
	while (tmp)
	{
		x = 0;
		while (x < tmp->len)
		{
			e->z0 = tmp->tab[x];
			e->x0 = e->ctr_x + e->cf * (e->k * (cos(e->om) * y +
			sin(e->om) * (x - tmp->len / 2)));
			e->y0 = e->ctr_y + e->cf * (e->k * (sin(e->al) * (sin(e->om) * y -
			cos(e->om) * (x - tmp->len / 2)) + cos(e->al) * e->z0 * e->h));
			if (x + 1 < tmp->len)
				calcul(e, x + 1, y, tmp);
			if (tmp->next)
				calcul(e, x, y + 1, tmp->next);
			x++;
		}
		y++;
		tmp = tmp->next;
	}
}

double	find_max(t_coor **cr)
{
	t_coor	*tmp;
	int		i;
	double	max;

	tmp = *cr;
	max = 0;
	while (tmp)
	{
		i = 0;
		while (i < tmp->len)
		{
			if (max < fabs((double)tmp->tab[i]))
				max = fabs((double)tmp->tab[i]);
			i++;
		}
		tmp = tmp->next;
	}
	return (max / 10);
}
