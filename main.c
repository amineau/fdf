/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   eeated: 2016/01/07 16:02:28 by amineau           #+#    #+#             */
/*   Updated: 2016/01/10 12:02:54 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
void	segment(t_env *e, int couleur)
{
	int dx;
	int dy;
	int dp;
	int deltaE;
	int deltaNE;
	int x;
	int y;
	
	x = e->x0;
	y = e->y0;
	dx = ft_abs(e->x1 - e->x0);
	dy = e->y1 - e->y0;
	dp = 2 * dy - dx;
	deltaE = 2 * dy;
	deltaNE = 2 * (dy - dx);
	mlx_pixel_put(e->mlx, e->win, x, y, couleur);
	while (x < e->x1)
	{
		if (dp <= 0)
		{
			dp += deltaE;
			x++;
		}
		else
		{
			dp += deltaNE;
			x++;
			y++;
		}
		mlx_pixel_put(e->mlx, e->win, x, y, 0x00ffff);
	}
}

int		key_hook(int keycode, t_env *e)
{
	void	*i;
	i = e->win;
	printf("keycode = %d\n", keycode);
	return (0);
}
int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 1)
	{
		if (e->x0)
		{
			e->x1 = x;
			e->y1 = y;
			segment(e, 0x00ffff);
			ft_putchar('\n');
		}
	}
	if (button == 2)
	{
		e->x0 = x;
		e->y0 = y;
	}
	printf("button = %d\nx = %d || y = %d\n", button, x, y);
	return (0);
}

int		expose_hook(t_env *e)
{
	void	*i;
	i = e->win;
	return (0);
}

int		main()
{
	t_env	e;

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
