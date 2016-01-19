/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:21:02 by amineau           #+#    #+#             */
/*   Updated: 2016/01/19 20:39:58 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	image(t_env *e)
{
	if (e->img)
		mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, e->size_x, e->size_y);
	e->img_addr = mlx_get_data_addr(e->img, &e->bits_pix, &e->size_line, &e->end);
	display_map(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

int	key_press(int keycode, t_env *e)
{
	void	*i;
	i = e->win;
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		e->om -= M_PI / 90;
	if (keycode == 124)
		e->om += M_PI / 90;
	if (keycode == 125)
		e->al -= M_PI / 90;
	if (keycode == 126)
		e->al += M_PI / 90;
	if (keycode == 69)
		e->h += 0.05;
	if (keycode == 78)
		e->h -= 0.05;
	if (keycode == 18 && e->color > 0)
		e->color -= 0x0f0f0f;
	if (keycode == 19 && e->color < 0xffffff)
		e->color += 0x0f0f0f;
	image(e);
//	printf("keycode = %d\ncolor = %d\nh = %f\n", keycode, e->color, e->h);
	return (0);
}

int	motion_notify(int x, int y, t_env *e)
{
	e->pos_x = x;
	e->pos_y = y;
	return (0);
}

int	mouse_press(int button, int x, int y, t_env *e)
{
	if (button == 1)
	{
		e->ctr_x = x;
		e->ctr_y = y;
	}
	if (button == 4 || button == 6)
	{
		e->coeff *= 1.1;
		e->ctr_x = (e->ctr_x - e->pos_x) * 1.1 + e->pos_x;
		e->ctr_y = (e->ctr_y - e->pos_y) * 1.1 + e->pos_y;
	}
	if (button == 5 || button == 7)
	{
		e->coeff /= 1.1;
		e->ctr_x = (e->ctr_x - e->pos_x) / 1.1 + e->pos_x;
		e->ctr_y = (e->ctr_y - e->pos_y) / 1.1 + e->pos_y;
	}
		image(e);
//	printf("button = %d\nx = %d || y = %d\nctr_x = %d || ctr_y = %d\n", button, x, y, e->ctr_x, e->ctr_y);
	return (0);
}


int	expose_hook(t_env *e)
{
	image(e);
	return (0);
}
