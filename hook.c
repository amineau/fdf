/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:21:02 by amineau           #+#    #+#             */
/*   Updated: 2016/01/10 14:35:46 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include "stdio.h"
int	key_hook(int keycode, t_env *e)
{
	void	*i;
	i = e->win;
	printf("keycode = %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}
int	mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 1)
	{
		if (e->x0)
		{
			e->x1 = x;
			e->y1 = y;
			segment(e);
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

int	expose_hook(t_env *e)
{
	void	*i;
	i = e->win;
	return (0);
}
