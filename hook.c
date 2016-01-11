/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:21:02 by amineau           #+#    #+#             */
/*   Updated: 2016/01/11 18:28:31 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include "stdio.h"


int	key_press(int keycode, t_env *e)
{
	void	*i;
	i = e->win;
	printf("keycode = %d\n", keycode);
	if (keycode == 53)
		exit(0);
	if ((keycode >= 123 && keycode <= 126) || keycode == 69 || keycode == 78)
	{
		if (keycode == 123)
			e->omega -= M_PI / 90;
		if (keycode == 124)
			e->omega += M_PI / 90;
		if (keycode == 125)
			e->alpha -= M_PI / 90;
		if (keycode == 126)
			e->alpha += M_PI / 90;
		if (keycode == 69)
			e->h -= 0.05;
		if (keycode == 78)
			e->h += 0.05;
		mlx_clear_window(e->mlx, e->win);
		display_map(e);
	}
	return (0);
}

int	motion_notify(int x, int y, t_env *e)
{
	e->centre_x = x;
	e->centre_y = y;
	return (0);
}

int	mouse_press(int button, int x, int y, t_env *e)
{
	if (button == 1)
	{
		e->centre_x = x;
		e->centre_y = y;
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
