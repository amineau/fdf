/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiased.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 08:42:28 by amineau           #+#    #+#             */
/*   Updated: 2016/01/12 15:14:17 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			pixel_put(float x, float y, int color, float opacity, t_env *e)
{
	color += (int)(0xff * (1 -  opacity)) * 0x01000000;
	mlx_pixel_put(e->mlx, e->win, x, y, color);
}


static void		draw_loop_x(t_point *start, t_point *end, int color, t_env *e)
{
	float		derivative;
	t_point		current;

	current.x = (int)start->x;
	current.y = start->y;
	derivative = (end->y - start->y) / (end->x - start->x);
	while ((int)current.x <= (int)end->x)
	{
		pixel_put(current.x, current.y, color,
				current.y - (int)current.y, e);
		current.y--;
		pixel_put(current.x, current.y, color,
				1 - (current.y - (int)current.y), e);
		current.y++;
		current.x = current.x + 1;
		current.y = current.y + derivative;
	}
}

static void		draw_loop_y(t_point *start, t_point *end, int color, t_env *e)
{
	float		derivative;
	t_point		current;

	current.x = start->x;
	current.y = (int)start->y;
	derivative = (end->x - start->x) / (end->y - start->y);
	while ((int)current.y <= (int)end->y)
	{
		pixel_put(current.x, current.y, color,
				current.x - (int)current.x, e);
		current.x--;
		pixel_put(current.x, current.y, color,
				1 - (current.x - (int)current.x), e);
		current.x++;
		current.x = current.x + derivative;
		current.y = current.y + 1;
	}
}

static void		swap_points(t_point **a, t_point **b)
{
	t_point		*cache_point;

	cache_point = *a;
	*a = *b;
	*b = cache_point;
}

void			draw_line(t_env *e, int color)
{
	t_point	*a;
	t_point	*b;

	if ((a = ft_memalloc(sizeof(t_point))) 
		&& (b = ft_memalloc(sizeof(t_point))))
	{
		a->x = e->x0;
		a->y = e->y0;
		b->x = e->x1;
		b->y = e->y1;
		if (abs((int)(a->x - b->x)) <= abs((int)(a->y - b->y)))
		{
			if (b->y < a->y)
				swap_points(&a, &b);
			draw_loop_y(a, b, color, e);
		}
		else
		{
			if (b->x < a->x)
				swap_points(&a, &b);
			draw_loop_x(a, b, color, e);
		}
	}
}
