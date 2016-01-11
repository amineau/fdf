/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   eeated: 2016/01/07 16:02:28 by amineau           #+#    #+#              */
/*   Updated: 2016/01/11 18:05:51 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
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
		x = tmp->start;
		while (x < tmp->lenght)
		{
			e->y0 = e->centre_y +  e->k * (cos(e->omega) * y + sin(e->omega) * x);
			e->x0 = e->centre_x +  e->k * (sin(e->alpha) * (sin(e->omega) * y - cos(e->omega) * x) + cos(e->alpha) * tmp->tab[x - tmp->start] * e->h);
			if (x + 1 < tmp->lenght)
			{
				e->y1 = e->centre_y +  e->k * (cos(e->omega) * y + sin(e->omega) * (x + 1));
				e->x1 = e->centre_x +  e->k * (sin(e->alpha) * (sin(e->omega) * y - cos(e->omega) * (x + 1)) + cos(e->alpha) * tmp->tab[x + 1 - tmp->start] * e->h);
				segment (e);
			}
			//printf("x0 : %d || y0 : %d || z0 : %d\n",e->x0,e->y0, tmp->tab[x - tmp->start]);
			//printf("x1 : %d || y1 : %d || z1 : %d\n",e->x1,e->y1, tmp->tab[x + 1 - tmp->start]);
			//printf("x  : %d || y  : %d || alpha : %f || omega : %f\n",x,y,e->alpha,e->omega);
			if (tmp->next)
			{
				e->y1 = e->centre_y +  e->k * (cos(e->omega) * (y + 1) + sin(e->omega) * x);
				e->x1 = e->centre_x +  e->k * (sin(e->alpha) * (sin(e->omega) * (y + 1) - cos(e->omega) * x) + cos(e->alpha) * tmp->next->tab[x - tmp->next->start] * e->h);
				segment (e);
			}
			x++;
		}
		y++;
		tmp = tmp->next;
	}
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac == 2)
	{
		e.cr = recup(av[1]);
		e.x0 = 0;
		e.x1 = 0;
		e.y0 = 0;
		e.y1 = 0;
		e.size_x = 1000;
		e.size_y = 1000;
		e.centre_x = 700;
		e.centre_y = 300;
		e.omega = M_PI / 12;
		e.alpha = 8 * M_PI / 6;
		e.k = 20;
		e.h = 0;
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, e.size_x, e.size_y, "fdf");
		display_map(&e);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_hook(e.win, 6, (1L >> 0), &motion_notify, &e);
		mlx_hook(e.win, 4, (1L >> 0), &mouse_press, &e);
		mlx_hook(e.win, 2, (1L >> 0), &key_press, &e);
		mlx_loop(e.mlx);
	}
	return (0);
}
