/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 09:18:52 by amineau           #+#    #+#             */
/*   Updated: 2016/01/21 11:15:46 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	else
		ft_putendl("error : invalid number of arguments");
	return (0);
}
