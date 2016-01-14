/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:21:02 by amineau           #+#    #+#             */
/*   Updated: 2016/01/14 15:47:38 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include "stdio.h"


int	key_press(int keycode, t_env *e)
{
	void	*i;
	i = e->win;
	printf("keycode = %d\ncolor = %d\nh = %f\n", keycode, e->color, e->h);
	if (keycode == 53)
		exit(0);
	if ((keycode >= 123 && keycode <= 126) || keycode == 69 || keycode == 78 || (keycode >= 18 && keycode <= 19))
	{
		if (keycode == 123)
			e->om -= M_PI / 90;
		if (keycode == 124)
			e->om += M_PI / 90;
		if (keycode == 125)
			e->al -= M_PI / 90;
		if (keycode == 126)
			e->al += M_PI / 90;
		if (keycode == 69)
			e->h -= 0.05;
		if (keycode == 78)
			e->h += 0.05;
		if (keycode == 18 && e->color > 0)
			e->color -= 0x0f0f0f;
		if (keycode == 19 && e->color < 0xffffff)
			e->color += 0x0f0f0f;
		mlx_clear_window(e->mlx, e->win);
		display_map(e);
	}
	return (0);
}

int	motion_notify(int x, int y, t_env *e)
{
	e->ctr_x = x;
	e->ctr_y = y;
	return (0);
}

int	mouse_press(int button, int x, int y, t_env *e)
{
	if (button == 1)
	{
		e->ctr_x = x;
		e->ctr_y = y;
		mlx_clear_window(e->mlx, e->win);
		display_map(e);
	}
	if (button == 4)
	{
		e->k *= 1.1;
		mlx_clear_window(e->mlx, e->win);
		display_map(e);
	}
	if (button == 5)
	{
		e->k /= 1.1;
		mlx_clear_window(e->mlx, e->win);
		display_map(e);
	}
	printf("button = %d\nx = %d || y = %d\n", button, x, y);
	return (0);
}

int	expose_hook(t_env *e)
{
	void	*i;
	i = e->win;
	return (0);
}
