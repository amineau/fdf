/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:02:28 by amineau           #+#    #+#             */
/*   Updated: 2016/01/07 17:34:57 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
