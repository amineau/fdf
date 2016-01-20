/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:16:45 by amineau           #+#    #+#             */
/*   Updated: 2016/01/20 17:25:31 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	segment(t_env *e)
{
	t_seg	s;
	int		a;
	int		b;

	s.x = e->x0;
	s.y = e->y0;
	s.dx = ft_abs(e->x1 - e->x0);
	s.dy = ft_abs(e->y0 - e->y1);
	a = (e->x1 >= e->x0) ? 1 : -1;
	b = (e->y1 >= e->y0) ? 1 : -1;
	if (s.dx >= s.dy)
	{
		s.dp = 2 * s.dy - s.dx;
		s.deltae = 2 * s.dy;
		s.deltane = 2 * (s.dy - s.dx);
		display_segment(&s, e, a, b);
	}
	else
	{
		s.dp = 2 * s.dx - s.dy;
		s.deltae = 2 * s.dx;
		s.deltane = 2 * (s.dx - s.dy);
		display_segment(&s, e, a, b);
	}
}

void	addr_color(t_env *e, t_seg *s, double h)
{
	if (e->h > 0)
	{
		e->img_addr[s->y * e->size_line + s->x * e->bits_pix / 8] = h / 4;
		e->img_addr[s->y * e->size_line +
			s->x * e->bits_pix / 8 + 1] = e->color - h;
		e->img_addr[s->y * e->size_line +
			s->x * e->bits_pix / 8 + 2] = e->color;
	}
	else
	{
		e->img_addr[s->y * e->size_line + s->x * e->bits_pix / 8] = 0;
		e->img_addr[s->y * e->size_line +
			s->x * e->bits_pix / 8 + 1] = e->color - h;
		e->img_addr[s->y * e->size_line +
			s->x * e->bits_pix / 8 + 2] = e->color - h;
	}
}

void	couleur(t_env *e, t_seg *s)
{
	double	h;

	if (s->x >= 0 && s->x < (int)e->size_x
			&& s->y >= 0 && s->y < (int)e->size_y)
	{
		if (fabs(e->h) <= 1)
			h = fabs((e->color / 10) * e->h * (e->z0 + (e->z1 - e->z0) *
			(hypot(e->x0 - s->x, e->y0 - s->y)
			/ hypot(e->x0 - e->x1, e->y0 - e->y1)))) / e->max;
		else
			h = fabs((e->color / 10) * (e->z0 + (e->z1 - e->z0) * (hypot(e->x0
			- s->x, e->y0 - s->y) / hypot(e->x0 - e->x1, e->y0 - e->y1))))
			/ e->max;
		addr_color(e, s, h);
	}
}

void	display_segment(t_seg *s, t_env *e, int a, int b)
{
	couleur(e, s);
	while (s->x != e->x1 || s->y != e->y1)
	{
		if (s->dp <= 0)
		{
			s->dp += s->deltae;
			if (s->dx >= s->dy)
				s->x += a;
			else
				s->y += b;
		}
		else
		{
			s->dp += s->deltane;
			s->x += a;
			s->y += b;
		}
		couleur(e, s);
	}
}
