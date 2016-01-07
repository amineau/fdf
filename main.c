/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:02:28 by amineau           #+#    #+#             */
/*   Updated: 2016/01/07 18:19:17 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void TraceSegmentPointMilieu (s_coor cr, unsigned char couleur)
{
	int dx = cr.x0 - cr.x0;
	int dy = cr.y1 - cr.y0;
	int dp = 2 * dy - dx;
	int deltaE = 2 * dy;
	int deltaNE = 2 * (dy - dx);
	int x = cr.x0;
	int y = cr.y0;
		mlx_pixel_put(mlx, win, x, y, 0x00ffff);
	while (x < x1)
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
		mlx_pixel_put(mlx, win, x, y, 0x00ffff);
	}
}

int main()
{
	void	*mlx;
	void	*win;
	int		i;
	int		y;

	i = 200;
	y = 200;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "Fdf");
	while (++i < 800)
	{
		y = 200;
		while (++y < 800)
			mlx_pixel_put(mlx, win, i, y, 0x00ffff);
	}
	mlx_loop(mlx);
	return (0);
}
