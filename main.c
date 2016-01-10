/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   eeated: 2016/01/07 16:02:28 by amineau           #+#    #+#              */
/*   Updated: 2016/01/10 18:55:56 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env	e;
	t_coor	**cr;
	t_coor	*tmp;

	if (ac == 2)
	{
		cr = recup(av[1]);

		tmp = *cr;
		while (tmp)
		{
			ft_putstr("tab[0] : ");
			ft_putnbrendl(tmp->tab[0]);
			ft_putstr("start : ");
			ft_putnbrendl(tmp->start);
			ft_putstr("lenght : ");
			ft_putnbrendl(tmp->lenght);
			tmp = tmp->next;
			}
	}
	e.x0 = 0;
	e.x1 = 0;
	e.y0 = 0;
	e.y1 = 0;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1000, 1000, "Fdf");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
