/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:02:28 by amineau           #+#    #+#             */
/*   Updated: 2016/01/08 13:26:49 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
void	segment(t_coor *cr, t_env *e, int couleur)
{
	int dx = cr->x0 - cr->x0;
	int dy = cr->y1 - cr->y0;
	int dp = 2 * dy - dx;
	int deltaE = 2 * dy;
	int deltaNE = 2 * (dy - dx);
	int x = cr->x0;
	int y = cr->y0;
	
	mlx_pixel_put(e->mlx, e->win, x, y, couleur);
	while (x < cr->x1)
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
		mlx_pixel_put(e->mlx, e->win, x, y, 0x00ffff);
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

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1000, 1000, "Fdf");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
