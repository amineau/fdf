/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   eeated: 2016/01/07 16:02:28 by amineau           #+#    #+#              */
/*   Updated: 2016/01/10 22:05:50 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dispaly_map(t_env *e, t_coor **cr)
{
	t_coor	*tmp;
	int y;
	int	x;

	tmp = *cr;
	y = 0;
	x = 0;
	while (tmp)
	{
		while (y < tmp->lenght)
			{
				tmp->y = y * 20 * cos(60);
				tmp->x = x * 20 * sin(60);
			}
		x++;
		tmp = tmp->next;
	}
}

int		main(int ac, char **av)
{
	t_env	e;
	t_coor	**cr;
	t_coor	*tmp;

	if (ac == 2)
		cr = recup(av[1]);
	e.x0 = 0;
	e.x1 = 0;
	e.y0 = 0;
	e.y1 = 0;
	e.size_x = 1000;
	e_size_y = 1000;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.size_x, e.size_y, "Fdf");

	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
