/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:16:45 by amineau           #+#    #+#             */
/*   Updated: 2016/01/18 21:14:41 by amineau          ###   ########.fr       */
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
		s.deltaE = 2 * s.dy;
		s.deltaNE = 2 * (s.dy - s.dx);
		display_segment(&s, e, a, b);
	}
	else
	{
		s.dp = 2 * s.dx - s.dy;
		s.deltaE = 2 * s.dx;
		s.deltaNE = 2 * (s.dx - s.dy);
		display_segment(&s, e, a, b);
	}
}

void	display_segment(t_seg *s, t_env *e, int a, int b)
{
		if (s->x >= 0 && s->x <= (int)e->size_x && s->y >= 0 && s->y <= (int)e->size_y)
			e->img_addr[s->y * e->size_line + s->x * e->bits_pix / 8] = 170;

	while (s->x != e->x1 || s->y != e->y1)
	{
		if (s->dp <= 0)
		{
			s->dp += s->deltaE;
			if (s->dx >= s->dy)
				s->x += a;
			else
				s->y += b;
		}
		else
		{
			s->dp += s->deltaNE;
			s->x += a;
			s->y += b;
		}
		if (s->x >= 0 && s->x <= (int)e->size_x && s->y >= 0 && s->y <= (int)e->size_y)
			e->img_addr[s->y * e->size_line + s->x * e->bits_pix / 8] = 170;
	}
}
