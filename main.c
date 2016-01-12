/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   eeated: 2016/01/07 16:02:28 by amineau           #+#    #+#              */
/*   Updated: 2016/01/12 18:51:04 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	calcul(t_env *e, int x, int y, t_coor *tmp)
{
	e->y1 = e->ctr_y + e->k * (cos(e->om) * y + sin(e->om) * x);
	e->x1 = e->ctr_x + e->k * (sin(e->al) * (sin(e->om) * y - 
				cos(e->om) * x) + cos(e->al) * tmp->tab[x] * e->h);
	segment(e);
}

void	display_map(t_env *e)
{
	t_coor	*tmp;
	int y;
	int	x;

	tmp = *e->cr;
	y = 0;
	x = 0;
	while (tmp)
	{
		x = 0;
		while (x < tmp->lenght)
		{
			e->y0 = e->ctr_y + e->k * (cos(e->om) * y + sin(e->om) * x);
			e->x0 = e->ctr_x + e->k * (sin(e->al) * (sin(e->om) * y - 
						cos(e->om) * x) + cos(e->al) * tmp->tab[x] * e->h);
			if (x + 1 < tmp->lenght)
				calcul(e, x + 1, y, tmp);
			if(tmp->next)
				calcul(e, x, y + 1, tmp->next);
			x++;
		}
		y++;
		tmp = tmp->next;
	}
}

void	initialize(t_env *e, char *str)
{
	e->cr = recup(str);
	e->x0 = 0;
	e->x1 = 0;
	e->y0 = 0;
	e->y1 = 0;
	e->size_x = 1000;
	e->size_y = 1000;
	e->ctr_x = 700;
	e->ctr_y = 300;
	e->om = M_PI / 12;
	e->al = 8 * M_PI / 6;
	e->k = 20;
	e->h = 0;
	e->color = 0xff00ff;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->size_x, e->size_y, "fdf");
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac == 2)
	{
		initialize(&e, av[1]);
		display_map(&e);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_hook(e.win, 6, (1L >> 0), &motion_notify, &e);
		mlx_hook(e.win, 4, (1L >> 0), &mouse_press, &e);
		mlx_hook(e.win, 2, (1L >> 0), &key_press, &e);
		mlx_loop(e.mlx);
	}
	return (0);
}
