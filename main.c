/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 09:18:52 by amineau           #+#    #+#             */
/*   Updated: 2016/01/20 15:55:31 by amineau          ###   ########.fr       */
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

double		find_max(t_coor **cr)
{
	t_coor	*tmp;
	int		i;
	double		max;

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

void	initialize(t_env *e, char *str)
{
	t_coor	*tmp;

	e->cr = recup(str);
	tmp = *e->cr;
	e->x0 = 0;
	e->x1 = 0;
	e->y0 = 0;
	e->y1 = 0;
	e->max = find_max(e->cr);
	e->size_x = 1000;
	e->size_y = 1000;
	e->cf = 1;
	e->k = fmax(e->size_x, e->size_y) / (fmax(len_y(e->cr), tmp->len) * 1.5);
	e->ctr_x = e->size_x / 2;
	e->ctr_y = e->size_y / 2;
	e->pos_x = e->ctr_x;
	e->pos_y = e->ctr_y;
	e->om = M_PI / 4;
	e->al = 3 * M_PI / 4;
	e->h = 0;
	e->color = 200;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->size_x, e->size_y, "fdf");
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac == 2)
	{
		initialize(&e, av[1]);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_hook(e.win, 6, (1L >> 0), &motion_notify, &e);
		mlx_hook(e.win, 4, (1L >> 0), &mouse_press, &e);
		mlx_hook(e.win, 2, (1L >> 0), &key_press, &e);
		mlx_loop(e.mlx);
	}
	return (0);
}
