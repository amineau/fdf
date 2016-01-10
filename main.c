/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   eeated: 2016/01/07 16:02:28 by amineau           #+#    #+#              */
/*   Updated: 2016/01/10 16:11:31 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env	e;
	char	**tab;
	int x;

	if (ac == 2)
	{
		tab = recup(av[1]);
		x = 0;
		while (tab[x])
			ft_putendl(tab[x]);
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
